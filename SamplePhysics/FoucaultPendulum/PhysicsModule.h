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
#include "Wm4Matrix3.h"

class PhysicsModule
{
public:
    // construction and destruction
    PhysicsModule ();
    ~PhysicsModule ();

    // initialize the differential equation solver
    void Initialize (double dTime, double dDeltaTime, double dTheta,
        double dPhi, double dThetaDot, double dPhiDot);

    double GetTime () const;
    double GetDeltaTime () const;
    double GetTheta () const;
    double GetThetaDot () const;
    double GetPhi () const;
    double GetPhiDot () const;

    // the orientation of the pendulum
    Wm4::Matrix3f GetOrientation () const;

    // take a single step of the solver
    void Update ();

    // pendulum parameters
    double AngularSpeed;  // w
    double Latitude;  // lat
    double GDivL;  // g/L

private:
    // state and auxiliary variables
    double m_dTime, m_dDeltaTime, m_adState[4], m_adAux[3];

    // ODE solver (specific solver assigned in the cpp file)
    Wm4::OdeSolverd* m_pkSolver;
    static void OdeFunction (double dTime, const double* adState,
        void* pvData, double* adFValue);
};

#include "PhysicsModule.inl"

#endif

