// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RANDOMCONTROLLER_H
#define RANDOMCONTROLLER_H

#include "Wm4PointController.h"

namespace Wm4
{

class RandomController : public PointController
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    RandomController ();
protected:
    virtual void UpdatePointMotion (float fCtrlTime);
};

WM4_REGISTER_STREAM(RandomController);

}

#endif
