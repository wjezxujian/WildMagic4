// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RIPPLINGOCEAN_H
#define RIPPLINGOCEAN_H

#include "Wm4WindowApplication3.h"
#include "RipplingOceanEffect.h"
using namespace Wm4;

class RipplingOcean : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RipplingOcean ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateNormalMapFromHeightImage (const char* acImageName);

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    RipplingOceanEffectPtr m_spkEffect;
    ImagePtr m_spkNormalMap;
    Culler m_kCuller;

    // Time information.
    bool m_bStopped;
    float m_fStopTime;

    // Wave information.
    float m_fWaveSpeedAmplitude;
    float m_fWaveHeightAmplitude;
    float m_fBumpSpeedAmplitude;
    float m_afWaveSpeed[4];
    float m_afWaveHeight[4];
    float m_afBumpSpeed[4];
};

WM4_REGISTER_INITIALIZE(RipplingOcean);

#endif
