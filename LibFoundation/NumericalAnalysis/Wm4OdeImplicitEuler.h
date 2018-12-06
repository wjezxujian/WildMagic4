// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4ODEIMPLICITEULER_H
#define WM4ODEIMPLICITEULER_H

#include "Wm4FoundationLIB.h"
#include "Wm4OdeSolver.h"
#include "Wm4GMatrix.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM OdeImplicitEuler : public OdeSolver<Real>
{
public:
    // The function F(t,x) has input t, a scalar, and input x, an n-vector.
    // The first derivative matrix with respect to x is DF(t,x), an
    // n-by-n matrix.  Entry DF[r][c] is the derivative of F[r] with
    // respect to x[c].
    typedef void (*DerivativeFunction)(
        Real,             // t
        const Real*,      // x
        void*,            // user-specified data
        GMatrix<Real>&);  // DF(t,x)

    OdeImplicitEuler (int iDim, Real fStep,
        typename OdeSolver<Real>::Function oFunction,
        DerivativeFunction oDFunction, void* pvData = 0);

    virtual ~OdeImplicitEuler ();

    virtual void Update (Real fTIn, Real* afXIn, Real& rfTOut,
        Real* afXOut);

    virtual void SetStepSize (Real fStep);

protected:
    using OdeSolver<Real>::m_iDim;
    using OdeSolver<Real>::m_fStep;
    using OdeSolver<Real>::m_pvData;

    DerivativeFunction m_oDFunction;
    GMatrix<Real> m_kDF;
    GVector<Real> m_kF;
    GMatrix<Real> m_kIdentity;
};

typedef OdeImplicitEuler<float> OdeImplicitEulerf;
typedef OdeImplicitEuler<double> OdeImplicitEulerd;

}

#endif
