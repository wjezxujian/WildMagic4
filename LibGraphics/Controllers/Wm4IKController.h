// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4IKCONTROLLER_H
#define WM4IKCONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Controller.h"
#include "Wm4IKGoal.h"
#include "Wm4IKJoint.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM IKController : public Controller
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  IKController assumes responsibility for
    // the input arrays and will delete them.  They should be dynamically
    // allocated.
    IKController (int iJointQuantity, IKJointPtr* aspkJoint,
        int iGoalQuantity, IKGoalPtr* aspkGoal);
    virtual ~IKController ();

    int Iterations;       // default = 128
    bool OrderEndToRoot;  // default = true

    virtual bool Update (double dAppTime);

protected:
    IKController ();

    int m_iJointQuantity;
    IKJointPtr* m_aspkJoint;

    int m_iGoalQuantity;
    IKGoalPtr* m_aspkGoal;
};

WM4_REGISTER_STREAM(IKController);
typedef Pointer<IKController> IKControllerPtr;

}

#endif
