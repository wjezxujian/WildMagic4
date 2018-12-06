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
inline Image::FormatMode Image::GetFormat () const
{
    return m_eFormat;
}
//----------------------------------------------------------------------------
inline const std::string& Image::GetFormatName () const
{
    return ms_akFormatName[m_eFormat];
}
//----------------------------------------------------------------------------
inline std::string Image::GetFormatName (int eFormat)
{
    return ms_akFormatName[eFormat];
}
//----------------------------------------------------------------------------
inline bool Image::IsDepthImage () const
{
    return m_eFormat == IT_DEPTH16
        || m_eFormat == IT_DEPTH24
        || m_eFormat == IT_DEPTH32;
}
//----------------------------------------------------------------------------
inline bool Image::IsCubeImage () const
{
    return m_eFormat == IT_CUBE_RGB888 || m_eFormat == IT_CUBE_RGBA8888;
}
//----------------------------------------------------------------------------
inline int Image::GetBytesPerPixel () const
{
    return ms_aiBytesPerPixel[m_eFormat];
}
//----------------------------------------------------------------------------
inline int Image::GetBytesPerPixel (int eFormat)
{
    return ms_aiBytesPerPixel[eFormat];
}
//----------------------------------------------------------------------------
inline int Image::GetDimension () const
{
    return m_iDimension;
}
//----------------------------------------------------------------------------
inline int Image::GetBound (int i) const
{
    assert(0 <= i && i < 3);
    return m_aiBound[i];
}
//----------------------------------------------------------------------------
inline int Image::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline unsigned char* Image::GetData () const
{
    return m_aucData;
}
//----------------------------------------------------------------------------
inline unsigned char* Image::operator() (int i)
{
    return m_aucData + i*ms_aiBytesPerPixel[m_eFormat];
}
//----------------------------------------------------------------------------
