// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "Wm4OdeSolver.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dTheta,
        double dThetaDot);

    // take a single step of the solver
    void Update ();

    // get the current pendulum angle
    double GetTime () const;
    double GetDeltaTime () const;
    double GetTheta () const;
    double GetThetaDot () const;

    // pendulum parameters
    double CDivM;  // friction_coefficient / mass
    double GDivL;  // gravity_constant / pendulum_length

private:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime;
    double m_adState[2], m_adAux[2];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif

