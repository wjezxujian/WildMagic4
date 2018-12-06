// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VERTEXCOLOR4EFFECT_H
#define WM4VERTEXCOLOR4EFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexColor4Effect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VertexColor4Effect ();
    virtual ~VertexColor4Effect ();
};

WM4_REGISTER_STREAM(VertexColor4Effect);
typedef Pointer<VertexColor4Effect> VertexColor4EffectPtr;

}

#endif
