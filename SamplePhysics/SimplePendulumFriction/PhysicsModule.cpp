// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "PhysicsModule.h"
#include "Wm4Math.h"
#include "Wm4OdeRungeKutta4.h"
using namespace Wm4;

//----------------------------------------------------------------------------
PhysicsModule::PhysicsModule ()
{
    memset(m_adState,0,2*sizeof(double));
    memset(m_adAux,0,2*sizeof(double));
    m_pkSolver = 0;
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
    WM4_DELETE m_pkSolver;
}
//----------------------------------------------------------------------------
void PhysicsModule::Initialize (double dTime, double dDeltaTime,
    double dTheta, double dThetaDot)
{
    m_dTime = dTime;
    m_dDeltaTime = dDeltaTime;

    // state variables
    m_adState[0] = dTheta;
    m_adState[1] = dThetaDot;

    // auxiliary variables
    m_adAux[0] = GDivL;
    m_adAux[1] = CDivM;

    // RK4 differential equation solver.  Since m_pkSolver is a base class
    // pointer, you can instead create a solver of whatever class you prefer.
    WM4_DELETE m_pkSolver;
    m_pkSolver = WM4_NEW OdeRungeKutta4d(2,m_dDeltaTime,OdeFunction,m_adAux);
}
//----------------------------------------------------------------------------
void PhysicsModule::Update ()
{
    assert(m_pkSolver);
    if (!m_pkSolver)
    {
        return;
    }

    // take a single step in the ODE solver
    m_pkSolver->Update(m_dTime,m_adState,m_dTime,m_adState);
}
//----------------------------------------------------------------------------
void PhysicsModule::OdeFunction (double, const double* adState,
    void* pvData, double* adFValue)
{
    double* adAux = (double*)pvData;

    double dThetaDotFunction = -(adAux[0]*Mathd::Sin(adState[0]) +
        adAux[1]*adState[1]);

    // theta function
    adFValue[0] = adState[1];

    // dot(theta) function
    adFValue[1] = dThetaDotFunction;
}
//----------------------------------------------------------------------------

