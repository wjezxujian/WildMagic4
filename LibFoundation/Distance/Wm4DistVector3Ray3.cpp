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
#include "Wm4DistVector3Ray3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistVector3Ray3<Real>::DistVector3Ray3 (const Vector3<Real>& rkVector,
    const Ray3<Real>& rkRay)
    :
    m_rkVector(rkVector),
    m_rkRay(rkRay)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& DistVector3Ray3<Real>::GetVector () const
{
    return m_rkVector;
}
//----------------------------------------------------------------------------
template <class Real>
const Ray3<Real>& DistVector3Ray3<Real>::GetRay () const
{
    return m_rkRay;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Ray3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Ray3<Real>::GetSquared ()
{
    Vector3<Real> kDiff = m_rkVector - m_rkRay.Origin;
    m_fRayParameter = m_rkRay.Direction.Dot(kDiff);
    if (m_fRayParameter > (Real)0.0)
    {
        m_kClosestPoint1 = m_rkRay.Origin + m_fRayParameter*m_rkRay.Direction;
    }
    else
    {
        m_kClosestPoint1 = m_rkRay.Origin;
        m_fRayParameter = (Real)0.0;
    }

    m_kClosestPoint0 = m_rkVector;
    kDiff = m_kClosestPoint1 - m_kClosestPoint0;
    return kDiff.SquaredLength();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Ray3<Real>::Get (Real fT, const Vector3<Real>& rkVelocity0,
    const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    return DistVector3Ray3<Real>(kMVector,kMRay).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Ray3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMOrigin = m_rkRay.Origin + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin,m_rkRay.Direction);
    return DistVector3Ray3<Real>(kMVector,kMRay).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Ray3<Real>::GetRayParameter () const
{
    return m_fRayParameter;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistVector3Ray3<float>;

template WM4_FOUNDATION_ITEM
class DistVector3Ray3<double>;
//----------------------------------------------------------------------------
}
