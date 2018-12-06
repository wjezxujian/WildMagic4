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
#include "Wm4DistSegment2Segment2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistSegment2Segment2<Real>::DistSegment2Segment2 (
    const Segment2<Real>& rkSegment0, const Segment2<Real>& rkSegment1)
    :
    m_rkSegment0(rkSegment0),
    m_rkSegment1(rkSegment1)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment2<Real>& DistSegment2Segment2<Real>::GetSegment0 () const
{
    return m_rkSegment0;
}
//----------------------------------------------------------------------------
template <class Real>
const Segment2<Real>& DistSegment2Segment2<Real>::GetSegment1 () const
{
    return m_rkSegment1;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment2Segment2<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment2Segment2<Real>::GetSquared ()
{
    Vector2<Real> kDiff = m_rkSegment0.Origin - m_rkSegment1.Origin;
    Real fA01 = -m_rkSegment0.Direction.Dot(m_rkSegment1.Direction);
    Real fB0 = kDiff.Dot(m_rkSegment0.Direction);
    Real fB1 = -kDiff.Dot(m_rkSegment1.Direction);
    Real fC = kDiff.SquaredLength();
    Real fDet = Math<Real>::FAbs((Real)1.0 - fA01*fA01);
    Real fS0, fS1, fSqrDist, fExtDet0, fExtDet1, fTmpS0, fTmpS1;

    if (fDet >= Math<Real>::ZERO_TOLERANCE)
    {
        // segments are not parallel
        fS0 = fA01*fB1-fB0;
        fS1 = fA01*fB0-fB1;
        fExtDet0 = m_rkSegment0.Extent*fDet;
        fExtDet1 = m_rkSegment1.Extent*fDet;

        if (fS0 >= -fExtDet0)
        {
            if (fS0 <= fExtDet0)
            {
                if (fS1 >= -fExtDet1)
                {
                    if (fS1 <= fExtDet1)  // region 0 (interior)
                    {
                        // minimum at two interior points of 3D lines
                        Real fInvDet = ((Real)1.0)/fDet;
                        fS0 *= fInvDet;
                        fS1 *= fInvDet;
                        fSqrDist = (Real)0.0;
                    }
                    else  // region 3 (side)
                    {
                        fS1 = m_rkSegment1.Extent;
                        fTmpS0 = -(fA01*fS1+fB0);
                        if (fTmpS0 < -m_rkSegment0.Extent)
                        {
                            fS0 = -m_rkSegment0.Extent;
                            fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                                fS1*(fS1+((Real)2.0)*fB1)+fC;
                        }
                        else if (fTmpS0 <= m_rkSegment0.Extent)
                        {
                            fS0 = fTmpS0;
                            fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                        }
                        else
                        {
                            fS0 = m_rkSegment0.Extent;
                            fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                                fS1*(fS1+((Real)2.0)*fB1)+fC;
                        }
                    }
                }
                else  // region 7 (side)
                {
                    fS1 = -m_rkSegment1.Extent;
                    fTmpS0 = -(fA01*fS1+fB0);
                    if (fTmpS0 < -m_rkSegment0.Extent)
                    {
                        fS0 = -m_rkSegment0.Extent;
                        fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                            fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else if (fTmpS0 <= m_rkSegment0.Extent)
                    {
                        fS0 = fTmpS0;
                        fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else
                    {
                        fS0 = m_rkSegment0.Extent;
                        fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                            fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                }
            }
            else
            {
                if (fS1 >= -fExtDet1)
                {
                    if (fS1 <= fExtDet1)  // region 1 (side)
                    {
                        fS0 = m_rkSegment0.Extent;
                        fTmpS1 = -(fA01*fS0+fB1);
                        if (fTmpS1 < -m_rkSegment1.Extent)
                        {
                            fS1 = -m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                        else if (fTmpS1 <= m_rkSegment1.Extent)
                        {
                            fS1 = fTmpS1;
                            fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                        else
                        {
                            fS1 = m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                    }
                    else  // region 2 (corner)
                    {
                        fS1 = m_rkSegment1.Extent;
                        fTmpS0 = -(fA01*fS1+fB0);
                        if (fTmpS0 < -m_rkSegment0.Extent)
                        {
                            fS0 = -m_rkSegment0.Extent;
                            fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                                fS1*(fS1+((Real)2.0)*fB1)+fC;
                        }
                        else if (fTmpS0 <= m_rkSegment0.Extent)
                        {
                            fS0 = fTmpS0;
                            fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                        }
                        else
                        {
                            fS0 = m_rkSegment0.Extent;
                            fTmpS1 = -(fA01*fS0+fB1);
                            if (fTmpS1 < -m_rkSegment1.Extent)
                            {
                                fS1 = -m_rkSegment1.Extent;
                                fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                    fS0*(fS0+((Real)2.0)*fB0)+fC;
                            }
                            else if (fTmpS1 <= m_rkSegment1.Extent)
                            {
                                fS1 = fTmpS1;
                                fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)
                                    + fC;
                            }
                            else
                            {
                                fS1 = m_rkSegment1.Extent;
                                fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                    fS0*(fS0+((Real)2.0)*fB0)+fC;
                            }
                        }
                    }
                }
                else  // region 8 (corner)
                {
                    fS1 = -m_rkSegment1.Extent;
                    fTmpS0 = -(fA01*fS1+fB0);
                    if (fTmpS0 < -m_rkSegment0.Extent)
                    {
                        fS0 = -m_rkSegment0.Extent;
                        fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                            fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else if (fTmpS0 <= m_rkSegment0.Extent)
                    {
                        fS0 = fTmpS0;
                        fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else
                    {
                        fS0 = m_rkSegment0.Extent;
                        fTmpS1 = -(fA01*fS0+fB1);
                        if (fTmpS1 > m_rkSegment1.Extent)
                        {
                            fS1 = m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                        else if (fTmpS1 >= -m_rkSegment1.Extent)
                        {
                            fS1 = fTmpS1;
                            fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)
                                + fC;
                        }
                        else
                        {
                            fS1 = -m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                    }
                }
            }
        }
        else 
        {
            if (fS1 >= -fExtDet1)
            {
                if (fS1 <= fExtDet1)  // region 5 (side)
                {
                    fS0 = -m_rkSegment0.Extent;
                    fTmpS1 = -(fA01*fS0+fB1);
                    if (fTmpS1 < -m_rkSegment1.Extent)
                    {
                        fS1 = -m_rkSegment1.Extent;
                        fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                            fS0*(fS0+((Real)2.0)*fB0)+fC;
                    }
                    else if (fTmpS1 <= m_rkSegment1.Extent)
                    {
                        fS1 = fTmpS1;
                        fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)+fC;
                    }
                    else
                    {
                        fS1 = m_rkSegment1.Extent;
                        fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                            fS0*(fS0+((Real)2.0)*fB0)+fC;
                    }
                }
                else  // region 4 (corner)
                {
                    fS1 = m_rkSegment1.Extent;
                    fTmpS0 = -(fA01*fS1+fB0);
                    if (fTmpS0 > m_rkSegment0.Extent)
                    {
                        fS0 = m_rkSegment0.Extent;
                        fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                            fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else if (fTmpS0 >= -m_rkSegment0.Extent)
                    {
                        fS0 = fTmpS0;
                        fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                    }
                    else
                    {
                        fS0 = -m_rkSegment0.Extent;
                        fTmpS1 = -(fA01*fS0+fB1);
                        if (fTmpS1 < -m_rkSegment1.Extent)
                        {
                            fS1 = -m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                        else if (fTmpS1 <= m_rkSegment1.Extent)
                        {
                            fS1 = fTmpS1;
                            fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)
                                + fC;
                        }
                        else
                        {
                            fS1 = m_rkSegment1.Extent;
                            fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                                fS0*(fS0+((Real)2.0)*fB0)+fC;
                        }
                    }
                }
            }
            else   // region 6 (corner)
            {
                fS1 = -m_rkSegment1.Extent;
                fTmpS0 = -(fA01*fS1+fB0);
                if (fTmpS0 > m_rkSegment0.Extent)
                {
                    fS0 = m_rkSegment0.Extent;
                    fSqrDist = fS0*(fS0-((Real)2.0)*fTmpS0) +
                        fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
                else if (fTmpS0 >= -m_rkSegment0.Extent)
                {
                    fS0 = fTmpS0;
                    fSqrDist = -fS0*fS0+fS1*(fS1+((Real)2.0)*fB1)+fC;
                }
                else
                {
                    fS0 = -m_rkSegment0.Extent;
                    fTmpS1 = -(fA01*fS0+fB1);
                    if (fTmpS1 < -m_rkSegment1.Extent)
                    {
                        fS1 = -m_rkSegment1.Extent;
                        fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                            fS0*(fS0+((Real)2.0)*fB0)+fC;
                    }
                    else if (fTmpS1 <= m_rkSegment1.Extent)
                    {
                        fS1 = fTmpS1;
                        fSqrDist = -fS1*fS1+fS0*(fS0+((Real)2.0)*fB0)
                            + fC;
                    }
                    else
                    {
                        fS1 = m_rkSegment1.Extent;
                        fSqrDist = fS1*(fS1-((Real)2.0)*fTmpS1) +
                            fS0*(fS0+((Real)2.0)*fB0)+fC;
                    }
                }
            }
        }
    }
    else
    {
        // segments are parallel
        Real fE0pE1 = m_rkSegment0.Extent + m_rkSegment1.Extent;
        Real fSign = (fA01 > (Real)0.0 ? (Real)-1.0 : (Real)1.0);
        Real fLambda = -fB0;
        if (fLambda < -fE0pE1)
        {
            fLambda = -fE0pE1;
        }
        else if (fLambda > fE0pE1)
        {
            fLambda = fE0pE1;
        }

        fS1 = fSign*fB0*m_rkSegment1.Extent/fE0pE1;
        fS0 = fLambda + fSign*fS1;
        fSqrDist = fLambda*(fLambda + ((Real)2.0)*fB0) + fC;
    }

    m_kClosestPoint0 = m_rkSegment0.Origin + fS0*m_rkSegment0.Direction;
    m_kClosestPoint1 = m_rkSegment1.Origin + fS1*m_rkSegment1.Direction;
    return Math<Real>::FAbs(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment2Segment2<Real>::Get (Real fS1,
    const Vector2<Real>& rkVelocity0, const Vector2<Real>& rkVelocity1)
{
    Vector2<Real> kMOrigin0 = m_rkSegment0.Origin + fS1*rkVelocity0;
    Vector2<Real> kMOrigin1 = m_rkSegment1.Origin + fS1*rkVelocity1;
    Segment2<Real> kMSegment0(kMOrigin0,m_rkSegment0.Direction,
        m_rkSegment0.Extent);
    Segment2<Real> kMSegment1(kMOrigin1,m_rkSegment1.Direction,
        m_rkSegment1.Extent);
    return DistSegment2Segment2<Real>(kMSegment0,kMSegment1).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistSegment2Segment2<Real>::GetSquared (Real fS1,
    const Vector2<Real>& rkVelocity0, const Vector2<Real>& rkVelocity1)
{
    Vector2<Real> kMOrigin0 = m_rkSegment0.Origin + fS1*rkVelocity0;
    Vector2<Real> kMOrigin1 = m_rkSegment1.Origin + fS1*rkVelocity1;
    Segment2<Real> kMSegment0(kMOrigin0,m_rkSegment0.Direction,
        m_rkSegment0.Extent);
    Segment2<Real> kMSegment1(kMOrigin1,m_rkSegment1.Direction,
        m_rkSegment1.Extent);
    return DistSegment2Segment2<Real>(kMSegment0,kMSegment1).GetSquared();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistSegment2Segment2<float>;

template WM4_FOUNDATION_ITEM
class DistSegment2Segment2<double>;
//----------------------------------------------------------------------------
}
