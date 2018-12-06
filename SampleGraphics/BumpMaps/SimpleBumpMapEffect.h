// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SIMPLEBUMPMAPEFFECT_H
#define SIMPLEBUMPMAPEFFECT_H

#include "Wm4ShaderEffect.h"
#include "Wm4Light.h"
#include "Wm4Geometry.h"

namespace Wm4
{

class SimpleBumpMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SimpleBumpMapEffect (const char* acBaseName, const char* acNormalName,
        const Vector3f& rkLightDirection);
    virtual ~SimpleBumpMapEffect ();

    void SetLightDirection (const Vector3f& rkLightDirection);
    const Vector3f& GetLightDirection () const;
    void ComputeLightVectors (Geometry* pkMesh);

protected:
    SimpleBumpMapEffect ();

    // Compute a tangent at the vertex P0.  The triangle is counterclockwise
    // ordered, <P0,P1,P2>.
    bool ComputeTangent (
        const Vector3f& rkPos0, const Vector2f& rkTCoord0,
        const Vector3f& rkPos1, const Vector2f& rkTCoord1,
        const Vector3f& rkPos2, const Vector2f& rkTCoord2,
        Vector3f& rkTangent);

    Vector3f m_kLightDirection;
};

WM4_REGISTER_STREAM(SimpleBumpMapEffect);
typedef Pointer<SimpleBumpMapEffect> SimpleBumpMapEffectPtr;

}

#endif
