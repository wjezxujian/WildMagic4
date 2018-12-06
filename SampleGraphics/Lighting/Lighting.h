// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef LIGHTING_H
#define LIGHTING_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Lighting : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Lighting ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateLights ();
    void CreatePlane ();
    void CreateSphere ();
    void UpdateEffects ();

    NodePtr m_spkScene;
    TriMeshPtr m_spkPlane, m_spkSphere;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // L1     =   4 combinations
    // L2     =  10 combinations
    // L3     =  20 combinations
    // L4     =  35 combinations
    // L5     =  56 combinations
    // L6     =  84 combinations
    // L7     = 120 combinations
    // L8     = 165 combinations
    // Total  = 494 combinations
    int m_iAQuantity, m_iDQuantity, m_iPQuantity, m_iSQuantity;
    LightPtr m_aspkALight[8];
    LightPtr m_aspkDLight[8];
    LightPtr m_aspkPLight[8];
    LightPtr m_aspkSLight[8];

    DefaultShaderEffectPtr m_spkDefaultEffect;
    int m_iActiveLight;
    int m_iLightQuantity;
    char m_acCaption[9];
};

WM4_REGISTER_INITIALIZE(Lighting);

#endif
