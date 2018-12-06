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
inline int ClodTerrainPage::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline const unsigned short* ClodTerrainPage::GetHeights () const
{
    return m_ausHeight;
}
//----------------------------------------------------------------------------
inline const Vector2f& ClodTerrainPage::GetOrigin () const
{
    return m_kOrigin;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetPixelTolerance () const
{
    return m_fPixelTolerance;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetX (int iX) const
{
    return m_kOrigin.X() + m_fSpacing*(float)iX;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetY (int iY) const
{
    return m_kOrigin.Y() + m_fSpacing*(float)iY;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetHeight (int iIndex) const
{
    return m_fMinElevation + m_fMultiplier*(float)m_ausHeight[iIndex];
}
//----------------------------------------------------------------------------
inline float& ClodTerrainPage::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline float ClodTerrainPage::GetTextureCoordinate (int iIndex) const
{
    return m_fUVBias + m_fTextureSpacing*(1.0f-2.0f*m_fUVBias) *
        (float)iIndex;
}
//----------------------------------------------------------------------------
