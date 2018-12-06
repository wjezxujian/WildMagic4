// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PLANARREFLECTIONEFFECT_H
#define WM4PLANARREFLECTIONEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Effect.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PlanarReflectionEffect : public Effect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    PlanarReflectionEffect (int iQuantity);
    virtual ~PlanarReflectionEffect ();

    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iMin, int iMax, VisibleObject* akVisible);

    // member access
    int GetQuantity () const;
    void SetPlane (int i, TriMeshPtr spkPlane);
    TriMeshPtr GetPlane (int i) const;
    void SetReflectance (int i, float fReflectance);
    float GetReflectance (int i) const;

protected:
    PlanarReflectionEffect ();

    void GetReflectionMatrixAndPlane (int i, Matrix4f& rkReflection,
        Plane3f& rkPlane);

    int m_iQuantity;
    TriMeshPtr* m_aspkPlane;
    float* m_afReflectance;

    // Temporary render state for drawing.
    AlphaStatePtr m_spkAState;
    StencilStatePtr m_spkSState;
    ZBufferStatePtr m_spkZState;
};

WM4_REGISTER_STREAM(PlanarReflectionEffect);
typedef Pointer<PlanarReflectionEffect> PlanarReflectionEffectPtr;
#include "Wm4PlanarReflectionEffect.inl"

}

#endif
