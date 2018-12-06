// Geometric Tools
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM4) source code is supplied under the terms of
// the license agreement
//    http://www.geometrictools.com/License/WildMagic4License.pdf 
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DEFAULTSHADEREFFECT_H
#define WM4DEFAULTSHADEREFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM DefaultShaderEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    DefaultShaderEffect ();
    virtual ~DefaultShaderEffect ();
};

WM4_REGISTER_STREAM(DefaultShaderEffect);
typedef Pointer<DefaultShaderEffect> DefaultShaderEffectPtr;

}

#endif
