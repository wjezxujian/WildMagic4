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
#include "Wm4DistLine3Rectangle3.h"
#include "Wm4DistLine3Segment3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistLine3Rectangle3<Real>::DistLine3Rectangle3 (const Line3<Real>& rkLine,
    const Rectangle3<Real>& rkRectangle)
    :
    m_rkLine(rkLine),
    m_rkRectangle(rkRectangle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Line3<Real>& DistLine3Rectangle3<Real>::GetLine () const
{
    return m_rkLine;
}
//----------------------------------------------------------------------------
template <class Real>
const Rectangle3<Real>& DistLine3Rectangle3<Real>::GetRectangle () const
{
    return m_rkRectangle;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::GetSquared ()
{
    // Test if line intersects rectangle.  If so, the squared distance is
    // zero.
    Vector3<Real> kN = m_rkRectangle.Axis[0].Cross(m_rkRectangle.Axis[1]);
    Real fNdD = kN.Dot(m_rkLine.Direction);
    if (Math<Real>::FAbs(fNdD) > Math<Real>::ZERO_TOLERANCE)
    {
        // The line and rectangle are not parallel, so the line intersects
        // the plane of the rectangle.
        Vector3<Real> kDiff = m_rkLine.Origin - m_rkRectangle.Center;
        Vector3<Real>& rkD = (Vector3<Real>&) m_rkLine.Direction;
        Vector3<Real> kU, kV;
        Vector3<Real>::GenerateOrthonormalBasis(kU,kV,rkD,true);
        Real fUdD0 = kU.Dot(m_rkRectangle.Axis[0]);
        Real fUdD1 = kU.Dot(m_rkRectangle.Axis[1]);
        Real fUdPmC = kU.Dot(kDiff);
        Real fVdD0 = kV.Dot(m_rkRectangle.Axis[0]);
        Real fVdD1 = kV.Dot(m_rkRectangle.Axis[1]);
        Real fVdPmC = kV.Dot(kDiff);
        Real fInvDet = ((Real)1.0)/(fUdD0*fVdD1 - fUdD1*fVdD0);

        // Rectangle coordinates for the point of intersection.
        Real fS0 = (fVdD1*fUdPmC - fUdD1*fVdPmC)*fInvDet;
        Real fS1 = (fUdD0*fVdPmC - fVdD0*fUdPmC)*fInvDet;

        if (Math<Real>::FAbs(fS0) <= m_rkRectangle.Extent[0]
        &&  Math<Real>::FAbs(fS1) <= m_rkRectangle.Extent[1])
        {
            // Line parameter for the point of intersection.
            Real fDdD0 = rkD.Dot(m_rkRectangle.Axis[0]);
            Real fDdD1 = rkD.Dot(m_rkRectangle.Axis[1]);
            Real fDdDiff = m_rkLine.Direction.Dot(kDiff);
            m_fLineParameter = fS0*fDdD0 + fS1*fDdD1 - fDdDiff;

            // Rectangle coordinates for the point of intersection.
            m_afRectCoord[0] = fS0;
            m_afRectCoord[1] = fS1;

            // The intersection point is inside or on the rectangle.
            m_kClosestPoint0 = m_rkLine.Origin +
                m_fLineParameter*m_rkLine.Direction;

            m_kClosestPoint1 = m_rkRectangle.Center +
                fS0*m_rkRectangle.Axis[0] + fS1*m_rkRectangle.Axis[1];
            return (Real)0.0;
        }
    }

    // Either (1) the line is not parallel to the rectangle and the point of
    // intersection of the line and the plane of the rectangle is outside the
    // rectangle or (2) the line and rectangle are parallel.  Regardless, the
    // closest point on the rectangle is on an edge of the rectangle.  Compare
    // the line to all four edges of the rectangle.
    Real fSqrDist = Math<Real>::MAX_REAL;
    Vector3<Real> akSDir[2] =
    {
        m_rkRectangle.Extent[0]*m_rkRectangle.Axis[0],
        m_rkRectangle.Extent[1]*m_rkRectangle.Axis[1]
    };
    for (int i1 = 0; i1 < 2; i1++)
    {
        for (int i0 = 0; i0 < 2; i0++)
        {
            Segment3<Real> kSeg;
            kSeg.Origin = m_rkRectangle.Center + ((Real)(2*i0-1))*akSDir[i1];
            kSeg.Direction = m_rkRectangle.Axis[1-i1];
            kSeg.Extent = m_rkRectangle.Extent[1-i1];
            DistLine3Segment3<Real> kLSDist(m_rkLine,kSeg);
            Real fSqrDistTmp = kLSDist.GetSquared();
            if (fSqrDistTmp < fSqrDist)
            {
                m_kClosestPoint0 = kLSDist.GetClosestPoint0();
                m_kClosestPoint1 = kLSDist.GetClosestPoint1();
                fSqrDist = fSqrDistTmp;

                m_fLineParameter = kLSDist.GetLineParameter();
                Real fRatio = kLSDist.GetSegmentParameter()/kSeg.Extent;
                m_afRectCoord[0] = m_rkRectangle.Extent[0]*((1-i1)*(2*i0-1) +
                    i1*fRatio);
                m_afRectCoord[1] = m_rkRectangle.Extent[1]*((1-i0)*(2*i1-1) +
                    i0*fRatio);
            }
        }
    }
    return fSqrDist;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::Get (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkLine.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Line3<Real> kMLine(kMOrigin,m_rkLine.Direction);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistLine3Rectangle3<Real>(kMLine,kMRectangle).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin = m_rkLine.Origin + fT*rkVelocity0;
    Vector3<Real> kMCenter = m_rkRectangle.Center + fT*rkVelocity1;
    Line3<Real> kMLine(kMOrigin,m_rkLine.Direction);
    Rectangle3<Real> kMRectangle(kMCenter,m_rkRectangle.Axis,
        m_rkRectangle.Extent);
    return DistLine3Rectangle3<Real>(kMLine,kMRectangle).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::GetLineParameter () const
{
    return m_fLineParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistLine3Rectangle3<Real>::GetRectangleCoordinate (int i) const
{
    assert(0 <= i && i < 2);
    return m_afRectCoord[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistLine3Rectangle3<float>;

template WM4_FOUNDATION_ITEM
class DistLine3Rectangle3<double>;
//----------------------------------------------------------------------------
}
