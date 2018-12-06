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
inline int Terrain::GetRowQuantity () const
{
    return m_iRows;
}
//----------------------------------------------------------------------------
inline int Terrain::GetColQuantity () const
{
    return m_iCols;
}
//----------------------------------------------------------------------------
inline int Terrain::GetSize () const
{
    return m_iSize;
}
//----------------------------------------------------------------------------
inline float Terrain::GetMinElevation () const
{
    return m_fMinElevation;
}
//----------------------------------------------------------------------------
inline float Terrain::GetMaxElevation () const
{
    return m_fMaxElevation;
}
//----------------------------------------------------------------------------
inline float Terrain::GetSpacing () const
{
    return m_fSpacing;
}
//----------------------------------------------------------------------------
inline float& Terrain::UVBias ()
{
    return m_fUVBias;
}
//----------------------------------------------------------------------------
inline ColorRGBA& Terrain::BorderColor ()
{
    return m_kBorderColor;
}
//----------------------------------------------------------------------------
