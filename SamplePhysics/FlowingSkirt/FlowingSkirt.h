// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef FLOWINGSKIRT_H
#define FLOWINGSKIRT_H

#include "Wm4WindowApplication3.h"
#include "Wm4BSplineCurve3.h"
using namespace Wm4;

class FlowingSkirt : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    FlowingSkirt ();
    virtual ~FlowingSkirt ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateSkirt ();
    void UpdateSkirt ();
    void ModifyCurves ();

    // the scene graph
    NodePtr m_spkScene, m_spkTrnNode;
    TriMeshPtr m_spkSkirt;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // the skirt is a generalized Bezier cylinder
    int m_iNumCtrl, m_iDegree;
    float m_fATop, m_fBTop, m_fABot, m_fBBot;
    BSplineCurve3f* m_pkSkirtTop;
    BSplineCurve3f* m_pkSkirtBot;
    float* m_afFrequency;
};

WM4_REGISTER_INITIALIZE(FlowingSkirt);

#endif

