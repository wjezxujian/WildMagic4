// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef ROUGHPLANESOLIDBOX_H
#define ROUGHPLANESOLIDBOX_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class RoughPlaneSolidBox : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RoughPlaneSolidBox ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    Node* CreateBox ();
    TriMesh* CreateRamp ();
    TriMesh* CreateGround();
    void InitializeModule ();
    void MoveBox ();
    void DoPhysical ();

    NodePtr m_spkScene, m_spkBox;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    PhysicsModule m_kModule;
    bool m_bDoUpdate;
};

WM4_REGISTER_INITIALIZE(RoughPlaneSolidBox);

#endif

