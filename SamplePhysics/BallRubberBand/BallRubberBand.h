// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BALLRUBBERBAND_H
#define BALLRUBBERBAND_H

#include "Wm4WindowApplication2.h"
#include "PhysicsModule.h"
using namespace Wm4;

class BallRubberBand : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    BallRubberBand ();

    virtual bool OnInitialize ();
    virtual void OnDisplay ();

protected:
    PhysicsModule m_kModule;
    std::vector<Vector2d> m_kPosition;
};

WM4_REGISTER_INITIALIZE(BallRubberBand);

#endif
