// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4IntrPlane3Sphere3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrPlane3Sphere3<Real>::IntrPlane3Sphere3 (const Plane3<Real>& rkPlane,
    const Sphere3<Real>& rkSphere)
    :
    m_rkPlane(rkPlane),
    m_rkSphere(rkSphere)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrPlane3Sphere3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Sphere3<Real>& IntrPlane3Sphere3<Real>::GetSphere () const
{
    return m_rkSphere;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Sphere3<Real>::Test ()
{
    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkSphere.Center);
    return Math<Real>::FAbs(fSignedDistance) <= m_rkSphere.Radius;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Sphere3<Real>::SphereIsCulled () const
{
    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkSphere.Center);
    return fSignedDistance <= -m_rkSphere.Radius;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrPlane3Sphere3<float>;

template WM4_FOUNDATION_ITEM
class IntrPlane3Sphere3<double>;
//----------------------------------------------------------------------------
}
