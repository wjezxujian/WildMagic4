// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef REFRACTIONEFFECT_H
#define REFRACTIONEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class RefractionEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    RefractionEffect (const char* acEnvironmentName,
        const char* acReflectionName);
    virtual ~RefractionEffect ();

    void SetFresnelConstant (int i, float fValue);
    float GetFresnelConstant (int i) const;
    void SetEtaRatio (float fEtaRatio);
    float GetEtaRatio () const;

protected:
    // streaming
    RefractionEffect ();

    // Exchange information between the effect and the programs.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // The first three values are the Fresnel constants.  The fourth value
    // is the eta ratio.
    float m_afVConstant[4];
};

WM4_REGISTER_STREAM(RefractionEffect);
typedef Pointer<RefractionEffect> RefractionEffectPtr;

#include "RefractionEffect.inl"

}

#endif
