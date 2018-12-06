// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CUBEMAPS_H
#define CUBEMAPS_H

#include "Wm4WindowApplication3.h"
#include "CubeMapEffect.h"
using namespace Wm4;

class CubeMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    CubeMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void MorphSphere ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    CullStatePtr m_spkCull;
    TriMeshPtr m_spkSphere;
    CubeMapEffectPtr m_spkCubeMap;
    Culler m_kCuller;

    // For random morphing of the sphere.
    float m_fRadius;
    float* m_afAmplitude;
    float* m_afFrequency;
};

WM4_REGISTER_INITIALIZE(CubeMaps);

#endif
