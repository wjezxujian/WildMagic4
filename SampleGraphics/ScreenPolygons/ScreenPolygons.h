// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SCREENPOLYGONS_H
#define SCREENPOLYGONS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ScreenPolygons : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ScreenPolygons ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();

    NodePtr m_spkScene;
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkForePoly, m_spkMidPoly, m_spkBackPoly;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    float m_fLinearZ, m_fDepthZ;
    double m_dAnimTime, m_dAnimTimeDelta;
};

WM4_REGISTER_INITIALIZE(ScreenPolygons);

#endif
