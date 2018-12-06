// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef FREETOPFIXEDTIP_H
#define FREETOPFIXEDTIP_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class FreeTopFixedTip : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    FreeTopFixedTip ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // scene graph
    void CreateScene ();
    TriMesh* CreateFloor ();
    TriMesh* CreateTop ();
    Polyline* CreateAxisTop ();
    Polyline* CreateAxisVertical ();

    NodePtr m_spkScene, m_spkTopRoot;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
    float m_fMaxPhi;

    // physics
    void DoPhysical ();
    PhysicsModule m_kModule;

    // controlled frame rate
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(FreeTopFixedTip);

#endif

