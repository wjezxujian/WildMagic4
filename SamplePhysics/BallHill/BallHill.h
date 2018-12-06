// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BALLHILL_H
#define BALLHILL_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class BallHill : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BallHill ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    TriMesh* CreateGround ();
    TriMesh* CreateHill ();
    TriMesh* CreateBall ();
    Polyline* CreatePath ();
    void DoPhysical ();
    Vector3f UpdateBall ();

    // scene graph
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkBall;
    PolylinePtr m_spkPath;
    float m_fRadius;
    int m_iNextPoint;
    Culler m_kCuller;

    // physics
    PhysicsModule m_kModule;
};

WM4_REGISTER_INITIALIZE(BallHill);

#endif
