// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PLANARSHADOWS_H
#define PLANARSHADOWS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class PlanarShadows : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    PlanarShadows ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void LoadBiped ();
    void CreatePlanes ();
    void CreatePlanarShadow ();

    NodePtr m_spkScene, m_spkBiped;
    TriMeshPtr m_spkPlane0, m_spkPlane1;
    LightNodePtr m_spkProjectorNode;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    double m_dUpdateTime;
};

WM4_REGISTER_INITIALIZE(PlanarShadows);

#endif
