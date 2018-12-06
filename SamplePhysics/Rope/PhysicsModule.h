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

#include "Wm4MassSpringCurve.h"

class PhysicsModule : public Wm4::MassSpringCurve3f
{
public:
    // Construction and destruction.
    //
    // Gravity is controlled by the input rkGravity.
    //
    // Mass-spring systems tend to exhibit "stiffness" (in the sense of
    // numerical stability).  To remedy this problem, a small amount of
    // viscous friction is added to the external force.  This term is
    // of the form -fViscosity*velocity where fViscosity > 0.
    //
    // The initial wind force is specified by the caller.  The application
    // of wind can be enabled/disabled by EnableWind().  The member
    // function EnableWindChange() allows the wind direction to change
    // randomly, but each new direction is nearby the old direction in order
    // to obtain some sense of continuity of direction.  The magnitude of
    // the wind force is constant, the length of the initial force.

    PhysicsModule (int iNumParticles, float fStep,
        const Wm4::Vector3f& rkGravity, const Wm4::Vector3f& rkWind,
        float fWindChangeAmplitude, float fViscosity);

    bool& EnableWind ();
    bool& EnableWindChange ();

    // External acceleration is due to forces of gravitation, wind, and
    // viscous friction.  The wind forces are randomly generated.
    virtual Wm4::Vector3f ExternalAcceleration (int i, float fTime,
        const Wm4::Vector3f* akPosition, const Wm4::Vector3f* akVelocity);

protected:
    Wm4::Vector3f m_kGravity, m_kWind;
    float m_fViscosity, m_fWindChangeAmplitude;
    bool m_bEnableWind, m_bEnableWindChange;
};

#endif

