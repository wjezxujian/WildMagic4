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
#include "Wm4DistRay3Rectangle3.h"
#include "Wm4DistLine3Rectangle3.h"
#include "Wm4DistVector3Rectangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistRay3Rectangle3<Real>::DistRay3Rectangle3 (const Ray3<Real>& rkRay,
    const Rectangle3<Real>& rkRectangle)
    :
    m_rkRay(rkRay),
    m_rkRectangle(rkRectangle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Ray3<Real>& DistRay3Rectangle3<Real>::GetRay () const
{
    return m_rkRay;
}
//----------------------------------------------------------------------------
template <class Real>
const Rectangle3<Real>& DistRay3Rectangle3<Real>::GetRectangle () const
{
    return m_rkRectangle;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::GetSquared ()
{
    DistLine3Rectangle3<Real> kLRDist(Line3<Real>(m_rkRay.Origin,
        m_rkRay.Direction),m_rkRectangle);

    Real fSqrDist;

    m_fRayParameter = kLRDist.GetLineParameter();
    if (m_fRayParameter >= (Real)0.0)
    {
        fSqrDist = kLRDist.GetSquared();
        m_kClosestPoint0 = kLRDist.GetClosestPoint0();
        m_kClosestPoint1 = kLRDist.GetClosestPoint1();
        m_afRectCoord[0] = kLRDist.GetRectangleCoordinate(0);
        m_afRectCoord[1] = kLRDist.GetRectangleCoordinate(1);
    }
    else
    {
        m_kClosestPoint0 = m_rkRay.Origin;
        DistVector3Rectangle3<Real> kVRDist(m_kClosestPoint0,m_rkRectangle);
        fSqrDist = kVRDist.GetSquared();
        m_kClosestPoint1 = kVRDist.GetClosestPoint1();
        m_fRayParameter = (Real)0.0;
        m_afRectCoord[0] = kVRDist.GetRectangleCoordinate(0);
        m_afRectCoord[1] = kVRDist.GetRectangleCoordinate(1);
    }

    return fSqrDist;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::Get (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistRay3Rectangle3<Real>(kMRay,kMRectangle).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistRay3Rectangle3<Real>(kMRay,kMRectangle).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::GetRayParameter () const
{
    return m_fRayParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Rectangle3<Real>::GetRectangleCoordinate (int i) const
{
    assert(0 <= i && i < 2);
    return m_afRectCoord[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistRay3Rectangle3<float>;

template WM4_FOUNDATION_ITEM
class DistRay3Rectangle3<double>;
//----------------------------------------------------------------------------
}
