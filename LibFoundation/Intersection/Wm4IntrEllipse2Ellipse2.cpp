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
#include "Wm4IntrEllipse2Ellipse2.h"
#include "Wm4PolynomialRoots.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrEllipse2Ellipse2<Real>::IntrEllipse2Ellipse2 (
    const Ellipse2<Real>& rkEllipse0, const Ellipse2<Real>& rkEllipse1)
    :
    m_rkEllipse0(rkEllipse0),
    m_rkEllipse1(rkEllipse1)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Ellipse2<Real>& IntrEllipse2Ellipse2<Real>::GetEllipse0 () const
{
    return m_rkEllipse0;
}
//----------------------------------------------------------------------------
template <class Real>
const Ellipse2<Real>& IntrEllipse2Ellipse2<Real>::GetEllipse1 () const
{
    return m_rkEllipse1;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrEllipse2Ellipse2<Real>::Test ()
{
    return Find();
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrEllipse2Ellipse2<Real>::Find ()
{
    m_iQuantity = 0;

    Ellipse2<Real> kScaled0, kScaled1;
    Vector2<Real> kTranslate;
    Real fScale;
    ScaleEllipses(kScaled0,kScaled1,kTranslate,fScale);

    Polynomial1<Real> kPoly = GetQuartic(kScaled0,kScaled1);
    if (kPoly.GetDegree() == -1)
    {
        m_iIntersectionType = IT_OTHER;
        return true;
    }

    // Get the 4th-degree polynomial whose roots lead to intersections of the
    // ellipses.  The y-values are in the interval [-1,1], so we only need
    // to locate roots there.  The increase to [-1.5,1.5] is to catch roots
    // that are nearly 1 or -1 without having to worry about floating point
    // round-off errors.
    PolynomialRoots<Real> kPR(Math<Real>::ZERO_TOLERANCE);
    kPR.FindB(kPoly,-(Real)1.5,(Real)1.5,6);
    int iYCount = kPR.GetCount();
    const Real* afY = kPR.GetRoots();
    if (iYCount == 0)
    {
        m_iIntersectionType = IT_EMPTY;
        return false;
    }

    // Adjustment for quadratics to allow for relative error testing when
    // eliminating extraneous roots.
    Real afQP0[6], afQP1[6];
    kScaled0.ToCoefficients(afQP0);
    kScaled1.ToCoefficients(afQP1);
    Real fNorm0 = afQP0[0]*afQP0[0] + ((Real)2.0)*afQP0[1]*afQP0[1] +
        afQP0[2]*afQP0[2];
    Real fNorm1 = afQP1[0]*afQP1[0] + ((Real)2.0)*afQP1[1]*afQP1[1] +
        afQP1[2]*afQP1[2];

    // test roots to eliminate extraneous ones that occurred due to "squaring"
    for (int iY = 0; iY < iYCount; iY++)
    {
        PolynomialRoots<Real> kAR(Math<Real>::ZERO_TOLERANCE);
        Polynomial1<Real> kAPoly(2);
        kAPoly[0] = afQP0[0]+afY[iY]*(afQP0[2]+afY[iY]*afQP0[5]);
        kAPoly[1] = afQP0[1]+afY[iY]*afQP0[4];
        kAPoly[2] = afQP0[3];
        kAR.FindB(kAPoly,6);
        int iXCount = kAR.GetCount();
        const Real* afX = kAR.GetRoots();
        for (int iX = 0; iX < iXCount; iX++)
        {
            const Real fEpsilon = (Real)1e-03;
            Real fTest = EvaluateQuadratic(afQP0,afX[iX],afY[iY]);
            if (Math<Real>::FAbs(fTest) < fEpsilon*fNorm0)
            {
                fTest = EvaluateQuadratic(afQP1,afX[iX],afY[iY]);
                if (Math<Real>::FAbs(fTest) < fEpsilon*fNorm1)
                {
                    m_akPoint[m_iQuantity].X() = afX[iX];
                    m_akPoint[m_iQuantity].Y() = afY[iY];
                    m_iQuantity++;
                }
            }
        }
    }

    if (m_iQuantity == 0)
    {
        m_iIntersectionType = IT_EMPTY;
        return false;
    }

    // map intersections back to original space
    for (int i = 0; i < m_iQuantity; i++)
    {
        m_akPoint[i] = m_akPoint[i]/fScale + kTranslate;
    }

    m_iIntersectionType = IT_POINT;
    return true;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrEllipse2Ellipse2<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& IntrEllipse2Ellipse2<Real>::GetPoint (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------
template <class Real>
const Ellipse2<Real>& IntrEllipse2Ellipse2<Real>::GetIntersectionEllipse ()
    const
{
    return m_rkEllipse0;
}
//----------------------------------------------------------------------------
template <class Real>
void IntrEllipse2Ellipse2<Real>::GetAABB (const Ellipse2<Real>& rkEllipse,
    Real& rfXMin, Real& rfXMax, Real& rfYMin, Real& rfYMax)
{
    Real fXExtreme =
        rkEllipse.Extent[0]*Math<Real>::FAbs(rkEllipse.Axis[0].X()) +
        rkEllipse.Extent[1]*Math<Real>::FAbs(rkEllipse.Axis[1].X());
    rfXMin = rkEllipse.Center.X() - fXExtreme;
    rfXMax = rkEllipse.Center.X() + fXExtreme;

    Real fYExtreme =
        rkEllipse.Extent[0]*Math<Real>::FAbs(rkEllipse.Axis[0].Y()) +
        rkEllipse.Extent[1]*Math<Real>::FAbs(rkEllipse.Axis[1].Y());
    rfYMin = rkEllipse.Center.Y() - fYExtreme;
    rfYMax = rkEllipse.Center.Y() + fYExtreme;
}
//----------------------------------------------------------------------------
template <class Real>
Polynomial1<Real> IntrEllipse2Ellipse2<Real>::GetQuartic (
    const Ellipse2<Real>& rkEllipse0, const Ellipse2<Real>& rkEllipse1)
{
    Real afP0[6], afP1[6];
    rkEllipse0.ToCoefficients(afP0);
    rkEllipse1.ToCoefficients(afP1);

    // The polynomials are
    //   P0 = a0 + a1*x + a2*y + a3*x^2 + a4*x*y + a5*y^2
    //      = (a0 + a2*y + a5*y^2) + (a1 + a4*y)*x + (a3)*x^2
    //      = u0(y) + u1(y)*x + u2(y)*x^2
    //   P1 = b0 + b1*x + b2*y + b3*x^2 + b4*x*y + b5*y^2
    //      = (b0 + b2*y + b5*y^2) + (b1 + b4*y)*x + (b3)*x^2
    //      = v0(y) + v1(y)*x + v2(y)*x^2
    // The Bezout determinant eliminates the variable x when solving the
    // equations P0(x,y) = 0 and P1(x,y) = 0.  We have
    //   0 = P0 = u0 + u1*x + u2*x^2
    //   0 = P1 = v0 + v1*x + v2*x^2
    //   0 = v2*P0 - u2*P1 = (u0*v2 - u2*v0) + (u1*v2 - u2*v1)*x
    //   0 = v1*P0 - u1*P1 = (u0*v1 - u1*v0) + (u2*v1 - u1*v2)*x^2
    // Solve the equation 0 = v2*P0-u2*P1 for x and substitute in the other
    // equation and simplify to
    //   Q(y) = (u0*v1-v1*u0)*(u1*v2-u2*v1) - (u0*v2-u2*v0)^2 = 0
    //        = c0 + c1*y + c2*y^2 + c3*y^3 + c4*y^4
    // Define dij = ai*bj - aj*bi for various indices i and j.  For example,
    // d01 = a0*b1-b1*a0.  The coefficients of Q(y) are
    //   c0 = d01*d13 - d30^2
    //   c1 = d01*d43 + (d04+d21)*d13 - 2*d30*d32
    //   c2 = (d04+d21)*d43 + (d24+d51)*d13 - 2*d30*d35 - d32^2
    //   c3 = (d24+d51)*d43 + d54*d13 - 2*d32*d35
    //   c4 = d54*d43 - d35^2

    Real fD01 = afP0[0]*afP1[1] - afP0[1]*afP1[0];
    Real fD04 = afP0[0]*afP1[4] - afP0[4]*afP1[0];
    Real fD13 = afP0[1]*afP1[3] - afP0[3]*afP1[1];
    Real fD21 = afP0[2]*afP1[1] - afP0[1]*afP1[2];
    Real fD24 = afP0[2]*afP1[4] - afP0[4]*afP1[2];
    Real fD30 = afP0[3]*afP1[0] - afP0[0]*afP1[3];
    Real fD32 = afP0[3]*afP1[2] - afP0[2]*afP1[3];
    Real fD35 = afP0[3]*afP1[5] - afP0[5]*afP1[3];
    Real fD43 = afP0[4]*afP1[3] - afP0[3]*afP1[4];
    Real fD51 = afP0[5]*afP1[1] - afP0[1]*afP1[5];
    Real fD54 = afP0[5]*afP1[4] - afP0[4]*afP1[5];
    Real fD04p21 = fD04+fD21;
    Real fD24p51 = fD24+fD51;

    Real afCoeff[5];
    afCoeff[0] = fD01*fD13-fD30*fD30;
    afCoeff[1] = fD01*fD43+fD04p21*fD13-((Real)2.0)*fD30*fD32;
    afCoeff[2] = fD04p21*fD43+fD24p51*fD13-((Real)2.0)*fD30*fD35-fD32*fD32;
    afCoeff[3] = fD24p51*fD43+fD54*fD13-((Real)2.0)*fD32*fD35;
    afCoeff[4] = fD54*fD43-fD35*fD35;

    // reduce degree if necessary
    int iDegree = 4;
    while (iDegree >= 0
    && Math<Real>::FAbs(afCoeff[iDegree]) < Math<Real>::ZERO_TOLERANCE)
    {
        iDegree--;
    }

    if (iDegree == -1)
    {
        return Polynomial1<Real>();
    }

    Polynomial1<Real> kPoly(iDegree);
    size_t uiSize = (iDegree+1)*sizeof(Real);
    System::Memcpy(&kPoly[0],uiSize,afCoeff,uiSize);
    return kPoly;
}
//----------------------------------------------------------------------------
template <class Real>
void IntrEllipse2Ellipse2<Real>::ScaleEllipses (Ellipse2<Real>& rkScaled0,
    Ellipse2<Real>& rkScaled1, Vector2<Real>& rkTranslate, Real& rfScale)
{
    // The ellipse E[i] is contained in the oriented rectangle with vertices
    //   C[i] + s0*e0[i][0]*A0[i] + s1*e1[i][1]*A1[i]
    // where C[i] is the ellipse center, A0[i] and A1[i] are the ellipse
    // unit-length axis directions, e0[i] and e1[i] are the ellipse extents,
    // and |s0| = 1 and |s1| = 1 (four choices).  The implementation for
    // finding intersections first computes the smallest axis-aligned
    // rectangle that contains the oriented rectangles of the ellipses.  The
    // bounding rectangle is mapped to the square [-1,1]^2.  This portion of
    // the algorithm is designed to help keep the floating point calculations
    // robust in the root finding.

    // construct axis-aligned bounding rectangle for E0
    Real fXMin0, fXMax0, fYMin0, fYMax0;
    GetAABB(m_rkEllipse0,fXMin0,fXMax0,fYMin0,fYMax0);

    // construct axis-aligned bounding rectangle for E1
    Real fXMin1, fXMax1, fYMin1, fYMax1;
    GetAABB(m_rkEllipse1,fXMin1,fXMax1,fYMin1,fYMax1);

    // construct axis-aligned bounding square of rectangle rectangles
    Real fXMin2 = (fXMin0 <= fXMin1 ? fXMin0 : fXMin1);
    Real fXMax2 = (fXMax0 >= fXMax1 ? fXMax0 : fXMax1);
    Real fYMin2 = (fYMin0 <= fYMin1 ? fYMin0 : fYMin1);
    Real fYMax2 = (fYMax0 >= fYMax1 ? fYMax0 : fYMax1);
    Real fDX = fXMax2 - fXMin2;
    Real fDY = fYMax2 - fYMin2;

    // translation and scaling to map ellipses into [-1,1]^2
    rkTranslate.X() = ((Real)0.5)*(fXMin2 + fXMax2);
    rkTranslate.Y() = ((Real)0.5)*(fYMin2 + fYMax2);
    rfScale = (fDX >= fDY ? ((Real)2.0)/fDX : ((Real)2.0)/fDY);

    // map ellipses to [-1,1]^2
    rkScaled0.Center = rfScale*(m_rkEllipse0.Center - rkTranslate);
    rkScaled1.Center = rfScale*(m_rkEllipse1.Center - rkTranslate);
    rkScaled0.Extent[0] = rfScale*m_rkEllipse0.Extent[0];
    rkScaled0.Extent[1] = rfScale*m_rkEllipse0.Extent[1];
    rkScaled1.Extent[0] = rfScale*m_rkEllipse1.Extent[0];
    rkScaled1.Extent[1] = rfScale*m_rkEllipse1.Extent[1];
    rkScaled0.Axis[0] = m_rkEllipse0.Axis[0];
    rkScaled0.Axis[1] = m_rkEllipse0.Axis[1];
    rkScaled1.Axis[0] = m_rkEllipse1.Axis[0];
    rkScaled1.Axis[1] = m_rkEllipse1.Axis[1];
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrEllipse2Ellipse2<Real>::EvaluateQuadratic (const Real afQP[6],
    Real fX, Real fY)
{
    return (afQP[0] + fY*(afQP[2] + fY*afQP[5])) +
        fX*((afQP[1] + fY*afQP[4]) + fX*afQP[3]);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrEllipse2Ellipse2<float>;

template WM4_FOUNDATION_ITEM
class IntrEllipse2Ellipse2<double>;
//----------------------------------------------------------------------------
}
