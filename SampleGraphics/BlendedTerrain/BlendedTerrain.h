// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BLENDEDTERRAIN_H
#define BLENDEDTERRAIN_H

#include "Wm4WindowApplication3.h"
#include "BlendedTerrainEffect.h"
using namespace Wm4;

//#define USE_BTEFFECT

class BlendedTerrain : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BlendedTerrain ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateSkyDome ();
    void CreateHeightField ();
    void UpdateClouds ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkHeightField, m_spkSkyDome;
    ImagePtr m_spkHeight, m_spkBlend;
    Culler m_kCuller;

    float m_fFlowDelta, m_fZAngle, m_fZDeltaAngle;

#ifdef USE_BTEFFECT
    BlendedTerrainEffectPtr m_spkEffect;
#else
    float m_afFlowDirection[4];
    float m_afPowerFactor[4];
#endif
};

WM4_REGISTER_INITIALIZE(BlendedTerrain);

#endif
