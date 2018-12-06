// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef IRIDESCENCEEFFECT_H
#define IRIDESCENCEEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class IridescenceEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IridescenceEffect (const char* acBaseName, const char* acGradName);
    virtual ~IridescenceEffect ();

    void SetInterpolateFactor (float fInterpolateFactor);
    float GetInterpolateFactor () const;

protected:
    // streaming
    IridescenceEffect ();

    // Set the user-defined constants to use local storage.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // The interpolation factor is stored at index 0.  The other values are
    // unused.
    float m_afInterpolate[4];
};

WM4_REGISTER_STREAM(IridescenceEffect);
typedef Pointer<IridescenceEffect> IridescenceEffectPtr;

#include "IridescenceEffect.inl"

}

#endif
