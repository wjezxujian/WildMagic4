// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CHARCOALEFFECT_H
#define CHARCOALEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Light.h"

namespace Wm4
{

class CharcoalEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // The vertex shader expects two lights.  They should be attached
    // somewhere in the scene to affect the Geometry object to which this
    // effect is attached.  TO DO.  See the note in CharcoalEffects, function
    // CreateScene.
    CharcoalEffect (const char* acPaperName, float fAmbientIntensity,
        float fContrastExponent, float fSmudgeFactor, float fPaperFactor,
        Light* pkLight0, Light* pkLight1);
    virtual ~CharcoalEffect ();

    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

    void SetAmbientIntensity (float fAmbientIntensity);
    float GetAmbientIntensity () const;
    void SetContrastExponent (float fContrastExponent);
    float GetContrastExponent () const;
    void SetSmudgeFactor (float fSmudgeFactor);
    float GetSmudgeFactor () const;
    void SetPaperFactor (float fPaperFactor);
    float GetPaperFactor () const;

protected:
    // streaming
    CharcoalEffect ();

    // Exchange information between the effect and the programs.
    void GenerateContrastImage ();
    void GenerateRandomImage ();
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // VShader constants.  The ambient intensity is stored at index 0.  The
    // contrast exponent is stored at index 1.  The other values are unused.
    float m_afAmbientContrast[4];

    // PShader constants.  The smudge factor is stored at index 0.  The paper
    // factor is stored at index 1.  The other values are unused.
    float m_afSmudgePaper[4];

    ImagePtr m_spkContrastImage, m_spkRandomImage;
    LightPtr m_spkLight0, m_spkLight1;
};

WM4_REGISTER_STREAM(CharcoalEffect);
typedef Pointer<CharcoalEffect> CharcoalEffectPtr;
#include "CharcoalEffect.inl"

}

#endif
