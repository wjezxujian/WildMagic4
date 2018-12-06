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
inline void TerrainEffect::SetFogColor (const ColorRGB& rkFogColor)
{
    m_afFogColorDensity[0] = rkFogColor[0];
    m_afFogColorDensity[1] = rkFogColor[1];
    m_afFogColorDensity[2] = rkFogColor[2];
}
//----------------------------------------------------------------------------
inline ColorRGB TerrainEffect::GetFogColor () const
{
    return ColorRGB(m_afFogColorDensity[0],m_afFogColorDensity[1],
        m_afFogColorDensity[2]);
}
//----------------------------------------------------------------------------
inline void TerrainEffect::SetFogDensity (float fFogDensity)
{
    m_afFogColorDensity[3] = fFogDensity;
}
//----------------------------------------------------------------------------
inline float TerrainEffect::GetFogDensity () const
{
    return m_afFogColorDensity[3];
}
//----------------------------------------------------------------------------
