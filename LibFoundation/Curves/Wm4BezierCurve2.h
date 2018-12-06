// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BEZIERCURVE2_H
#define WM4BEZIERCURVE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4SingleCurve2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM BezierCurve2 : public SingleCurve2<Real>
{
public:
    // Construction and destruction.  BezierCurve2 accepts responsibility for
    // deleting the input array.
    BezierCurve2 (int iDegree, Vector2<Real>* akCtrlPoint);
    virtual ~BezierCurve2 ();

    int GetDegree () const;
    const Vector2<Real>* GetControlPoints () const;

    virtual Vector2<Real> GetPosition (Real fTime) const;
    virtual Vector2<Real> GetFirstDerivative (Real fTime) const;
    virtual Vector2<Real> GetSecondDerivative (Real fTime) const;
    virtual Vector2<Real> GetThirdDerivative (Real fTime) const;

    virtual Real GetVariation (Real fT0, Real fT1,
        const Vector2<Real>* pkP0 = 0, const Vector2<Real>* pkP1 = 0) const;

protected:
    int m_iDegree;
    int m_iNumCtrlPoints;
    Vector2<Real>* m_akCtrlPoint;
    Vector2<Real>* m_akDer1CtrlPoint;
    Vector2<Real>* m_akDer2CtrlPoint;
    Vector2<Real>* m_akDer3CtrlPoint;
    Real** m_aafChoose;

    // variation support
    int m_iTwoDegree;
    int m_iTwoDegreePlusOne;
    Real* m_afSigma;
    Real* m_afRecip;
    Real* m_afPowT0;
    Real* m_afPowOmT0;
    Real* m_afPowT1;
    Real* m_afPowOmT1;
};

typedef BezierCurve2<float> BezierCurve2f;
typedef BezierCurve2<double> BezierCurve2d;

}

#endif
