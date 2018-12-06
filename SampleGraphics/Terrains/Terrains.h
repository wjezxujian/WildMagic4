// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef TERRAINS_H
#define TERRAINS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Terrains : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Terrains ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateSkyDome ();
    void CreateTerrain ();

    // turret-based camera motion
    virtual void MoveForward ();
    virtual void MoveBackward ();
    virtual void MoveUp ();
    virtual void MoveDown ();

    NodePtr m_spkScene;
    TerrainPtr m_spkTerrain;
    TriMeshPtr m_spkSkyDome;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    float m_fUVBias;
    ColorRGB m_kFogColor;
    float m_fFogDensity;
    float m_fHeightAboveTerrain;
};

WM4_REGISTER_INITIALIZE(Terrains);

#endif
