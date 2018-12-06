// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTPBSPLINEUNIFORM1_H
#define WM4INTPBSPLINEUNIFORM1_H

#include "Wm4FoundationLIB.h"
#include "Wm4IntpBSplineUniform.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntpBSplineUniform1
    : public IntpBSplineUniform<Real>
{
public:
    // Construction.  IntpBSplineUniform1 accepts responsibility for
    // deleting the input array afData.
    IntpBSplineUniform1 (int iDegree, int iDim, Real* afData);

    // spline evaluation for function interpolation (no derivatives)
    Real operator() (Real fX);
    virtual Real operator() (Real* afX);

    // spline evaluation, derivative count given in iDx and aiDx[]
    Real operator() (int iDx, Real fX);
    virtual Real operator() (int* aiDx, Real* afX);

private:
    using IntpBSplineUniform<Real>::m_iDegree;
    using IntpBSplineUniform<Real>::m_afData;
    using IntpBSplineUniform<Real>::m_aiGridMin;
    using IntpBSplineUniform<Real>::m_aiGridMax;
    using IntpBSplineUniform<Real>::m_aiBase;
    using IntpBSplineUniform<Real>::m_aiOldBase;
    using IntpBSplineUniform<Real>::m_aafMatrix;
    using IntpBSplineUniform<Real>::m_afInter;
    using IntpBSplineUniform<Real>::m_aafPoly;
    using IntpBSplineUniform<Real>::m_oEvaluateCallback;

    void EvaluateUnknownData ();
    void ComputeIntermediate ();
};

typedef IntpBSplineUniform1<float> IntpBSplineUniform1f;
typedef IntpBSplineUniform1<double> IntpBSplineUniform1d;

}

#endif
