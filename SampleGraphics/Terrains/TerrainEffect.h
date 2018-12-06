// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef TERRAINEFFECT_H
#define TERRAINEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class TerrainEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // The fog factor is computed to be f = exp(-(d*z)^2), where d is the
    // fog density and z is the z-component of the view-space vertex position.
    TerrainEffect (const char* acBaseName, const char* acDetailName,
        const ColorRGB& rkFogColor, float fFogDensity);
    virtual ~TerrainEffect ();

    void SetFogColor (const ColorRGB& rkFogColor);
    ColorRGB GetFogColor () const;

    void SetFogDensity (float fFogDensity);
    float GetFogDensity () const;

    // Set the user-defined constants to use local storage.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

protected:
    // streaming
    TerrainEffect ();

    // The fog color is stored in the first three components (R = 0, G = 1,
    // and B = 2).  The fog density is stored in the last component.
    float m_afFogColorDensity[4];
};

WM4_REGISTER_STREAM(TerrainEffect);
typedef Pointer<TerrainEffect> TerrainEffectPtr;

#include "TerrainEffect.inl"

}

#endif
