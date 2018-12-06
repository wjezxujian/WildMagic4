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
inline int SphereBV::GetBVType () const
{
    return BoundingVolume::BV_SPHERE;
}
//----------------------------------------------------------------------------
inline void SphereBV::SetCenter (const Vector3f& rkCenter)
{
    m_kSphere.Center = rkCenter;
}
//----------------------------------------------------------------------------
inline void SphereBV::SetRadius (float fRadius)
{
    m_kSphere.Radius = fRadius;
}
//----------------------------------------------------------------------------
inline Vector3f SphereBV::GetCenter () const
{
    return m_kSphere.Center;
}
//----------------------------------------------------------------------------
inline float SphereBV::GetRadius () const
{
    return m_kSphere.Radius;
}
//----------------------------------------------------------------------------
inline Sphere3f& SphereBV::Sphere ()
{
    return m_kSphere;
}
//----------------------------------------------------------------------------
inline const Sphere3f& SphereBV::GetSphere () const
{
    return m_kSphere;
}
//----------------------------------------------------------------------------
