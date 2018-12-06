// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef ROUGHPLANEPARTICLE1_H
#define ROUGHPLANEPARTICLE1_H

#include "Wm4WindowApplication2.h"
#include "PhysicsModule.h"
using namespace Wm4;

class RoughPlaneParticle1 : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    RoughPlaneParticle1 ();

    virtual bool OnInitialize ();
    virtual void OnIdle ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    PhysicsModule m_kModule;
    std::vector<Vector2d> m_kSFPosition;  // path with static friction
    bool m_bContinueSolving;

    // viscous solution:
    //   x(t) = a0*exp(-r*t)+a1
    //   w(t) = b0*exp(-r*t)+b1*t+b2
    //   r = c/m
    //   a0 = -xdot(0)/r
    //   a1 = x(0)-a0
    //   b1 = -g*sin(phi)/r
    //   b2 = (wdot(0)+r*w(0)-b1)/r
    //   b0 = w(0)-b2
    Vector2d GetVFPosition (double dTime);
    double m_dR, m_dA0, m_dA1, m_dB0, m_dB1, m_dB2;
    std::vector<Vector2d> m_kVFPosition;  // path with viscous friction
};

WM4_REGISTER_INITIALIZE(RoughPlaneParticle1);

#endif

