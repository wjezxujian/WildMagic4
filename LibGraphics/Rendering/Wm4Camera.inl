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
inline Vector3f Camera::GetLocation () const
{
    return m_kLocation;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetDVector () const
{
    return m_kDVector;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetUVector () const
{
    return m_kUVector;
}
//----------------------------------------------------------------------------
inline Vector3f Camera::GetRVector () const
{
    return m_kRVector;
}
//----------------------------------------------------------------------------
inline const float* Camera::GetFrustum () const
{
    return m_afFrustum;
}
//----------------------------------------------------------------------------
inline float Camera::GetDMin () const
{
    return m_afFrustum[VF_DMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetDMax () const
{
    return m_afFrustum[VF_DMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMin () const
{
    return m_afFrustum[VF_UMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetUMax () const
{
    return m_afFrustum[VF_UMAX];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMin () const
{
    return m_afFrustum[VF_RMIN];
}
//----------------------------------------------------------------------------
inline float Camera::GetRMax () const
{
    return m_afFrustum[VF_RMAX];
}
//----------------------------------------------------------------------------
