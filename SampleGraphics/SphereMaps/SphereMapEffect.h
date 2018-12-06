// Geometric Tools
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM4) source code is supplied under the terms of
// the license agreement
//    http://www.geometrictools.com/License/WildMagic4License.pdf 
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SPHEREMAPEFFECT_H
#define SPHEREMAPEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class SphereMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SphereMapEffect (const std::string& rkEnvName);
    virtual ~SphereMapEffect ();

protected:
    SphereMapEffect ();
};

WM4_REGISTER_STREAM(SphereMapEffect);
typedef Pointer<SphereMapEffect> SphereMapEffectPtr;

}

#endif
