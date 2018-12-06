// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GLOSSMAPEFFECT_H
#define WM4GLOSSMAPEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Light.h"

namespace Wm4
{

class GlossMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    GlossMapEffect (const std::string& rkBaseName, Light* pkLight);
    virtual ~GlossMapEffect ();

    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

protected:
    // streaming
    GlossMapEffect ();

    LightPtr m_spkLight;
};

WM4_REGISTER_STREAM(GlossMapEffect);
typedef Pointer<GlossMapEffect> GlossMapEffectPtr;

}

#endif
