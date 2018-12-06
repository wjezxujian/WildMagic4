// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RUNGEKUTTA4_H
#define WM4RUNGEKUTTA4_H

#include "Wm4FoundationLIB.h"
#include "Wm4OdeSolver.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM OdeRungeKutta4 : public OdeSolver<Real>
{
public:
    OdeRungeKutta4 (int iDim, Real fStep,
        typename OdeSolver<Real>::Function oFunction, void* pvData = 0);

    virtual ~OdeRungeKutta4 ();

    virtual void Update (Real fTIn, Real* afXIn, Real& rfTOut,
        Real* afXOut);

    virtual void SetStepSize (Real fStep);

protected:
    using OdeSolver<Real>::m_iDim;
    using OdeSolver<Real>::m_fStep;
    using OdeSolver<Real>::m_pvData;
    using OdeSolver<Real>::m_afFValue;

    Real m_fHalfStep, m_fSixthStep;
    Real* m_afTemp1;
    Real* m_afTemp2;
    Real* m_afTemp3;
    Real* m_afTemp4;
    Real* m_afXTemp;
};

typedef OdeRungeKutta4<float> OdeRungeKutta4f;
typedef OdeRungeKutta4<double> OdeRungeKutta4d;

}

#endif
