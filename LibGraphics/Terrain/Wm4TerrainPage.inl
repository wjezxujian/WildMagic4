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
inline int TerrainPage::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline const unsigned short* TerrainPage::GetHeights () const
{
    return m_ausHeight;
}
//----------------------------------------------------------------------------
inline const Vector2f& TerrainPage::GetOrigin () const
{
    return m_kOrigin;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetX (int iX) const
{
    return m_kOrigin.X() + m_fSpacing*float(iX);
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetY (int iY) const
{
    return m_kOrigin.Y() + m_fSpacing*float(iY);
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetHeight (int iIndex) const
{
    return m_fMinElevation + m_fMultiplier*float(m_ausHeight[iIndex]);
}
//----------------------------------------------------------------------------
inline float& TerrainPage::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline float TerrainPage::GetTextureCoordinate (int iIndex) const
{
    return m_fTextureSpacing*float(iIndex);
}
//----------------------------------------------------------------------------
