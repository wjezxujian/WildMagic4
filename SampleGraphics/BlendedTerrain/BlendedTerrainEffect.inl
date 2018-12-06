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
inline void BlendedTerrainEffect::SetFlowDirection (
    const Vector2f& rkFlowDirection)
{
    m_afFlowDirection[0] = rkFlowDirection[0];
    m_afFlowDirection[1] = rkFlowDirection[1];
}
//----------------------------------------------------------------------------
inline Vector2f BlendedTerrainEffect::GetFlowDirection () const
{
    return Vector2f(m_afFlowDirection[0],m_afFlowDirection[1]);
}
//----------------------------------------------------------------------------
inline void BlendedTerrainEffect::SetPowerFactor (float fPowerFactor)
{
    m_afPowerFactor[0] = fPowerFactor;
}
//----------------------------------------------------------------------------
inline float BlendedTerrainEffect::GetPowerFactor () const
{
    return m_afPowerFactor[0];
}
//----------------------------------------------------------------------------
