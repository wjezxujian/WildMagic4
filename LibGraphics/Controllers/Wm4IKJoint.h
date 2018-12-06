// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4IKJOINT_H
#define WM4IKJOINT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4IKGoal.h"

namespace Wm4
{

class Spatial;

class WM4_GRAPHICS_ITEM IKJoint : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  IKJoint assumes responsibility for the
    // input array of pointers to goals and will delete it.  The array should
    // therefore be dynamically allocated.  The goals themselves are managed
    // by the IKController and will be deleted by it.
    IKJoint (Spatial* pkObject, int iGoalQuantity, IKGoalPtr* aspkGoal);
    virtual ~IKJoint ();

    // index i is for the joint's parent's world axis[i]
    bool AllowTranslation[3];
    float MinTranslation[3];
    float MaxTranslation[3];
    bool AllowRotation[3];
    float MinRotation[3];
    float MaxRotation[3];

protected:
    // streaming
    IKJoint ();

    // support for the IK update
    friend class IKController;

    // the managed object
    Spatial* m_pkObject;

    // joint update
    Vector3f GetAxis (int i);
    void UpdateWorldSRT ();
    void UpdateWorldRT ();
    bool UpdateLocalT (int i);
    bool UpdateLocalR (int i);

    // the goals affected by this joint
    int m_iGoalQuantity;
    IKGoalPtr* m_aspkGoal;
};

WM4_REGISTER_STREAM(IKJoint);
typedef Pointer<IKJoint> IKJointPtr;

}

#endif
