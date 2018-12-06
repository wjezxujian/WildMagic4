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
#include "Wm4DistRay3Triangle3.h"
#include "Wm4DistLine3Triangle3.h"
#include "Wm4DistVector3Triangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistRay3Triangle3<Real>::DistRay3Triangle3 (const Ray3<Real>& rkRay,
    const Triangle3<Real>& rkTriangle)
    :
    m_rkRay(rkRay),
    m_rkTriangle(rkTriangle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Ray3<Real>& DistRay3Triangle3<Real>::GetRay () const
{
    return m_rkRay;
}
//----------------------------------------------------------------------------
template <class Real>
const Triangle3<Real>& DistRay3Triangle3<Real>::GetTriangle () const
{
    return m_rkTriangle;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::GetSquared ()
{
    DistLine3Triangle3<Real> kLTDist(Line3<Real>(m_rkRay.Origin,
        m_rkRay.Direction),m_rkTriangle);

    Real fSqrDist;

    m_fRayParameter = kLTDist.GetLineParameter();
    if (m_fRayParameter >= (Real)0.0)
    {
        fSqrDist = kLTDist.GetSquared();
        m_kClosestPoint0 = kLTDist.GetClosestPoint0();
        m_kClosestPoint1 = kLTDist.GetClosestPoint1();
        m_afTriangleBary[0] = kLTDist.GetTriangleBary(0);
        m_afTriangleBary[1] = kLTDist.GetTriangleBary(1);
        m_afTriangleBary[2] = kLTDist.GetTriangleBary(2);
    }
    else
    {
        m_kClosestPoint0 = m_rkRay.Origin;
        DistVector3Triangle3<Real> kVTDist(m_kClosestPoint0,m_rkTriangle);
        fSqrDist = kVTDist.GetSquared();
        m_kClosestPoint1 = kVTDist.GetClosestPoint1();
        m_fRayParameter = (Real)0.0;
        m_afTriangleBary[0] = kVTDist.GetTriangleBary(0);
        m_afTriangleBary[1] = kVTDist.GetTriangleBary(1);
        m_afTriangleBary[2] = kVTDist.GetTriangleBary(2);
    }

    return fSqrDist;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::Get (Real fT, const Vector3<Real>& rkVelocity0,
    const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTriangle.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTriangle.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTriangle.V[2] + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    Triangle3<Real> kMTriangle(kMV0,kMV1,kMV2);
    return DistRay3Triangle3<Real>(kMRay,kMTriangle).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTriangle.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTriangle.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTriangle.V[2] + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    Triangle3<Real> kMTriangle(kMV0,kMV1,kMV2);
    return DistRay3Triangle3<Real>(kMRay,kMTriangle).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::GetRayParameter () const
{
    return m_fRayParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Triangle3<Real>::GetTriangleBary (int i) const
{
    assert(0 <= i && i < 3);
    return m_afTriangleBary[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistRay3Triangle3<float>;

template WM4_FOUNDATION_ITEM
class DistRay3Triangle3<double>;
//----------------------------------------------------------------------------
}
