// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef ROPE_H
#define ROPE_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;


class Rope : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Rope ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // The masses are located at the control points of a spline curve.  The
    // control points are connected by a mass-spring system.
    BSplineCurve3f* m_pkSpline;
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSprings ();
    void CreateRope ();
    void CreateScene ();
    static float Radial (float) { return 0.025f; }
    NodePtr m_spkScene, m_spkTrnNode;
    WireframeStatePtr m_spkWireframe;
    TubeSurfacePtr m_spkRope;
    Culler m_kCuller;

    // controlled frame rate
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(Rope);

#endif

