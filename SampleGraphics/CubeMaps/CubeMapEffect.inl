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
inline void CubeMapEffect::SetReflectivity (float fReflectivity)
{
    m_afReflectivity[0] = fReflectivity;
}
//----------------------------------------------------------------------------
inline float CubeMapEffect::GetReflectivity () const
{
    return m_afReflectivity[0];
}
//----------------------------------------------------------------------------
inline bool CubeMapEffect::CanDynamicallyUpdate () const
{
    return m_spkCubeFace != 0;
}
//----------------------------------------------------------------------------
