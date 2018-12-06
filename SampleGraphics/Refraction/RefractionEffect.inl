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
inline void RefractionEffect::SetFresnelConstant (int i, float fValue)
{
    m_afVConstant[i] = fValue;
}
//----------------------------------------------------------------------------
inline float RefractionEffect::GetFresnelConstant (int i) const
{
    return m_afVConstant[i];
}
//----------------------------------------------------------------------------
inline void RefractionEffect::SetEtaRatio (float fEtaRatio)
{
    m_afVConstant[3] = fEtaRatio;
}
//----------------------------------------------------------------------------
inline float RefractionEffect::GetEtaRatio () const
{
    return m_afVConstant[3];
}
//----------------------------------------------------------------------------
