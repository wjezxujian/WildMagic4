// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef PROJECTEDTEXTUREEFFECT_H
#define PROJECTEDTEXTUREEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Camera.h"
#include "Wm4Light.h"

namespace Wm4
{

class ProjectedTextureEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    ProjectedTextureEffect (Camera* pkProjector, const char* acProjectorImage,
        Light* pkLight);
    virtual ~ProjectedTextureEffect ();

    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

protected:
    // streaming
    ProjectedTextureEffect ();

    CameraPtr m_spkProjector;
    LightPtr m_spkLight;
};

WM4_REGISTER_STREAM(ProjectedTextureEffect);
typedef Pointer<ProjectedTextureEffect> ProjectedTextureEffectPtr;

}

#endif
