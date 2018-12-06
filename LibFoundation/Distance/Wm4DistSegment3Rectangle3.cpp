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
#include "Wm4DistSegment3Rectangle3.h"
#include "Wm4DistLine3Rectangle3.h"
#include "Wm4DistVector3Rectangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistSegment3Rectangle3<Real>::DistSegment3Rectangle3 (
    const Segment3<Real>& rkSegment, const Rectangle3<Real>& rkRectangle)
    :
    m_rkSegment(rkSegment),
    m_rkRectangle(rkRectangle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& DistSegment3Rectangle3<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Rectangle3<Real>& DistSegment3Rectangle3<Real>::GetRectangle () const
{
    return m_rkRectangle;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::GetSquared ()
{
    DistLine3Rectangle3<Real> kLRDist(Line3<Real>(m_rkSegment.Origin,
        m_rkSegment.Direction),m_rkRectangle);

    Real fSqrDist;

    m_fSegmentParameter = kLRDist.GetLineParameter();
    if (m_fSegmentParameter >= -m_rkSegment.Extent)
    {
        if (m_fSegmentParameter <= m_rkSegment.Extent)
        {
            fSqrDist = kLRDist.GetSquared();
            m_kClosestPoint0 = kLRDist.GetClosestPoint0();
            m_kClosestPoint1 = kLRDist.GetClosestPoint1();
            m_afRectCoord[0] = kLRDist.GetRectangleCoordinate(0);
            m_afRectCoord[1] = kLRDist.GetRectangleCoordinate(1);
        }
        else
        {
            m_kClosestPoint0 = m_rkSegment.GetPosEnd();
            DistVector3Rectangle3<Real> kVTDist(m_kClosestPoint0,
                m_rkRectangle);
            fSqrDist = kVTDist.GetSquared();
            m_kClosestPoint1 = kVTDist.GetClosestPoint1();
            m_fSegmentParameter = m_rkSegment.Extent;
            m_afRectCoord[0] = kVTDist.GetRectangleCoordinate(0);
            m_afRectCoord[1] = kVTDist.GetRectangleCoordinate(1);
        }
    }
    else
    {
        m_kClosestPoint0 = m_rkSegment.GetNegEnd();
        DistVector3Rectangle3<Real> kVTDist(m_kClosestPoint0,m_rkRectangle);
        fSqrDist = kVTDist.GetSquared();
        m_kClosestPoint1 = kVTDist.GetClosestPoint1();
        m_fSegmentParameter = -m_rkSegment.Extent;
        m_afRectCoord[0] = kVTDist.GetRectangleCoordinate(0);
        m_afRectCoord[1] = kVTDist.GetRectangleCoordinate(1);
    }

    return fSqrDist;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::Get (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistSegment3Rectangle3<Real>(kMSegment,kMRectangle).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkSegment.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Segment3<Real> kMSegment(kMOrigin,m_rkSegment.Direction,
        m_rkSegment.Extent);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistSegment3Rectangle3<Real>(kMSegment,kMRectangle).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::GetSegmentParameter () const
{
    return m_fSegmentParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment3Rectangle3<Real>::GetRectangleCoordinate (int i) const
{
    assert(0 <= i && i < 2);
    return m_afRectCoord[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistSegment3Rectangle3<float>;

template WM4_FOUNDATION_ITEM
class DistSegment3Rectangle3<double>;
//----------------------------------------------------------------------------
}
