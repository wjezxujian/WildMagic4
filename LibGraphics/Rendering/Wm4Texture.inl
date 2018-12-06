// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline void Texture::SetImage (Image* pkImage)
{
    m_spkImage = pkImage;
}
//----------------------------------------------------------------------------
inline Image* Texture::GetImage ()
{
    return m_spkImage;
}
//----------------------------------------------------------------------------
inline const Image* Texture::GetImage () const
{
    return m_spkImage;
}
//----------------------------------------------------------------------------
inline void Texture::SetSamplerInformation (
    SamplerInformation* pkSamplerInformation)
{
    m_pkSamplerInformation = pkSamplerInformation;
}
//----------------------------------------------------------------------------
inline SamplerInformation* Texture::GetSamplerInformation ()
{
    return m_pkSamplerInformation;
}
//----------------------------------------------------------------------------
inline const SamplerInformation* Texture::GetSamplerInformation () const
{
    return m_pkSamplerInformation;
}
//----------------------------------------------------------------------------
inline void Texture::SetFilterType (FilterType eFType)
{
    m_eFType = eFType;
}
//----------------------------------------------------------------------------
inline Texture::FilterType Texture::GetFilterType () const
{
    return m_eFType;
}
//----------------------------------------------------------------------------
inline void Texture::SetWrapType (int i, WrapType eWType)
{
    assert(0 <= i && i < 3);
    m_aeWType[i] = eWType;
}
//----------------------------------------------------------------------------
inline Texture::WrapType Texture::GetWrapType (int i) const
{
    assert(0 <= i && i < 3);
    return m_aeWType[i];
}
//----------------------------------------------------------------------------
inline void Texture::SetBorderColor (const ColorRGBA& rkBorderColor)
{
    m_kBorderColor = rkBorderColor;
}
//----------------------------------------------------------------------------
inline ColorRGBA Texture::GetBorderColor () const
{
    return m_kBorderColor;
}
//----------------------------------------------------------------------------
inline bool Texture::IsDepthTexture () const
{
    return m_eCompare != DC_QUANTITY;
}
//----------------------------------------------------------------------------
inline void Texture::SetDepthCompare (DepthCompare eCompare)
{
    m_eCompare = eCompare;
}
//----------------------------------------------------------------------------
inline Texture::DepthCompare Texture::GetDepthCompare () const
{
    return m_eCompare;
}
//----------------------------------------------------------------------------
inline bool Texture::IsOffscreenTexture () const
{
    return m_bOffscreenTexture;
}
//----------------------------------------------------------------------------
inline void Texture::SetOffscreenTexture (bool bOffscreenTexture)
{
    m_bOffscreenTexture = bOffscreenTexture;
}
//----------------------------------------------------------------------------
