// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef GELATINCUBE_H
#define GELATINCUBE_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class GelatinCube : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GelatinCube ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // The masses are located at the control points of a spline surface.
    // The control points are connected in a mass-spring system.
    BSplineVolumef* m_pkSpline;
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSprings ();
    void CreateBox ();
    void CreateScene ();
    NodePtr m_spkScene, m_spkTrnNode;
    WireframeStatePtr m_spkWireframe;
    BoxSurfacePtr m_spkBox;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(GelatinCube);

#endif

