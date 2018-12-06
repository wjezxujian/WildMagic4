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
#include "Wm4DistRay3Segment3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistRay3Segment3<Real>::DistRay3Segment3 (const Ray3<Real>& rkRay,
    const Segment3<Real>& rkSegment)
    :
    m_rkRay(rkRay),
    m_rkSegment(rkSegment)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Ray3<Real>& DistRay3Segment3<Real>::GetRay () const
{
    return m_rkRay;
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& DistRay3Segment3<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::GetSquared ()
{
    Vector3<Real> kDiff = m_rkRay.Origin- m_rkSegment.Origin;
    Real fA01 = -m_rkRay.Direction.Dot(m_rkSegment.Direction);
    Real fB0 = kDiff.Dot(m_rkRay.Direction);
    Real fB1 = -kDiff.Dot(m_rkSegment.Direction);
    Real fC = kDiff.SquaredLength();
    Real fDet = Math<Real>::FAbs((Real)1.0 - fA01*fA01);
    Real fS0, fS1, fSqrDist, fExtDet;

    if (fDet >= Math<Real>::ZERO_TOLERANCE)
    {
        // The ray and segment are not parallel.
        fS0 = fA01*fB1-fB0;
        fS1 = fA01*fB0-fB1;
        fExtDet = m_rkSegment.Extent*fDet;

        if (fS0 >= (Real)0.0)
        {
            if (fS1 >= -fExtDet)
            {
                if (fS1 <= fExtDet)  // region 0
                {
                    // minimum at interior points of ray and segment
                    Real fInvDet = ((Real)1.0)/fDet;
                    fS0 *= fInvDet;
                    fS1 *= fInvDet;
                    fSqrDist = fS0*(fS0+fA01*fS1+((Real)2.0)*fB0) +
                        fS1*(fA01*fS0+fS1+((Real)2.0)*fB1)+fC;
                }
                else  // region 1
                {
                    fS1 = m_rkSegment.Extent;
                    fS0 = -(fA01*fS1+fB0);
                    if (fS0 > (Real)0.0)
                    {
                        fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else
                    {
                        fS0 = (Real)0.0;
                        fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                }
            }
            else  // region 5
            {
                fS1 = -m_rkSegment.Extent;
                fS0 = -(fA01*fS1+fB0);
                if (fS0 > (Real)0.0)
                {
                    fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
                else
                {
                    fS0 = (Real)0.0;
                    fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
            }
        }
        else
        {
            if (fS1 <= -fExtDet)  // region 4
            {
                fS0 = -(-fA01*m_rkSegment.Extent+fB0);
                if (fS0 > (Real)0.0)
                {
                    fS1 = -m_rkSegment.Extent;
                    fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
                else
                {
                    fS0 = (Real)0.0;
                    fS1 = -fB1;
                    if (fS1 < -m_rkSegment.Extent)
                    {
                        fS1 = -m_rkSegment.Extent;
                    }
                    else if (fS1 > m_rkSegment.Extent)
                    {
                        fS1 = m_rkSegment.Extent;
                    }
                    fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
            }
            else if (fS1 <= fExtDet)  // region 3
            {
                fS0 = (Real)0.0;
                fS1 = -fB1;
                if (fS1 < -m_rkSegment.Extent)
                {
                    fS1 = -m_rkSegment.Extent;
                }
                else if (fS1 > m_rkSegment.Extent)
                {
                    fS1 = m_rkSegment.Extent;
                }
                fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
            }
            else  // region 2
            {
                fS0 = -(fA01*m_rkSegment.Extent+fB0);
                if (fS0 > (Real)0.0)
                {
                    fS1 = m_rkSegment.Extent;
                    fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
                else
                {
                    fS0 = (Real)0.0;
                    fS1 = -fB1;
                    if (fS1 < -m_rkSegment.Extent)
                    {
                        fS1 = -m_rkSegment.Extent;
                    }
                    else if (fS1 > m_rkSegment.Extent)
                    {
                        fS1 = m_rkSegment.Extent;
                    }
                    fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
            }
        }
    }
    else
    {
        // ray and segment are parallel
        if (fA01 > (Real)0.0)
        {
            // opposite direction vectors
            fS1 = -m_rkSegment.Extent;
        }
        else
        {
            // same direction vectors
            fS1 = m_rkSegment.Extent;
        }

        fS0 = -(fA01*fS1+fB0);
        if (fS0 > (Real)0.0)
        {
            fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
        }
        else
        {
            fS0 = (Real)0.0;
            fSqrDist = fS1*(fS1+((Real)2.0)*fB1)+fC;
        }
    }

    m_kClosestPoint0 = m_rkRay.Origin + fS0*m_rkRay.Direction;
    m_kClosestPoint1 = m_rkSegment.Origin + fS1*m_rkSegment.Direction;
    m_fRayParameter = fS0;
    m_fSegmentParameter = fS1;
    return Math<Real>::FAbs(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::Get (Real fT, const Vector3<Real>& rkVelocity0,
    const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin0 = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMOrigin1 = m_rkSegment.Origin + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin0,m_rkRay.Direction);
    Segment3<Real> kMSegment(kMOrigin1,m_rkSegment.Direction,
        m_rkSegment.Extent);
    return DistRay3Segment3<Real>(kMRay,kMSegment).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMOrigin0 = m_rkRay.Origin + fT*rkVelocity0;
    Vector3<Real> kMOrigin1 = m_rkSegment.Origin + fT*rkVelocity1;
    Ray3<Real> kMRay(kMOrigin0,m_rkRay.Direction);
    Segment3<Real> kMSegment(kMOrigin1,m_rkSegment.Direction,
        m_rkSegment.Extent);
    return DistRay3Segment3<Real>(kMRay,kMSegment).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::GetRayParameter () const
{
    return m_fRayParameter;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistRay3Segment3<Real>::GetSegmentParameter () const
{
    return m_fSegmentParameter;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistRay3Segment3<float>;

template WM4_FOUNDATION_ITEM
class DistRay3Segment3<double>;
//----------------------------------------------------------------------------
}
