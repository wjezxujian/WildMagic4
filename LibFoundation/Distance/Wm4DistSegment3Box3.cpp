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
#include "Wm4DistSegment3Box3.h"
#include "Wm4DistVector3Box3.h"
#include "Wm4DistLine3Box3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistSegment3Box3<Real>::DistSegment3Box3 (const Segment3<Real>& rkSegment,
    const Box3<Real>& rkBox)
    :
    m_rkSegment(rkSegment),
    m_rkBox(rkBox)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& DistSegment3Box3<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Box3<Real>& DistSegment3Box3<Real>::GetBox () const
{
    return m_rkBox;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Box3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Box3<Real>::GetSquared ()
{
    Line3<Real> kLine(m_rkSegment.Origin,m_rkSegment.Direction);
    DistLine3Box3<Real> kLBDist(kLine,m_rkBox);
    Real fLParam = kLBDist.GetLineParameter();

    Real fSqrDistance;
    if (fLParam >= -m_rkSegment.Extent)
    {
        if (fLParam <= m_rkSegment.Extent)
        {
            fSqrDistance = kLBDist.GetSquared();
            m_kClosestPoint0 = kLBDist.GetClosestPoint0();
            m_kClosestPoint1 = kLBDist.GetClosestPoint1();
        }
        else
        {
            DistVector3Box3<Real> kVBDist(m_rkSegment.GetPosEnd(),m_rkBox);
            fSqrDistance = kVBDist.GetSquared();
            m_kClosestPoint0 = kVBDist.GetClosestPoint0();
            m_kClosestPoint1 = kVBDist.GetClosestPoint1();
        }
    }
    else
    {
        DistVector3Box3<Real> kVBDist(m_rkSegment.GetNegEnd(),m_rkBox);
        fSqrDistance = kVBDist.GetSquared();
        m_kClosestPoint0 = kVBDist.GetClosestPoint0();
        m_kClosestPoint1 = kVBDist.GetClosestPoint1();
    }
    return fSqrDistance;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Box3<Real>::Get (Real fT, const Vector3<Real>& rkVelocity0,
    const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkBox.Center + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    Box3<Real> kMBox(kMCenter,m_rkBox.Axis,m_rkBox.Extent);
    return DistSegment3Box3<Real>(kMSegment,kMBox).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Box3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkBox.Center + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    Box3<Real> kMBox(kMCenter,m_rkBox.Axis,m_rkBox.Extent);
    return DistSegment3Box3<Real>(kMSegment,kMBox).GetSquared();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistSegment3Box3<float>;

template WM4_FOUNDATION_ITEM
class DistSegment3Box3<double>;
//----------------------------------------------------------------------------
}
