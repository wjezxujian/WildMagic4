// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WATERDROPFORMATION_H
#define WATERDROPFORMATION_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class WaterDropFormation : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    WaterDropFormation ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // scene graph
    void CreatePlane ();
    void CreateWall ();
    void CreateWaterRoot ();

    NodePtr m_spkScene, m_spkTrnNode, m_spkWaterRoot;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkPlane, m_spkWall;
    RevolutionSurfacePtr m_spkWaterSurface, m_spkWaterDrop;
    TextureEffectPtr m_spkWater;
    Culler m_kCuller;

    // water sphere curves and simulation parameters
    void Configuration0 ();  // water surface
    void Configuration1 ();  // split into water surface and water drop
    void DoPhysical1 ();
    void DoPhysical2 ();
    void DoPhysical3 ();
    void DoPhysical ();
    void DoVisual ();

    NURBSCurve2f* m_pkSpline;
    NURBSCurve2f* m_pkCircle;
    Vector2f* m_akCtrlPoint;
    Vector2f* m_akTarget;
    float m_fSimTime, m_fSimDelta, m_fLastSeconds;
};

WM4_REGISTER_INITIALIZE(WaterDropFormation);

#endif

