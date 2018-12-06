// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4IKGOAL_H
#define WM4IKGOAL_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM IKGoal : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IKGoal (Spatial* pkTarget, Spatial* pkEffector, float fWeight);

    SpatialPtr GetTarget ();
    SpatialPtr GetEffector ();
    float Weight;  // default = 1.0f

    Vector3f GetTargetPosition () const;
    Vector3f GetEffectorPosition () const;

protected:
    IKGoal ();

    SpatialPtr m_spkTarget;
    SpatialPtr m_spkEffector;
};

WM4_REGISTER_STREAM(IKGoal);
typedef Pointer<IKGoal> IKGoalPtr;
#include "Wm4IKGoal.inl"

}

#endif
