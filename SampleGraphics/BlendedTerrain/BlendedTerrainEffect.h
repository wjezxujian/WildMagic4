// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BLENDEDTERRAINEFFECT_H
#define BLENDEDTERRAINEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class BlendedTerrainEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    BlendedTerrainEffect (const char* acGrassName, const char* acStoneName,
        const char* acBlendName, const char* acCloudName);
    virtual ~BlendedTerrainEffect ();

    // for the vertex program
    void SetFlowDirection (const Vector2f& rkFlowDirection);
    Vector2f GetFlowDirection () const;

    // for the pixel program
    void SetPowerFactor (float fPowerFactor);
    float GetPowerFactor () const;

protected:
    // streaming
    BlendedTerrainEffect ();

    // Set the user-defined constants to use local storage.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // The flow direction is stored in locations 0 and 1.  The others are
    // unused.
    float m_afFlowDirection[4];

    // The power factor is stored in location 0.  The others are unused.
    float m_afPowerFactor[4];
};

WM4_REGISTER_STREAM(BlendedTerrainEffect);
typedef Pointer<BlendedTerrainEffect> BlendedTerrainEffectPtr;

#include "BlendedTerrainEffect.inl"

}

#endif
