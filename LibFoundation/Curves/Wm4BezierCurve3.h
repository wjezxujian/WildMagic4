// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BEZIERCURVE3_H
#define WM4BEZIERCURVE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4SingleCurve3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM BezierCurve3 : public SingleCurve3<Real>
{
public:
    // Construction and destruction.  BezierCurve3 accepts responsibility for
    // deleting the input arrays.
    BezierCurve3 (int iDegree, Vector3<Real>* akCtrlPoint);
    virtual ~BezierCurve3 ();

    int GetDegree () const;
    const Vector3<Real>* GetControlPoints () const;

    virtual Vector3<Real> GetPosition (Real fTime) const;
    virtual Vector3<Real> GetFirstDerivative (Real fTime) const;
    virtual Vector3<Real> GetSecondDerivative (Real fTime) const;
    virtual Vector3<Real> GetThirdDerivative (Real fTime) const;

    virtual Real GetVariation (Real fT0, Real fT1,
        const Vector3<Real>* pkP0 = 0, const Vector3<Real>* pkP1 = 0) const;

protected:
    int m_iDegree;
    int m_iNumCtrlPoints;
    Vector3<Real>* m_akCtrlPoint;
    Vector3<Real>* m_akDer1CtrlPoint;
    Vector3<Real>* m_akDer2CtrlPoint;
    Vector3<Real>* m_akDer3CtrlPoint;
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

typedef BezierCurve3<float> BezierCurve3f;
typedef BezierCurve3<double> BezierCurve3d;

}

#endif
