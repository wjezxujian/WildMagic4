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
#include "Wm4DistVector3Segment3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistVector3Segment3<Real>::DistVector3Segment3 (const Vector3<Real>& rkVector,
    const Segment3<Real>& rkSegment)
    :
    m_rkVector(rkVector),
    m_rkSegment(rkSegment)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& DistVector3Segment3<Real>::GetVector () const
{
    return m_rkVector;
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& DistVector3Segment3<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Segment3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Segment3<Real>::GetSquared ()
{
    Vector3<Real> kDiff = m_rkVector - m_rkSegment.Origin;
    m_fSegmentParameter = m_rkSegment.Direction.Dot(kDiff);

    if (-m_rkSegment.Extent < m_fSegmentParameter)
    {
        if (m_fSegmentParameter < m_rkSegment.Extent)
        {
            m_kClosestPoint1 = m_rkSegment.Origin +
                m_fSegmentParameter*m_rkSegment.Direction;
        }
        else
        {
            m_kClosestPoint1 = m_rkSegment.Origin +
                m_rkSegment.Extent*m_rkSegment.Direction;
        }
    }
    else
    {
        m_kClosestPoint1 = m_rkSegment.Origin -
            m_rkSegment.Extent*m_rkSegment.Direction;
    }

    m_kClosestPoint0 = m_rkVector;
    kDiff = m_kClosestPoint1 - m_kClosestPoint0;
    return kDiff.SquaredLength();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Segment3<Real>::Get (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    return DistVector3Segment3<Real>(kMVector,kMSegment).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Segment3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    return DistVector3Segment3<Real>(kMVector,kMSegment).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Segment3<Real>::GetSegmentParameter () const
{
    return m_fSegmentParameter;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistVector3Segment3<float>;

template WM4_FOUNDATION_ITEM
class DistVector3Segment3<double>;
//----------------------------------------------------------------------------
}
