// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BLOODCELLCONTROLLER_H
#define BLOODCELLCONTROLLER_H

#include "Wm4ParticleController.h"

namespace Wm4
{

class BloodCellController : public ParticleController
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    BloodCellController ();
protected:
    virtual void UpdatePointMotion (float fCtrlTime);
};

WM4_REGISTER_STREAM(BloodCellController);

}

#endif
