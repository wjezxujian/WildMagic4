// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VOLUMEFOGEFFECT_H
#define WM4VOLUMEFOGEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class VolumeFogEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VolumeFogEffect (const std::string& rkBaseName);
    virtual ~VolumeFogEffect ();

protected:
    // streaming
    VolumeFogEffect ();
};

WM4_REGISTER_STREAM(VolumeFogEffect);
typedef Pointer<VolumeFogEffect> VolumeFogEffectPtr;

}

#endif
