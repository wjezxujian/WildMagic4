// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef HELIXTUBESURFACE_H
#define HELIXTUBESURFACE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class HelixTubeSurface : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    HelixTubeSurface ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);

protected:
    MultipleCurve3f* CreateCurve ();
    static float Radial (float fT);
    virtual bool MoveCamera ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
    MultipleCurve3f* m_pkCurve;
    float m_fMinCurveTime, m_fMaxCurveTime, m_fCurvePeriod;
    float m_fCurveTime, m_fDeltaTime;
};

WM4_REGISTER_INITIALIZE(HelixTubeSurface);

#endif

