// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SHADOWMAPS_H
#define SHADOWMAPS_H

#include "Wm4WindowApplication3.h"
#include "ShadowMapEffect.h"
using namespace Wm4;

class ShadowMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ShadowMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateGround ();
    void CreateTorus ();
    void CreateGlobe ();
    void CreateFlashlight ();

    NodePtr m_spkScene, m_spkShadowMapNode, m_spkFlashlight;
    TriMeshPtr m_spkGround, m_spkTorus, m_spkGlobe, m_spkLightSphere;
    LightPtr m_spkLight;
    WireframeStatePtr m_spkWireframe;
    ShadowMapEffectPtr m_spkSMEffect;
    Culler m_kCuller;

    char* m_acCaption;
    static char* ms_aacCaptions[3];
};

WM4_REGISTER_INITIALIZE(ShadowMaps);

#endif
