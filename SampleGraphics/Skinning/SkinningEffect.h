// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SKINNINGEFFECT_H
#define SKINNINGEFFECT_H

#include "Wm4ShaderEffect.h"

namespace Wm4
{

class SkinningEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SkinningEffect ();
    virtual ~SkinningEffect ();

    void SetMatrix (int i, const Matrix4f& rkMatrix);
    const Matrix4f& GetMatrix (int i) const;

protected:
    // Set the user-defined constants to use local storage.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    Matrix4f m_akMatrix[4];
};

WM4_REGISTER_STREAM(SkinningEffect);
typedef Pointer<SkinningEffect> SkinningEffectPtr;

#include "SkinningEffect.inl"

}

#endif
