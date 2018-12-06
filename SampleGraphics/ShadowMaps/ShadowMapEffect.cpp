// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ShadowMapEffect.h"
#include "Wm4BitHacks.h"
#include "Wm4Geometry.h"
#include "Wm4Images.h"
#include "Wm4VisibleSet.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,ShadowMapEffect,Effect);
WM4_IMPLEMENT_STREAM(ShadowMapEffect);

//----------------------------------------------------------------------------
ShadowMapEffect::ShadowMapEffect (Camera* pkProjector,
    const std::string& rkProjectionImage, int iDepthWidth, int iDepthHeight,
    float fDepthBias)
    :
    m_spkProjector(pkProjector)
{
    // TO DO.  If the width is invalid, find largest power of two smaller than
    // the invalid value.
    assert(IsPowerOfTwo((unsigned int)iDepthWidth)
        && IsPowerOfTwo((unsigned int)iDepthHeight));

    // Create the depth effect.
    VertexShader* pkVShader = WM4_NEW VertexShader("ProjectedDepth");
    PixelShader* pkPShader = WM4_NEW PixelShader("ProjectedDepth");
    m_spkDepthEffect = WM4_NEW ShaderEffect(1);
    m_spkDepthEffect->SetVShader(0,pkVShader);
    m_spkDepthEffect->SetPShader(0,pkPShader);
    m_pkDepthBuffer = 0;  // Creation deferred until the first Draw call.

    // Create an image for the depth texture.
    int iQuantity = 4*iDepthWidth*iDepthHeight;
    unsigned char* aucData = WM4_NEW unsigned char[iQuantity];
    m_spkDepthImage = WM4_NEW Image(Image::IT_RGBA8888,iDepthWidth,
        iDepthHeight,aucData,"DepthImage");

    // Create the shadow map effect.
    pkVShader = WM4_NEW VertexShader("ShadowMap");
    pkPShader = WM4_NEW PixelShader("ShadowMap");
    pkPShader->SetTextureQuantity(2);
    pkPShader->SetImageName(0,rkProjectionImage);
    pkPShader->SetImageName(1,"DepthImage");
    Texture* pkProjectedTexture = pkPShader->GetTexture(0);
    pkProjectedTexture->SetFilterType(Texture::LINEAR);
    m_spkShadowEffect = WM4_NEW ShaderEffect(1);
    m_spkShadowEffect->SetVShader(0,pkVShader);
    m_spkShadowEffect->SetPShader(0,pkPShader);
    AlphaState* pkAState = m_spkShadowEffect->GetBlending(0);
    pkAState->SrcBlend = AlphaState::SBF_DST_COLOR;
    pkAState->DstBlend = AlphaState::DBF_ZERO;

    m_afDepthBias[0] = fDepthBias;
}
//----------------------------------------------------------------------------
ShadowMapEffect::ShadowMapEffect ()
{
    m_pkDepthBuffer = 0;
    m_pkDepthTexture = 0;
}
//----------------------------------------------------------------------------
ShadowMapEffect::~ShadowMapEffect ()
{
    WM4_DELETE m_pkDepthBuffer;
}
//----------------------------------------------------------------------------
void ShadowMapEffect::Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
    int iMin, int iMax, VisibleObject* akVisible)
{
    // Deferred creation of the depth buffer since it needs a renderer to
    // exist.  This is necessary if the shadow map is being streamed from
    // disk before the renderer has been created.
    if (!m_pkDepthBuffer)
    {
        m_pkDepthTexture = m_spkShadowEffect->GetPShader(0)->GetTexture(1);
        m_pkDepthTexture->SetFilterType(Texture::LINEAR);
        m_pkDepthTexture->SetOffscreenTexture(true);
        pkRenderer->LoadResources(m_spkShadowEffect);

        PixelProgram* pkProgram = m_spkShadowEffect->GetPProgram(0);
        pkProgram->GetUC("DepthBias")->SetDataSource(m_afDepthBias);

        m_pkDepthBuffer = FrameBuffer::Create(pkRenderer->GetFormatType(),
            pkRenderer->GetDepthType(),pkRenderer->GetStencilType(),
            pkRenderer->GetBufferingType(),pkRenderer->GetMultisamplingType(),
            pkRenderer,m_pkDepthTexture);
        assert(m_pkDepthBuffer);
    }

    // Draw to the depth texture from the projector's perspective.  The
    // projector camera must be set before the Enable() call so that its
    // settings are used inside the Enable() call.
    Camera* pkSaveCamera = pkRenderer->GetCamera();
    pkRenderer->SetCamera(m_spkProjector);
    m_pkDepthBuffer->Enable();
    pkRenderer->ClearBuffers();

    // Another attempt to deal with the depth bias problems.
    // CullState* pkCState = pkRenderer->GetCullState();
    // pkCState->CullFace = CullState::CT_FRONT;
    // pkRenderer->SetCullState(pkCState);

    int i;
    for (i = iMin; i <= iMax; i++)
    {
        if (akVisible[i].IsDrawable())
        {
            Geometry* pkGeom = (Geometry*)akVisible[i].Object;
            pkGeom->AttachEffect(m_spkDepthEffect);
            pkGeom->SetStartEffect(pkGeom->GetEffectQuantity()-1);
            pkRenderer->Draw(pkGeom);
            pkGeom->SetStartEffect(0);
            pkGeom->DetachEffect(m_spkDepthEffect);
        }
    }

    // Another attempt to deal with the depth bias problems.
    // pkCState->CullFace = CullState::CT_BACK;
    // pkRenderer->SetCullState(pkCState);

#if 0
    // BEGIN TEST
    m_pkDepthBuffer->CopyToTexture(true);
    Image* pkDTImage = m_pkDepthTexture->GetImage();
    ImageRGB82D kImage(pkDTImage->GetBound(0),pkDTImage->GetBound(1));
    unsigned char* pucData = pkDTImage->GetData();
    for (int i = 0; i < pkDTImage->GetQuantity(); i++)
    {
        unsigned char ucR = *pucData++;
        unsigned char ucG = *pucData++;
        unsigned char ucB = *pucData++;
        pucData++;
        kImage[i] = GetColor24(ucR,ucG,ucB);
    }
    kImage.Save("dimage.im");
    // END TEST
#endif

    // We are finished drawing to the depth buffer.  The old camera must be
    // set before the Disable() call so that its settings are used inside the
    // Disable() call.
    pkRenderer->SetCamera(pkSaveCamera);
    m_pkDepthBuffer->Disable();

    // Draw the scene normally, but blend in the projection image and shadow.
    pkRenderer->SetProjector(m_spkProjector);
    pkRenderer->ClearBuffers();
    for (i = iMin; i <= iMax; i++)
    {
        if (akVisible[i].IsDrawable())
        {
            Geometry* pkGeom = (Geometry*)akVisible[i].Object;
            pkGeom->AttachEffect(m_spkShadowEffect);
            pkRenderer->Draw(pkGeom);
            pkGeom->DetachEffect(m_spkShadowEffect);
        }
    }
    pkRenderer->SetProjector(0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* ShadowMapEffect::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Effect::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkProjector)
    {
        pkFound = m_spkProjector->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkDepthEffect)
    {
        pkFound = m_spkDepthEffect->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkDepthImage)
    {
        pkFound = m_spkDepthImage->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkShadowEffect)
    {
        pkFound = m_spkShadowEffect->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void ShadowMapEffect::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Effect::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkProjector)
    {
        m_spkProjector->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkDepthEffect)
    {
        m_spkDepthEffect->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkDepthImage)
    {
        m_spkDepthImage->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkShadowEffect)
    {
        m_spkShadowEffect->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* ShadowMapEffect::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Effect::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkProjector)
    {
        pkFound = m_spkProjector->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkDepthEffect)
    {
        pkFound = m_spkDepthEffect->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkDepthImage)
    {
        pkFound = m_spkDepthImage->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkShadowEffect)
    {
        pkFound = m_spkShadowEffect->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void ShadowMapEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Effect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afDepthBias[0]);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkProjector
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkDepthEffect
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkDepthImage
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkShadowEffect
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(ShadowMapEffect);
}
//----------------------------------------------------------------------------
void ShadowMapEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Effect::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkProjector = (Camera*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkDepthEffect = (ShaderEffect*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkDepthImage = (Image*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkShadowEffect = (ShaderEffect*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool ShadowMapEffect::Register (Stream& rkStream) const
{
    if (!Effect::Register(rkStream))
    {
        return false;
    }

    if (m_spkProjector)
    {
        m_spkProjector->Register(rkStream);
    }

    if (m_spkDepthEffect)
    {
        m_spkDepthEffect->Register(rkStream);
    }

    if (m_spkDepthImage)
    {
        m_spkDepthImage->Register(rkStream);
    }

    if (m_spkShadowEffect)
    {
        m_spkShadowEffect->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void ShadowMapEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Effect::Save(rkStream);

    // native data
    rkStream.Write(m_afDepthBias[0]);

    // link data
    rkStream.Write(m_spkProjector);
    rkStream.Write(m_spkDepthEffect);
    rkStream.Write(m_spkDepthImage);
    rkStream.Write(m_spkShadowEffect);

    WM4_END_DEBUG_STREAM_SAVE(ShadowMapEffect);
}
//----------------------------------------------------------------------------
int ShadowMapEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Effect::GetDiskUsed(rkVersion) +
        sizeof(m_afDepthBias[0]) +
        sizeof(m_spkProjector) +
        sizeof(m_spkDepthEffect) +
        sizeof(m_spkDepthImage) +
        sizeof(m_spkShadowEffect);
}
//----------------------------------------------------------------------------
StringTree* ShadowMapEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("depth bias =",m_afDepthBias[0]));

    // children
    pkTree->Append(Effect::SaveStrings());

    if (m_spkProjector)
    {
        pkTree->Append(m_spkProjector->SaveStrings());
    }

    if (m_spkDepthEffect)
    {
        pkTree->Append(m_spkDepthEffect->SaveStrings());
    }

    if (m_spkDepthImage)
    {
        pkTree->Append(m_spkDepthImage->SaveStrings());
    }

    if (m_spkShadowEffect)
    {
        pkTree->Append(m_spkShadowEffect->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
