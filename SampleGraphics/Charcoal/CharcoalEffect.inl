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
inline void CharcoalEffect::SetAmbientIntensity (float fAmbientIntensity)
{
    m_afAmbientContrast[0] = fAmbientIntensity;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetAmbientIntensity () const
{
    return m_afAmbientContrast[0];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetContrastExponent (float fContrastExponent)
{
    m_afAmbientContrast[1] = fContrastExponent;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetContrastExponent () const
{
    return m_afAmbientContrast[1];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetSmudgeFactor (float fSmudgeFactor)
{
    m_afSmudgePaper[0] = fSmudgeFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetSmudgeFactor () const
{
    return m_afSmudgePaper[0];
}
//----------------------------------------------------------------------------
inline void CharcoalEffect::SetPaperFactor (float fPaperFactor)
{
    m_afSmudgePaper[1] = fPaperFactor;
}
//----------------------------------------------------------------------------
inline float CharcoalEffect::GetPaperFactor () const
{
    return m_afSmudgePaper[1];
}
//----------------------------------------------------------------------------
