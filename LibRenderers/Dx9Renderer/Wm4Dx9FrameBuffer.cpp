// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4Dx9RendererPCH.h"
#include "Wm4Dx9Resources.h"
#include "Wm4Dx9FrameBuffer.h"
#include "Wm4Camera.h"
using namespace Wm4;

WM4_IMPLEMENT_INITIALIZE(Dx9FrameBuffer);

//----------------------------------------------------------------------------
void Dx9FrameBuffer::Initialize ()
{
    ms_aoCreate[Renderer::DIRECTX] = &Dx9FrameBuffer::Create;
    ms_aoDestroy[Renderer::DIRECTX] = &Dx9FrameBuffer::Destroy;
}
//----------------------------------------------------------------------------
FrameBuffer* Dx9FrameBuffer::Create (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
{
    if (pkRenderer && pkTarget)
    {
        Dx9FrameBuffer* pkBuffer = WM4_NEW Dx9FrameBuffer(eFormat,
            eDepth,eStencil,eBuffering,eMultisampling,pkRenderer,pkTarget);

        if (pkBuffer->InitializeBuffer())
        {
            return pkBuffer;
        }

        WM4_DELETE pkBuffer;
    }
    return 0;
}
//----------------------------------------------------------------------------
void Dx9FrameBuffer::Destroy (FrameBuffer* pkBuffer)
{
    ((Dx9FrameBuffer*)pkBuffer)->TerminateBuffer();
    WM4_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
Dx9FrameBuffer::Dx9FrameBuffer (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
    :
    FrameBuffer(eFormat,eDepth,eStencil,eBuffering,eMultisampling,pkRenderer,
        pkTarget)
{
    m_pkTargetID = 0;
    m_pkRenderToTexture = 0;
    m_pkTextureSurface = 0;
    m_pkSaveTextureSurface = 0;
    m_pkDepthStencilSurface = 0;
    m_pkSaveDepthStencilSurface = 0;

    m_pkCopyTexture = 0;
    m_pkCopySurface = 0;
}
//----------------------------------------------------------------------------
Dx9FrameBuffer::~Dx9FrameBuffer ()
{
}
//----------------------------------------------------------------------------
bool Dx9FrameBuffer::InitializeBuffer ()
{
    Image* pkImage = m_pkTarget->GetImage();
    if (pkImage->IsCubeImage())
    {
        // TO DO.  Cube map images not supported yet, but they should be.
        return false;
    }

    ResourceIdentifier* pkID = m_pkTarget->GetIdentifier(m_pkRenderer);
    assert(pkID);
    TextureID* pkResource = (TextureID*)pkID;
    m_pkTargetID = (IDirect3DTexture9*)pkResource->ID;

    Dx9Renderer* pkRenderer = (Dx9Renderer*)m_pkRenderer;
    HRESULT hResult;

    if (m_pkTarget->IsDepthTexture())
    {
        hResult = m_pkTargetID->GetSurfaceLevel(0,&m_pkDepthStencilSurface);
        if (!SUCCEEDED(hResult))
        {
            m_pkTextureSurface = 0;
            return false;
        }
    }
    else
    {
        hResult = m_pkTargetID->GetSurfaceLevel(0,&m_pkTextureSurface);
        if (!SUCCEEDED(hResult))
        {
            m_pkTextureSurface = 0;
            return false;
        }

        D3DSURFACE_DESC kDesc;
        hResult = m_pkTextureSurface->GetDesc(&kDesc);
        if (!SUCCEEDED(hResult))
        {
            m_pkTextureSurface->Release();
            m_pkTextureSurface = 0;
            return false;
        }

        hResult = D3DXCreateRenderToSurface(pkRenderer->m_pqDevice,
            kDesc.Width,kDesc.Height,kDesc.Format,TRUE,D3DFMT_D24S8,
            &m_pkRenderToTexture);
        if (!SUCCEEDED(hResult))
        {
            m_pkTextureSurface->Release();
            m_pkTextureSurface = 0;
            m_pkRenderToTexture = 0;
            return false;
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void Dx9FrameBuffer::TerminateBuffer ()
{
    if (m_pkTarget->IsDepthTexture())
    {
        if (m_pkDepthStencilSurface)
        {
            m_pkDepthStencilSurface->Release();
            m_pkDepthStencilSurface = 0;
        }
    }
    else
    {
        if (m_pkTextureSurface)
        {
            m_pkTextureSurface->Release();
            m_pkTextureSurface = 0;
        }

        if (m_pkRenderToTexture)
        {
            m_pkRenderToTexture->Release();
            m_pkRenderToTexture = 0;
        }
    }

    if (m_pkCopySurface)
    {
        m_pkCopySurface->Release();
        m_pkCopySurface = 0;
    }

    if (m_pkCopyTexture)
    {
        m_pkCopyTexture->Release();
        m_pkCopyTexture = 0;
    }
}
//----------------------------------------------------------------------------
void Dx9FrameBuffer::Enable ()
{
    Dx9Renderer* pkRenderer = (Dx9Renderer*)m_pkRenderer;
    HRESULT hResult;

    if (m_pkTarget->IsDepthTexture())
    {
        hResult = pkRenderer->m_pqDevice->GetDepthStencilSurface(
            &m_pkSaveDepthStencilSurface);
        assert(SUCCEEDED(hResult));

        hResult = pkRenderer->m_pqDevice->SetDepthStencilSurface(
            m_pkDepthStencilSurface);
        assert(SUCCEEDED(hResult));
    }
    else
    {
        if (pkRenderer->m_bBeginSceneActive)
        {
            hResult = pkRenderer->m_pqDevice->GetRenderTarget(0,
                &m_pkSaveTextureSurface);
            assert(SUCCEEDED(hResult));

            hResult = pkRenderer->m_pqDevice->SetRenderTarget(0,
                m_pkTextureSurface);
            assert(SUCCEEDED(hResult));
        }
        else
        {
            hResult = m_pkRenderToTexture->BeginScene(m_pkTextureSurface,0);
            assert(SUCCEEDED(hResult));
        }
    }

    pkRenderer->OnFrustumChange();

    // The offscreen texture is stored in such a way that the following
    // adjustment is necessary to have the texture show up correctly on
    // the rendered geometry.  The handedness is changed by negating in the
    // up direction.  This additionally requires reversing the culling mode.
    const Vector3f& rkEye = pkRenderer->m_pkCamera->GetLocation();
    Vector3f rkRVector = pkRenderer->m_pkCamera->GetRVector();
    Vector3f rkUVector = -pkRenderer->m_pkCamera->GetUVector();
    Vector3f rkDVector = pkRenderer->m_pkCamera->GetDVector();
    pkRenderer->m_kViewMatrix[0][0] = rkRVector[0];
    pkRenderer->m_kViewMatrix[0][1] = rkUVector[0];
    pkRenderer->m_kViewMatrix[0][2] = rkDVector[0];
    pkRenderer->m_kViewMatrix[0][3] = 0.0f;
    pkRenderer->m_kViewMatrix[1][0] = rkRVector[1];
    pkRenderer->m_kViewMatrix[1][1] = rkUVector[1];
    pkRenderer->m_kViewMatrix[1][2] = rkDVector[1];
    pkRenderer->m_kViewMatrix[1][3] = 0.0f;
    pkRenderer->m_kViewMatrix[2][0] = rkRVector[2];
    pkRenderer->m_kViewMatrix[2][1] = rkUVector[2];
    pkRenderer->m_kViewMatrix[2][2] = rkDVector[2];
    pkRenderer->m_kViewMatrix[2][3] = 0.0f;
    pkRenderer->m_kViewMatrix[3][0] = -rkRVector.Dot(rkEye);
    pkRenderer->m_kViewMatrix[3][1] = -rkUVector.Dot(rkEye);
    pkRenderer->m_kViewMatrix[3][2] = -rkDVector.Dot(rkEye);
    pkRenderer->m_kViewMatrix[3][3] = 1.0f;
    hResult = pkRenderer->m_pqDevice->SetTransform(D3DTS_VIEW,
        (D3DXMATRIX*)(float*)pkRenderer->m_kViewMatrix); 
    assert(SUCCEEDED(hResult));

    pkRenderer->m_bReverseCullFace = !pkRenderer->m_bReverseCullFace;
    CullState* pkCState = pkRenderer->GetCullState();
    pkRenderer->SetCullState(pkCState);

    Image* pkImage = m_pkTarget->GetImage();
    D3DVIEWPORT9 kViewport;
    kViewport.X = 0;
    kViewport.Y = 0;
    kViewport.Width = (DWORD)pkImage->GetBound(0);
    kViewport.Height = (DWORD)pkImage->GetBound(1);
    kViewport.MinZ = 0.0f;
    kViewport.MaxZ = 1.0f;
    hResult = pkRenderer->m_pqDevice->SetViewport(&kViewport);
    assert(SUCCEEDED(hResult));
}
//----------------------------------------------------------------------------
void Dx9FrameBuffer::Disable ()
{
    Dx9Renderer* pkRenderer = (Dx9Renderer*)m_pkRenderer;
    HRESULT hResult;

    if (m_pkTarget->IsDepthTexture())
    {
        hResult = pkRenderer->m_pqDevice->SetDepthStencilSurface(
            m_pkSaveDepthStencilSurface);
        assert(SUCCEEDED(hResult));
        m_pkSaveDepthStencilSurface->Release();
    }
    else
    {
        if (pkRenderer->m_bBeginSceneActive)
        {
            hResult = pkRenderer->m_pqDevice->SetRenderTarget(0,
                m_pkSaveTextureSurface);
            assert(SUCCEEDED(hResult));
            m_pkSaveTextureSurface->Release();
        }
        else
        {
            hResult = m_pkRenderToTexture->EndScene(0);
            assert(SUCCEEDED(hResult));
        }
    }

    pkRenderer->OnViewportChange();
    pkRenderer->OnFrustumChange();
    pkRenderer->OnFrameChange();

    pkRenderer->m_bReverseCullFace = !pkRenderer->m_bReverseCullFace;
    CullState* pkCState = pkRenderer->GetCullState();
    pkRenderer->SetCullState(pkCState);
}
//----------------------------------------------------------------------------
void Dx9FrameBuffer::CopyToTexture (bool bFillImage)
{
    // TO DO.  Only the software renderer actually does something when
    // bFillImage is 'false'.  If that is not necessary, then CopyToTexture
    // should have no parameters and should be called only when you want to
    // copy the VRAM copy into system memory.

    // TO DO:  I tried a lot of approaches to retrieving the depth texture
    // values, but they all failed.
    if (bFillImage && !m_pkTarget->IsDepthTexture())
    {
        Image* pkImage = m_pkTarget->GetImage();
        unsigned char* aucDst = pkImage->GetData();
        int iQuantity = pkImage->GetQuantity();
        int iByteQuantity = 4*iQuantity;
        unsigned char* aucRDst = WM4_NEW unsigned char[iByteQuantity];
        int i, iDstBase = 0, iRDstBase = 0;

        Dx9Renderer* pkRenderer = (Dx9Renderer*)m_pkRenderer;
        HRESULT hResult;

        // Allocate the system-memory texture on demand.
        if (!m_pkCopyTexture)
        {
            hResult = D3DXCreateTexture(pkRenderer->m_pqDevice,
                pkImage->GetBound(0),pkImage->GetBound(1),0,
                0,D3DFMT_A8R8G8B8,D3DPOOL_SYSTEMMEM,
                &m_pkCopyTexture);
            assert(SUCCEEDED(hResult));

            hResult = m_pkCopyTexture->GetSurfaceLevel(0,
                &m_pkCopySurface);
            assert(SUCCEEDED(hResult));

            hResult = pkRenderer->m_pqDevice->GetRenderTargetData(
                m_pkTextureSurface,m_pkCopySurface);
            assert(SUCCEEDED(hResult));
        }

        D3DLOCKED_RECT kLockRect;
        hResult = m_pkCopySurface->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(hResult));
        memcpy(aucRDst,kLockRect.pBits,iByteQuantity);
        hResult = m_pkCopySurface->UnlockRect();
        assert(SUCCEEDED(hResult));

        switch (m_eFormat)
        {
        case FT_FORMAT_RGB:
            for (i = 0; i < iQuantity; i++, iDstBase += 3, iRDstBase += 4)
            {
                aucDst[iDstBase    ] = aucRDst[iRDstBase + 2];
                aucDst[iDstBase + 1] = aucRDst[iRDstBase + 1];
                aucDst[iDstBase + 2] = aucRDst[iRDstBase    ];
            }
            break;

        case FT_FORMAT_RGBA:
            for (i = 0; i < iQuantity; i++, iDstBase += 4, iRDstBase += 4)
            {
                aucDst[iDstBase    ] = aucRDst[iRDstBase + 2];
                aucDst[iDstBase + 1] = aucRDst[iRDstBase + 1];
                aucDst[iDstBase + 2] = aucRDst[iRDstBase    ];
                aucDst[iDstBase + 3] = aucRDst[iRDstBase + 3];
            }
            break;

        case FT_FORMAT_DEPTH:
            memcpy(aucDst,aucRDst,iByteQuantity);
            break;

        default:
            assert(false);
            break;
        }

        WM4_DELETE[] aucRDst;
    }
}
//----------------------------------------------------------------------------
