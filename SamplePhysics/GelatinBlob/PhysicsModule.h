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

#include "Wm4MassSpringArbitrary.h"

class PhysicsModule : public Wm4::MassSpringArbitrary3f
{
public:
    // construction and destruction
    PhysicsModule (int iNumParticles, int iNumSteps, float fStep,
        float fViscosity);

    virtual ~PhysicsModule ();

    // external acceleration is due to viscous forces
    virtual Wm4::Vector3f ExternalAcceleration (int i, float fTime,
        const Wm4::Vector3f* akPosition, const Wm4::Vector3f* akVelocity);

protected:
    float m_fViscosity;
};

#endif

