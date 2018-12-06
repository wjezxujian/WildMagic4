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
inline void Spatial::SetParent (Spatial* pkParent)
{
    m_pkParent = pkParent;
}
//----------------------------------------------------------------------------
inline Spatial* Spatial::GetParent ()
{
    return m_pkParent;
}
//----------------------------------------------------------------------------
inline int Spatial::GetGlobalStateQuantity () const
{
    return (int)m_kGlobalStates.size();
}
//----------------------------------------------------------------------------
inline GlobalState* Spatial::GetGlobalState (int i) const
{
    assert(0 <= i && i < (int)m_kGlobalStates.size());
    return m_kGlobalStates[i];
}
//----------------------------------------------------------------------------
inline void Spatial::DetachAllGlobalStates ()
{
    m_kGlobalStates.clear();
}
//----------------------------------------------------------------------------
inline int Spatial::GetLightQuantity () const
{
    return (int)m_kLights.size();
}
//----------------------------------------------------------------------------
inline Light* Spatial::GetLight (int i) const
{
    assert(0 <= i && i < (int)m_kLights.size());
    return StaticCast<Light>(m_kLights[i]);
}
//----------------------------------------------------------------------------
inline void Spatial::DetachAllLights ()
{
    m_kLights.clear();
}
//----------------------------------------------------------------------------
inline int Spatial::GetEffectQuantity () const
{
    return (int)m_kEffects.size();
}
//----------------------------------------------------------------------------
inline Effect* Spatial::GetEffect (int i) const
{
    assert(0 <= i && i < (int)m_kEffects.size());
    return StaticCast<Effect>(m_kEffects[i]);
}
//----------------------------------------------------------------------------
inline void Spatial::DetachAllEffects ()
{
    m_kEffects.clear();
}
//----------------------------------------------------------------------------
inline void Spatial::SetStartEffect (int i)
{
    assert(0 <= i && i < (int)m_kEffects.size());
    m_iStartEffect = i;
}
//----------------------------------------------------------------------------
inline int Spatial::GetStartEffect () const
{
    return m_iStartEffect;
}
//----------------------------------------------------------------------------
