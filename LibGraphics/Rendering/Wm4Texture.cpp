// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4Texture.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Texture,Object);
WM4_IMPLEMENT_STREAM(Texture);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Texture,Object);

const char* Texture::ms_aacFilterType[MAX_FILTER_TYPES] =
{
    "NEAREST",
    "LINEAR",
    "NEAREST_NEAREST",
    "NEAREST_LINEAR",
    "LINEAR_NEAREST",
    "LINEAR_LINEAR"
};

const char* Texture::ms_aacWrapType[MAX_WRAP_TYPES] =
{
    "CLAMP",
    "REPEAT",
    "MIRRORED_REPEAT",
    "CLAMP_BORDER",
    "CLAMP_EDGE"
};

const char* Texture::ms_aacDepthCompare[DC_QUANTITY] =
{
    "DC_NEVER",
    "DC_LESS",
    "DC_EQUAL",
    "DC_LEQUAL",
    "DC_GREATER",
    "DC_NOTEQUAL",
    "DC_GEQUAL",
    "DC_ALWAYS"
};

//----------------------------------------------------------------------------
Texture::Texture (Image* pkImage, SamplerInformation* pkSInfo, bool bSIOwner)
    :
    m_spkImage(pkImage),
    m_kBorderColor(ColorRGBA::BLACK)
{
    m_pkSamplerInformation = pkSInfo;
    m_eFType = LINEAR;
    m_aeWType[0] = CLAMP_EDGE;
    m_aeWType[1] = CLAMP_EDGE;
    m_aeWType[2] = CLAMP_EDGE;
    m_eCompare = DC_QUANTITY;
    m_bOffscreenTexture = false;
    m_bSIOwner = bSIOwner;
}
//----------------------------------------------------------------------------
Texture::Texture (Image* pkDepthImage, DepthCompare eCompare)
    :
    m_spkImage(pkDepthImage),
    m_kBorderColor(ColorRGBA::BLACK)
{
    m_eFType = LINEAR;
    m_aeWType[0] = CLAMP_EDGE;
    m_aeWType[1] = CLAMP_EDGE;
    m_aeWType[2] = CLAMP_EDGE;
    m_eCompare = eCompare;

    m_pkSamplerInformation = WM4_NEW SamplerInformation(
        pkDepthImage->GetName(),SamplerInformation::SAMPLER_2D,0);

    m_bOffscreenTexture = false;
    m_bSIOwner = true;
}
//----------------------------------------------------------------------------
Texture::~Texture ()
{
    if (m_bSIOwner)
    {
        WM4_DELETE m_pkSamplerInformation;
    }

    // Inform all renderers using this texture that it is being destroyed.
    // This allows the renderer to free up any associated resources.
    Release();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Texture::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    int iTmp;
    rkStream.Read(iTmp);
    m_eFType = (FilterType)iTmp;
    for (int i = 0; i < 3; i++)
    {
        rkStream.Read(iTmp);
        m_aeWType[i] = (WrapType)iTmp;
    }
    rkStream.Read(m_kBorderColor);
    rkStream.Read(iTmp);
    m_eCompare = (DepthCompare)iTmp;
    rkStream.Read(m_bOffscreenTexture);

    // The data members m_spkImage, m_pkSamplerInformation, and m_bSIOwner
    // are all set during resource loading at program runtime.

    WM4_END_DEBUG_STREAM_LOAD(Texture);
}
//----------------------------------------------------------------------------
void Texture::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool Texture::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void Texture::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);

    rkStream.Write((int)m_eFType);
    for (int i = 0; i < 3; i++)
    {
        rkStream.Write((int)m_aeWType[i]);
    }
    rkStream.Write(m_kBorderColor);
    rkStream.Write((int)m_eCompare);
    rkStream.Write(m_bOffscreenTexture);

    // The data members m_spkImage, m_pkSamplerInformation, and m_bSIOwner
    // are all set during resource loading at program runtime.

    WM4_END_DEBUG_STREAM_SAVE(Texture);
}
//----------------------------------------------------------------------------
int Texture::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion) +
        sizeof(int) + // m_eFType
        3*sizeof(int) + // m_aeWType[]
        sizeof(m_kBorderColor) +
        sizeof(int) + // m_eCompare
        sizeof(char);  // m_bOffscreenTexture
}
//----------------------------------------------------------------------------
StringTree* Texture::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("filter = ",ms_aacFilterType[m_eFType]));

    const size_t uiTitleSize = 16;
    char acTitle[uiTitleSize];
    for (int i = 0; i < 3; i++)
    {
        System::Sprintf(acTitle,uiTitleSize,"wrap[%d] =",i);
        pkTree->Append(Format(acTitle,ms_aacWrapType[m_aeWType[i]]));
    }

    pkTree->Append(Format("border color =",m_kBorderColor));
    if (m_eCompare != DC_QUANTITY)
    {
        pkTree->Append(Format("depth compare = ",
            ms_aacDepthCompare[m_eCompare]));
    }
    pkTree->Append(Format("offscreen =",m_bOffscreenTexture));

    // children
    pkTree->Append(Object::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
