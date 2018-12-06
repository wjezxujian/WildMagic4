// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4EFFECT_H
#define WM4EFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

class Geometry;
class Renderer;
class VisibleObject;

class WM4_GRAPHICS_ITEM Effect : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~Effect ();

    // Override this function to obtain whatever drawing behavior your effect
    // requires.  If this is not overridden, the default behavior is to
    // draw all the Geometry objects in akVisible.
    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    // Override these to allow loading and releasing of any resources your
    // effect requires.  The defaults are to do nothing.  The functions are
    // called by Renderer::LoadResources and Renderer::ReleaseResources for
    // Geometry and Effect objects.
    virtual void LoadResources (Renderer* pkRenderer, Geometry* pkGeometry);
    virtual void ReleaseResources (Renderer* pkRenderer,
        Geometry* pkGeometry);

protected:
    Effect ();
};

WM4_REGISTER_STREAM(Effect);
typedef Pointer<Effect> EffectPtr;

}

#endif
