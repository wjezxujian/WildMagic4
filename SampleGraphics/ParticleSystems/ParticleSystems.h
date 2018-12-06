// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PARTICLESYSTEMS_H
#define PARTICLESYSTEMS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ParticleSystems : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ParticleSystems ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateBloodCellImage ();
    Particles* CreateParticles ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    ImagePtr m_spkBloodCell;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(ParticleSystems);

#endif
