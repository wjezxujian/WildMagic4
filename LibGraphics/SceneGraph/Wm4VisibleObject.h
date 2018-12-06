// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VISIBLEOBJECT_H
#define WM4VISIBLEOBJECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class Effect;
class Spatial;

class WM4_GRAPHICS_ITEM VisibleObject
{
public:
    Spatial* Object;
    Effect* GlobalEffect;

    bool IsDrawable () const;
};

#include "Wm4VisibleObject.inl"

}

#endif
