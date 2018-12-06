// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef ROUGHPLANEPARTICLE2_H
#define ROUGHPLANEPARTICLE2_H

#include "Wm4WindowApplication2.h"
#include "PhysicsModule.h"
using namespace Wm4;

class RoughPlaneParticle2 : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    RoughPlaneParticle2 ();

    virtual bool OnInitialize ();
    virtual void OnIdle ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    PhysicsModule m_kModule;
    int m_iIteration, m_iMaxIteration;
};

WM4_REGISTER_INITIALIZE(RoughPlaneParticle2);

#endif

