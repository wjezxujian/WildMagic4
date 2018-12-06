// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef FOUCAULTPENDULUM_H
#define FOUCAULTPENDULUM_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class FoucaultPendulum : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    FoucaultPendulum ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    TriMesh* CreateFloor ();
    Polypoint* CreatePath ();
    Node* CreatePendulum ();
    void DoPhysical ();

    // the scene graph
    NodePtr m_spkScene, m_spkPendulum;
    WireframeStatePtr m_spkWireframe;
    PolypointPtr m_spkPath;
    int m_iNextPoint;
    float m_fColorDiff;
    Culler m_kCuller;

    // physics
    PhysicsModule m_kModule;
};

WM4_REGISTER_INITIALIZE(FoucaultPendulum);

#endif

