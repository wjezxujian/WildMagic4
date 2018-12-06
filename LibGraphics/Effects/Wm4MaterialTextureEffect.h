// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MATERIALTEXTUREEFFECT_H
#define WM4MATERIALTEXTUREEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM MaterialTextureEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    MaterialTextureEffect (const std::string& rkBaseName);
    virtual ~MaterialTextureEffect ();

protected:
    // streaming
    MaterialTextureEffect ();
};

WM4_REGISTER_STREAM(MaterialTextureEffect);
typedef Pointer<MaterialTextureEffect> MaterialTextureEffectPtr;

}

#endif
