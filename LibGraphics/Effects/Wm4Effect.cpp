// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4Effect.h"
#include "Wm4Geometry.h"
#include "Wm4Renderer.h"
#include "Wm4VisibleSet.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Effect,Object);
WM4_IMPLEMENT_STREAM(Effect);
WM4_IMPLEMENT_DEFAULT_STREAM(Effect,Object);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Effect,Object);

//----------------------------------------------------------------------------
Effect::Effect ()
{
}
//----------------------------------------------------------------------------
Effect::~Effect ()
{
}
//----------------------------------------------------------------------------
void Effect::Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
    int iMin, int iMax, VisibleObject* akVisible)
{
    // The default drawing function for global effects.  Essentially, this is
    // a local effect applied to all the visible leaf geometry.
    for (int i = iMin; i <= iMax; i++)
    {
        if (akVisible[i].IsDrawable())
        {
            Geometry* pkGeometry = (Geometry*)akVisible[i].Object;
            pkGeometry->AttachEffect(this);
            pkRenderer->Draw(pkGeometry);
            pkGeometry->DetachEffect(this);
        }
    }
}
//----------------------------------------------------------------------------
void Effect::LoadResources (Renderer*, Geometry*)
{
    // Stub for derived classes.
}
//----------------------------------------------------------------------------
void Effect::ReleaseResources (Renderer*, Geometry*)
{
    // Stub for derived classes.
}
//----------------------------------------------------------------------------
