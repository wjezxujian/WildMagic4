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
#include "Wm4IntrLinComp2LinComp2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrLinComp2LinComp2<Real>::IntrLinComp2LinComp2 (
    const LinComp2<Real>& rkComponent0, const LinComp2<Real>& rkComponent1)
    :
    m_rkComponent0(rkComponent0),
    m_rkComponent1(rkComponent1)
{
}
//----------------------------------------------------------------------------
template <class Real>
const LinComp2<Real>& IntrLinComp2LinComp2<Real>::GetComponent0 ()
    const
{
    return m_rkComponent0;
}
//----------------------------------------------------------------------------
template <class Real>
const LinComp2<Real>& IntrLinComp2LinComp2<Real>::GetComponent1 ()
    const
{
    return m_rkComponent1;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrLinComp2LinComp2<Real>::Test ()
{
    Vector2<Real> kDiff;
    m_iIntersectionType = Classify(m_rkComponent0,m_rkComponent1,
        m_afParameter,&kDiff);

    if (m_iIntersectionType == IT_POINT)
    {
        // The lines of the components intersect in a single point.  Test if
        // that point is on both components.
        if (!m_rkComponent0.Contains(m_afParameter[0])
        ||  !m_rkComponent1.Contains(m_afParameter[1]))
        {
            m_iIntersectionType = IT_EMPTY;
        }
    }
    else if (m_iIntersectionType == IT_LINE)
    {
        // The components are on the same line.  Test for overlap of the
        // components.
        Real fOrigin1 = kDiff.Dot(m_rkComponent0.Direction);
        Real fSign = m_rkComponent0.Direction.Dot(m_rkComponent1.Direction);
        Real fMin1, fMax1;
        if (fSign > (Real)0.0)
        {
            // components are in the same direction
            fMin1 = fOrigin1 + m_rkComponent1.GetMin();
            fMax1 = fOrigin1 + m_rkComponent1.GetMax();
        }
        else
        {
            // components are in opposite directions
            fMin1 = fOrigin1 - m_rkComponent1.GetMax();
            fMax1 = fOrigin1 - m_rkComponent1.GetMin();
        }

        Intersector1<Real> kIntr(m_rkComponent0.GetMin(),
            m_rkComponent0.GetMax(),fMin1,fMax1);

        kIntr.Find();

        int iQuantity = kIntr.GetQuantity();
        if (iQuantity == 2)
        {
            m_iIntersectionType = LinComp2<Real>::GetTypeFromInterval(
                kIntr.GetOverlap(0),kIntr.GetOverlap(1));
        }
        else if (iQuantity == 1)
        {
            m_iIntersectionType = IT_POINT;
        }
        else
        {
            m_iIntersectionType = IT_EMPTY;
        }
    }

    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrLinComp2LinComp2<Real>::Find ()
{
    Vector2<Real> kDiff;
    m_iIntersectionType = Classify(m_rkComponent0,m_rkComponent1,
        m_afParameter,&kDiff);

    if (m_iIntersectionType == IT_POINT)
    {
        // The lines of the components intersect in a single point.  Test if
        // that point is on both components.
        if (m_rkComponent0.Contains(m_afParameter[0])
        &&  m_rkComponent1.Contains(m_afParameter[1]))
        {
            // point
            m_kIntrComponent.Origin = m_rkComponent0.Origin;
            m_kIntrComponent.Direction = m_rkComponent0.Direction;
            m_kIntrComponent.SetInterval(m_afParameter[0],m_afParameter[0]);
        }
        else
        {
            // empty set
            m_kIntrComponent.SetInterval((Real)1.0,(Real)-1.0);
        }
    }
    else if (m_iIntersectionType == IT_LINE)
    {
        // The components are on the same line.  Test for overlap of the
        // components.
        Real fOrigin1 = kDiff.Dot(m_rkComponent0.Direction);
        Real fSign = m_rkComponent0.Direction.Dot(m_rkComponent1.Direction);
        Real fMin1, fMax1;
        if (fSign > (Real)0.0)
        {
            // components are in the same direction
            fMin1 = fOrigin1 + m_rkComponent1.GetMin();
            fMax1 = fOrigin1 + m_rkComponent1.GetMax();
        }
        else
        {
            // components are in opposite directions
            fMin1 = fOrigin1 - m_rkComponent1.GetMax();
            fMax1 = fOrigin1 - m_rkComponent1.GetMin();
        }

        Intersector1<Real> kIntr(m_rkComponent0.GetMin(),
            m_rkComponent0.GetMax(),fMin1,fMax1);

        kIntr.Find();

        int iQuantity = kIntr.GetQuantity();
        if (iQuantity == 2)
        {
            // line, ray, or segment
            m_kIntrComponent.Origin = m_rkComponent0.Origin;
            m_kIntrComponent.Direction = m_rkComponent0.Direction;
            m_kIntrComponent.SetInterval(kIntr.GetOverlap(0),
                kIntr.GetOverlap(1));
        }
        else if (iQuantity == 1)
        {
            // point
            m_kIntrComponent.Origin = m_rkComponent0.Origin;
            m_kIntrComponent.Direction = m_rkComponent0.Direction;
            m_kIntrComponent.SetInterval(m_afParameter[0],m_afParameter[0]);
        }
        else
        {
            // empty set
            m_kIntrComponent.SetInterval((Real)1.0,(Real)-1.0);
        }
    }

    m_kIntrComponent.MakeCanonical();
    m_iIntersectionType = m_kIntrComponent.GetType();
    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
const LinComp2<Real>&
IntrLinComp2LinComp2<Real>::GetIntersectionComponent () const
{
    return m_kIntrComponent;
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrLinComp2LinComp2<Real>::GetParameter0 () const
{
    return m_afParameter[0];
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrLinComp2LinComp2<Real>::GetParameter1 () const
{
    return m_afParameter[1];
}
//----------------------------------------------------------------------------
template <class Real>
int IntrLinComp2LinComp2<Real>::Classify (const LinComp2<Real>& rkComponent0,
    const LinComp2<Real>& rkComponent1, Real* afS, Vector2<Real>* pkDiff,
    Vector2<Real>* pkDiffN)
{
    // The intersection of two lines is a solution to P0+s0*D0 = P1+s1*D1.
    // Rewrite this as s0*D0 - s1*D1 = P1 - P0 = Q.  If D0.Dot(Perp(D1)) = 0,
    // the lines are parallel.  Additionally, if Q.Dot(Perp(D1)) = 0, the
    // lines are the same.  If D0.Dot(Perp(D1)) is not zero, then
    //   s0 = Q.Dot(Perp(D1))/D0.Dot(Perp(D1))
    // produces the point of intersection.  Also,
    //   s1 = Q.Dot(Perp(D0))/D0.Dot(Perp(D1))

    Vector2<Real> kDiff = rkComponent1.Origin - rkComponent0.Origin;
    if (pkDiff)
    {
        *pkDiff = kDiff;
    }

    Real fD0DotPerpD1 =
        rkComponent0.Direction.DotPerp(rkComponent1.Direction);
    if (Math<Real>::FAbs(fD0DotPerpD1) > Math<Real>::ZERO_TOLERANCE)
    {
        // lines intersect in a single point
        if (afS)
        {
            Real fInvD0DotPerpD1 = ((Real)1.0)/fD0DotPerpD1;
            Real fDiffDotPerpD0 = kDiff.DotPerp(rkComponent0.Direction);
            Real fDiffDotPerpD1 = kDiff.DotPerp(rkComponent1.Direction);
            afS[0] = fDiffDotPerpD1*fInvD0DotPerpD1;
            afS[1] = fDiffDotPerpD0*fInvD0DotPerpD1;
        }
        return IT_POINT;
    }

    // lines are parallel
    kDiff.Normalize();
    if (pkDiffN)
    {
        *pkDiffN = kDiff;
    }

    Real fDiffNDotPerpD1 = kDiff.DotPerp(rkComponent1.Direction);
    if (Math<Real>::FAbs(fDiffNDotPerpD1) <= Math<Real>::ZERO_TOLERANCE)
    {
        // lines are colinear
        return IT_LINE;
    }

    // lines are parallel, but distinct
    return IT_EMPTY;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrLinComp2LinComp2<float>;

template WM4_FOUNDATION_ITEM
class IntrLinComp2LinComp2<double>;
//----------------------------------------------------------------------------
}
