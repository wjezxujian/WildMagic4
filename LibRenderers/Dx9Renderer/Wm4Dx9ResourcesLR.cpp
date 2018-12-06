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
#include "Wm4Dx9Renderer.h"
#include "Wm4Dx9Resources.h"
#include "Wm4ShaderEffect.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::OnLoadVProgram (ResourceIdentifier*& rpkID,
    VertexProgram* pkVProgram)
{
    // Compile the vertex program.
    VProgramID* pkResource = WM4_NEW VProgramID;
    rpkID = pkResource;

    const char* acProgramText = pkVProgram->GetProgramText().c_str();
    int iProgramLength = (int)strlen(acProgramText);

    LPD3DXBUFFER pkCompiledShader = 0;
    LPD3DXBUFFER pkErrors = 0;
    ms_hResult = D3DXAssembleShader(acProgramText,iProgramLength,
        0,0,0,&pkCompiledShader,&pkErrors);
#ifdef _DEBUG
    if (!SUCCEEDED(ms_hResult))
    {
        char* acMsg = (char*)pkErrors->GetBufferPointer();
        int iStopHere = 0;
    }
#endif
    assert(SUCCEEDED(ms_hResult));
    assert(pkCompiledShader);

    // Create the vertex shader and binding information.
    ms_hResult = m_pqDevice->CreateVertexShader( 
        (DWORD*)(pkCompiledShader->GetBufferPointer()),&pkResource->ID);
    assert(SUCCEEDED(ms_hResult));

    // Release buffers, if necessary.
    if (pkCompiledShader)
    {
        pkCompiledShader->Release();
    }
    if (pkErrors)
    {
        pkErrors->Release();
    }
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnReleaseVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    ms_hResult = pkResource->ID->Release();
    assert(SUCCEEDED(ms_hResult));
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnLoadPProgram (ResourceIdentifier*& rpkID,
    PixelProgram* pkPProgram)
{
    // Compile the pixel program.
    PProgramID* pkResource = WM4_NEW PProgramID;
    rpkID = pkResource;

    const char* acProgramText = pkPProgram->GetProgramText().c_str();
    int iProgramLength = (int)strlen(acProgramText);

    LPD3DXBUFFER pkCompiledShader = 0;
    LPD3DXBUFFER pkErrors = 0;
    ms_hResult = D3DXAssembleShader(acProgramText,iProgramLength,
        0,0,0,&pkCompiledShader,&pkErrors);
#ifdef _DEBUG
    if (!SUCCEEDED(ms_hResult))
    {
        char* acMsg = (char*)pkErrors->GetBufferPointer();
        int iStopHere = 0;
    }
#endif
    assert(SUCCEEDED(ms_hResult));
    assert(pkCompiledShader);

    // Create the pixel shader and binding information.
    ms_hResult = m_pqDevice->CreatePixelShader( 
        (DWORD*)(pkCompiledShader->GetBufferPointer()),&pkResource->ID);
    assert(SUCCEEDED(ms_hResult));

    // Release buffers, if necessary.
    if (pkCompiledShader)
    {
        pkCompiledShader->Release();
    }
    if (pkErrors)
    {
        pkErrors->Release();
    }
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnReleasePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    ms_hResult = pkResource->ID->Release();
    assert(SUCCEEDED(ms_hResult));
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnLoadTexture (ResourceIdentifier*& rpkID,
    Texture* pkTexture)
{
    // The texture is encountered the first time.  Set up the texture unit
    // in hardware that will manage this texture.
    TextureID* pkResource = WM4_NEW TextureID;
    pkResource->TextureObject = pkTexture;
    rpkID = pkResource;

    SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
    SamplerInformation::Type eSType = pkSI->GetType();
    int iTextureUnit = pkSI->GetTextureUnit();
    bool bDepth = pkTexture->IsDepthTexture();
    bool bOffscreen = pkTexture->IsOffscreenTexture();

    // Copy the image data from system memory to video memory.
    const Image* pkImage = pkTexture->GetImage();
    assert(pkImage);

    // Windows stores BGR (lowest byte to highest byte), but Wild Magic
    // stores RGB.  The byte ordering must be reversed.
    int iQuantity, iByteQuantity;
    unsigned char* aucSrc = pkImage->GetData();
    unsigned char* aucRSrc = 0;
    int i, iSrcBase = 0, iRSrcBase = 0;
    if (pkImage->GetFormat() == Image::IT_RGB888)
    {
        iQuantity = pkImage->GetQuantity();
        iByteQuantity = 4*iQuantity;
        aucRSrc = WM4_NEW unsigned char[iByteQuantity];
        for (i = 0; i < iQuantity; i++, iSrcBase += 3, iRSrcBase += 4)
        {
            aucRSrc[iRSrcBase    ] = aucSrc[iSrcBase + 2];
            aucRSrc[iRSrcBase + 1] = aucSrc[iSrcBase + 1];
            aucRSrc[iRSrcBase + 2] = aucSrc[iSrcBase    ];
            aucRSrc[iRSrcBase + 3] = 255;
        }
    }
    else if (pkImage->GetFormat() == Image::IT_RGBA8888)
    {
        iQuantity = pkImage->GetQuantity();
        iByteQuantity = 4*iQuantity;
        aucRSrc = WM4_NEW unsigned char[iByteQuantity];
        for (i = 0; i < iQuantity; i++, iSrcBase += 4)
        {
            aucRSrc[iSrcBase    ] = aucSrc[iSrcBase + 2];
            aucRSrc[iSrcBase + 1] = aucSrc[iSrcBase + 1];
            aucRSrc[iSrcBase + 2] = aucSrc[iSrcBase    ];
            aucRSrc[iSrcBase + 3] = aucSrc[iSrcBase + 3];
        }
    }
    else if (pkImage->GetFormat() == Image::IT_CUBE_RGB888)
    {
        iQuantity = 6*pkImage->GetQuantity();
        iByteQuantity = 4*iQuantity;
        aucRSrc = WM4_NEW unsigned char[iByteQuantity];
        for (i = 0; i < iQuantity; i++, iSrcBase += 3, iRSrcBase += 4)
        {
            aucRSrc[iRSrcBase    ] = aucSrc[iSrcBase + 2];
            aucRSrc[iRSrcBase + 1] = aucSrc[iSrcBase + 1];
            aucRSrc[iRSrcBase + 2] = aucSrc[iSrcBase    ];
            aucRSrc[iRSrcBase + 3] = 255;
        }
        iByteQuantity = 4*pkImage->GetQuantity();
    }
    else if (pkImage->GetFormat() == Image::IT_CUBE_RGBA8888
    || pkImage->GetFormat() == Image::IT_RGB32
    || pkImage->GetFormat() == Image::IT_RGBA32)
    {
        // TO DO.  Handle these formats.
        assert(false);
    }

    DWORD dwUsage;
    D3DPOOL kPool;
    if (bOffscreen)
    {
        dwUsage = D3DUSAGE_RENDERTARGET | D3DUSAGE_AUTOGENMIPMAP;
        kPool = D3DPOOL_DEFAULT;
    }
    else if (bDepth)
    {
        dwUsage = D3DUSAGE_DEPTHSTENCIL;
        kPool = D3DPOOL_DEFAULT;
    }
    else
    {
        if (pkImage->GetDimension() < 3)
        {
            dwUsage = D3DUSAGE_AUTOGENMIPMAP;
        }
        else
        {
            dwUsage = 0;
        }
        kPool = D3DPOOL_MANAGED;
    }

    D3DLOCKED_RECT kLockRect;

    switch (eSType)
    {
    case SamplerInformation::SAMPLER_1D:
    {
        // DirectX appears not to have support for 1D textures, but the
        // pkImage data works anyway because it is equivalent to an n-by-1
        // 2D image.
        LPDIRECT3DTEXTURE9 pkDXTexture;
        ms_hResult = D3DXCreateTexture(m_pqDevice,pkImage->GetBound(0),1,
            0,dwUsage,D3DFMT_A8R8G8B8,kPool,&pkDXTexture);
        assert(SUCCEEDED(ms_hResult));

        ms_hResult = pkDXTexture->LockRect(0,&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRSrc,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(0);
        assert(SUCCEEDED(ms_hResult));

        pkResource->ID = pkDXTexture;
        break;
    }
    case SamplerInformation::SAMPLER_2D:
    case SamplerInformation::SAMPLER_PROJ:
    {
        LPDIRECT3DTEXTURE9 pkDXTexture;

        if (!bDepth)
        {
            ms_hResult = D3DXCreateTexture(m_pqDevice,pkImage->GetBound(0),
                pkImage->GetBound(1),0,dwUsage,D3DFMT_A8R8G8B8,kPool,
                &pkDXTexture);
            assert(SUCCEEDED(ms_hResult));

            if (!pkTexture->IsOffscreenTexture())
            {
                ms_hResult = pkDXTexture->LockRect(0,&kLockRect,0,0);
                assert(SUCCEEDED(ms_hResult));
                assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
                memcpy(kLockRect.pBits,aucRSrc,iByteQuantity);
                ms_hResult = pkDXTexture->UnlockRect(0);
                assert(SUCCEEDED(ms_hResult));
            }
        }
        else
        {
            ms_hResult = D3DXCreateTexture(m_pqDevice,pkImage->GetBound(0),
                pkImage->GetBound(1),0,dwUsage,D3DFMT_D24S8,kPool,
                &pkDXTexture);
            assert(SUCCEEDED(ms_hResult));
        }

        pkResource->ID = pkDXTexture;
        break;
    }
    case SamplerInformation::SAMPLER_CUBE:
    {
        LPDIRECT3DCUBETEXTURE9 pkDXTexture;
        ms_hResult = D3DXCreateCubeTexture(m_pqDevice,pkImage->GetBound(0),
            0,dwUsage,D3DFMT_R8G8B8,kPool,&pkDXTexture);

        LPDIRECT3DSURFACE9 pkFace;
        unsigned char* aucRFace;

        aucRFace = aucRSrc;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_POSITIVE_X,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_POSITIVE_X,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        aucRFace = aucRSrc + iByteQuantity;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_NEGATIVE_X,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_NEGATIVE_X,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        aucRFace = aucRSrc + 2*iByteQuantity;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_POSITIVE_Y,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_POSITIVE_Y,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        aucRFace = aucRSrc + 3*iByteQuantity;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_NEGATIVE_Y,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_NEGATIVE_Y,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        aucRFace = aucRSrc + 4*iByteQuantity;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_POSITIVE_Z,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_POSITIVE_Z,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        aucRFace = aucRSrc + 5*iByteQuantity;
        ms_hResult = pkDXTexture->GetCubeMapSurface(
            D3DCUBEMAP_FACE_NEGATIVE_Z,0,&pkFace);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = pkFace->LockRect(&kLockRect,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockRect.Pitch);
        memcpy(kLockRect.pBits,aucRFace,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockRect(D3DCUBEMAP_FACE_NEGATIVE_Z,0);
        assert(SUCCEEDED(ms_hResult));
        pkFace->Release();

        pkResource->ID = pkDXTexture;
        break;
    }
    case SamplerInformation::SAMPLER_3D:
    {
        LPDIRECT3DVOLUMETEXTURE9 pkDXTexture;
        ms_hResult = D3DXCreateVolumeTexture(m_pqDevice,pkImage->GetBound(0),
            pkImage->GetBound(1),pkImage->GetBound(2),0,dwUsage,
            D3DFMT_A8R8G8B8,kPool,&pkDXTexture);
        assert(SUCCEEDED(ms_hResult));

        D3DLOCKED_BOX kLockBox;
        ms_hResult = pkDXTexture->LockBox(0,&kLockBox,0,0);
        assert(SUCCEEDED(ms_hResult));
        assert(4*pkImage->GetBound(0) == (int)kLockBox.RowPitch);
        assert(4*pkImage->GetBound(0)*pkImage->GetBound(1) ==
            (int)kLockBox.SlicePitch);
        memcpy(kLockBox.pBits,aucRSrc,iByteQuantity);
        ms_hResult = pkDXTexture->UnlockBox(0);
        assert(SUCCEEDED(ms_hResult));

        pkResource->ID = pkDXTexture;
        break;
    }
    default:
        assert(false);
        break;
    }

    WM4_DELETE[] aucRSrc;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnReleaseTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    ms_hResult = pkResource->ID->Release();
    assert(SUCCEEDED(ms_hResult));
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnLoadVBuffer (ResourceIdentifier*& rpkID,
    const Attributes& rkIAttr, const Attributes& rkOAttr,
    VertexBuffer* pkVBuffer)
{
    VBufferID* pkResource = WM4_NEW VBufferID;
    rpkID = pkResource;
    pkResource->IAttr = rkIAttr;
    pkResource->OAttr = rkOAttr;

    DWORD dwFormat = D3DFVF_XYZ;
    int iVertexSize = 3*sizeof(float);

    if (rkIAttr.HasNormal())
    {
        dwFormat |= D3DFVF_NORMAL;
        iVertexSize += 3*sizeof(float);
    }

    if (rkIAttr.HasColor(0))
    {
        // DirectX always has RGBA color, stored as unsigned byte
        // channels.
        dwFormat |= D3DFVF_DIFFUSE;
        iVertexSize += sizeof(DWORD);
    }

    if (rkIAttr.HasColor(1))
    {
        // DirectX always has RGBA color, stored as unsigned byte
        // channels.
        dwFormat |= D3DFVF_SPECULAR;
        iVertexSize += sizeof(DWORD);
    }

    int iUnit;
    for (iUnit = 0; iUnit < rkIAttr.GetMaxTCoords(); iUnit++)
    {
        if (rkIAttr.HasTCoord(iUnit))
        {
            switch (rkIAttr.GetTChannels(iUnit))
            {
            case 1:
                dwFormat |= D3DFVF_TEXCOORDSIZE1(iUnit);
                iVertexSize += sizeof(float);
                break;
            case 2:
                dwFormat |= D3DFVF_TEXCOORDSIZE2(iUnit);
                iVertexSize += 2*sizeof(float);
                break;
            case 3:
                dwFormat |= D3DFVF_TEXCOORDSIZE3(iUnit);
                iVertexSize += 3*sizeof(float);
                break;
            case 4:
                dwFormat |= D3DFVF_TEXCOORDSIZE4(iUnit);
                iVertexSize += 4*sizeof(float);
                break;
            }
        }
    }

    // The index of the maximum texture unit needed determines the
    // maximum number of texture coordinate sets defined.
    dwFormat |= (rkIAttr.GetMaxTCoords() << D3DFVF_TEXCOUNT_SHIFT);

    // Copy the vertex buffer data to an array.  NOTE:  The output iChannels
    // will be smaller than vertexSize*vertexQuantity for pkVBuffer whenever
    // the vertex buffer attributes have colors.  This is because a ColorRGBA
    // value is 4 floats but is packed into 1 float.
    int iChannels;
    float* afCompatible = 0;  // allocated by BuildCompatibleArray
    pkVBuffer->BuildCompatibleArray(rkIAttr,true,iChannels,afCompatible);

    // Create the vertex buffer.
    unsigned int uiVBSize = (unsigned int)(iChannels*sizeof(float));
    LPDIRECT3DVERTEXBUFFER9 pqVBuffer;
    ms_hResult = m_pqDevice->CreateVertexBuffer(uiVBSize,D3DUSAGE_WRITEONLY,
        dwFormat,D3DPOOL_MANAGED,&pqVBuffer,0);
    assert(SUCCEEDED(ms_hResult));

    // Copy the vertex buffer data from system memory to video memory.
    float* afVBData;
    ms_hResult = pqVBuffer->Lock(0,uiVBSize,(void**)(&afVBData),0);
    assert(SUCCEEDED(ms_hResult));
    System::Memcpy(afVBData,uiVBSize,afCompatible,uiVBSize);
    ms_hResult = pqVBuffer->Unlock();
    assert(SUCCEEDED(ms_hResult));

    WM4_DELETE[] afCompatible;

    // Generate the binding information and save it.
    pkResource->ID = pqVBuffer;
    pkResource->VertexSize = iVertexSize;
    pkResource->Format = dwFormat;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnReleaseVBuffer (ResourceIdentifier* pkID)
{
    VBufferID* pkResource = (VBufferID*)pkID;
    pkResource->ID->Release();
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnLoadIBuffer (ResourceIdentifier*& rpkID,
    IndexBuffer* pkIBuffer)
{
    // The index buffer is encountered the first time.
    IBufferID* pkResource = WM4_NEW IBufferID;
    rpkID = pkResource;

    int iIQuantity = pkIBuffer->GetIndexQuantity();
    int* aiIndex = pkIBuffer->GetData();
    unsigned int uiIBSize = (unsigned int)(iIQuantity*sizeof(int));

    // Create the index buffer.
    LPDIRECT3DINDEXBUFFER9 pqIBuffer;
    ms_hResult = m_pqDevice->CreateIndexBuffer(uiIBSize,D3DUSAGE_WRITEONLY,
        D3DFMT_INDEX32,D3DPOOL_MANAGED,&pqIBuffer,0);
    assert(SUCCEEDED(ms_hResult));

    // Copy the index buffer data from system memory to video memory.
    char* pcIndices;
    ms_hResult = pqIBuffer->Lock(0,uiIBSize,(void**)(&pcIndices),0);
    assert(SUCCEEDED(ms_hResult));

    System::Memcpy(pcIndices,uiIBSize,aiIndex,iIQuantity*sizeof(int));

    ms_hResult = pqIBuffer->Unlock();
    assert(SUCCEEDED(ms_hResult));

    // Generate the binding information and save it.
    pkResource->ID = pqIBuffer;
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnReleaseIBuffer (ResourceIdentifier* pkID)
{
    IBufferID* pkResource = (IBufferID*)pkID;
    pkResource->ID->Release();
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
