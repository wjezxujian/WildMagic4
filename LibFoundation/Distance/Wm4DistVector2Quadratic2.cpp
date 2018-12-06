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
#include "Wm4DistVector2Quadratic2.h"
#include "Wm4Eigen.h"
#include "Wm4PolynomialRoots.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistVector2Quadratic2<Real>::DistVector2Quadratic2 (
    const Vector2<Real>& rkVector, const Quadratic2<Real>& rkQuadratic)
    :
    m_rkVector(rkVector),
    m_rkQuadratic(rkQuadratic)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& DistVector2Quadratic2<Real>::GetVector () const
{
    return m_rkVector;
}
//----------------------------------------------------------------------------
template <class Real>
const Quadratic2<Real>& DistVector2Quadratic2<Real>::GetQuadratic () const
{
    return m_rkQuadratic;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector2Quadratic2<Real>::Get ()
{
    return Math<Real>::Sqrt(GetSquared());
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector2Quadratic2<Real>::GetSquared ()
{
    Eigen<Real> kES(2);
    kES(0,0) = m_rkQuadratic[3];
    kES(0,1) = ((Real)0.5)*m_rkQuadratic[4];
    kES(1,0) = kES(0,1);
    kES(1,1) = m_rkQuadratic[5];

    kES.IncrSortEigenStuff2();
    Vector2<Real> akEVec[2];
    kES.GetEigenvector(0,akEVec[0]);
    kES.GetEigenvector(1,akEVec[1]);

    Real afA[2], afB[2], afD[2], fC = m_rkQuadratic[0];
    int i;
    for (i = 0; i < 2; i++)
    {
        afA[i] = akEVec[i].X()*m_rkVector.X() + akEVec[i].Y()*m_rkVector.Y();
        afB[i] = akEVec[i].X()*m_rkQuadratic[1] +
            akEVec[i].Y()*m_rkQuadratic[2];
        afD[i] = kES.GetEigenvalue(i);
    }

    Polynomial1<Real> kPoly(4);
    ComputePoly(afA,afB,afD,fC,kPoly);

    PolynomialRoots<Real> kPR(Math<Real>::ZERO_TOLERANCE);
    kPR.FindB(kPoly,6);
    int iCount = kPR.GetCount();
    const Real* afRoot = kPR.GetRoots();

    if (iCount > 0)
    {
        Real fMinDistSqr = Math<Real>::MAX_REAL;
        int iMinIndex = -1;
        Real afV[2], fDenom;
        for (int iIndex = 0; iIndex < iCount; iIndex++)
        {
            // compute closest point for this root
            for (i = 0; i < 2; i++)
            {
                fDenom = (Real)1.0 + ((Real)2.0)*afRoot[iIndex]*afD[i];
                afV[i] = (afA[i]-afRoot[iIndex]*afB[i])/fDenom;
            }

            m_kClosestPoint1.X() = akEVec[0][0]*afV[0] + akEVec[1][0]*afV[1];
            m_kClosestPoint1.Y() = akEVec[0][1]*afV[0] + akEVec[1][1]*afV[1];

            // compute squared distance from point to quadratic
            Vector2<Real> kDiff = m_kClosestPoint1 - m_rkVector;
            Real fDistSqr = kDiff.SquaredLength();
            if (fDistSqr < fMinDistSqr)
            {
                fMinDistSqr = fDistSqr;
                iMinIndex = iIndex;
            }
        }

        for (i = 0; i < 2; i++)
        {
            fDenom = (Real)1.0 + ((Real)2.0)*afRoot[iMinIndex]*afD[i];
            afV[i] = (afA[i]-afRoot[iMinIndex]*afB[i])/fDenom;
        }

        m_kClosestPoint0 = m_rkVector;
        m_kClosestPoint1.X() = akEVec[0][0]*afV[0] + akEVec[1][0]*afV[1];
        m_kClosestPoint1.Y() = akEVec[0][1]*afV[0] + akEVec[1][1]*afV[1];
        return fMinDistSqr;
    }
    else
    {
        assert(false);
        return -(Real)1.0;
    }
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector2Quadratic2<Real>::Get (Real fT,
    const Vector2<Real>& rkVelocity0, const Vector2<Real>& rkVelocity1)
{
    Vector2<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Quadratic2<Real> kMQuadratic = m_rkQuadratic.Translate(fT*rkVelocity1);
    return DistVector2Quadratic2<Real>(kMVector,kMQuadratic).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector2Quadratic2<Real>::GetSquared (Real fT,
    const Vector2<Real>& rkVelocity0, const Vector2<Real>& rkVelocity1)
{
    Vector2<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Quadratic2<Real> kMQuadratic = m_rkQuadratic.Translate(fT*rkVelocity1);
    return DistVector2Quadratic2<Real>(kMVector,kMQuadratic).GetSquared();
}
//----------------------------------------------------------------------------
template <class Real>
void DistVector2Quadratic2<Real>::ComputePoly (Real afA[2], Real afB[2],
    Real afD[2], Real fC, Polynomial1<Real>& rkPoly)
{
    Real afBPad[2] = { afB[0]+afA[0]*afD[0], afB[1]+afA[1]*afD[1] };
    Real afBSqr[2] = { afB[0]*afB[0], afB[1]*afB[1] };
    Real afDSqr[2] = { afD[0]*afD[0], afD[1]*afD[1] };
    Real fDPrd = afD[0]*afD[1];
    Real fDSum = afD[0]+afD[1];

    rkPoly[0] = afA[0]*afBPad[0]+afA[1]*afBPad[1]+fC;
    rkPoly[1] = -afBSqr[0]-afBSqr[1]+((Real)4.0)*(afA[0]*afD[1]*afBPad[0]+
        afA[1]*afD[0]*afBPad[1]+fC*fDSum);
    rkPoly[2] = -afBSqr[0]*(afD[0]+((Real)4.0)*afD[1])-afBSqr[1]*(afD[1]+
        ((Real)4.0)*afD[0])+((Real)4.0)*(afA[0]*afDSqr[1]*afBPad[0]+
        afA[1]*afDSqr[0]*afBPad[1]+fC*(afDSqr[0]+afDSqr[1]+
        ((Real)4.0)*fDPrd));

    Real fTmp = -((Real)4.0)*(afBSqr[0]*afD[1]+afBSqr[1]*afD[0]-
        ((Real)4.0)*fC*fDPrd);
    rkPoly[3] = fDSum*fTmp;
    rkPoly[4] = fDPrd*fTmp;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistVector2Quadratic2<float>;

template WM4_FOUNDATION_ITEM
class DistVector2Quadratic2<double>;
//----------------------------------------------------------------------------
}
