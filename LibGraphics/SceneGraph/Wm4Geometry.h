// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GEOMETRY_H
#define WM4GEOMETRY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"
#include "Wm4VertexBuffer.h"
#include "Wm4IndexBuffer.h"
#include "Wm4LightingEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Geometry : public Spatial
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~Geometry ();

    // member access
    VertexBufferPtr VBuffer;
    IndexBufferPtr IBuffer;
    BoundingVolumePtr ModelBound;

    // geometric updates
    virtual void UpdateMS (bool bUpdateNormals = true);

    // Picking support. This nested class exists only to maintain the
    // class-derivation chain that is parallel to the one whose base is
    // Spatial.
    class WM4_GRAPHICS_ITEM PickRecord : public Spatial::PickRecord
    {
    protected:
        PickRecord (Geometry* pkIObject, float fT);
    };

protected:
    Geometry ();
    Geometry (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer);

    // geometric updates
    virtual void UpdateModelBound ();
    virtual void UpdateModelNormals ();
    virtual void UpdateWorldBound ();

    // render state updates
    virtual void UpdateState (std::vector<GlobalState*>* akGStack,
        std::vector<Light*>* pkLStack);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // Dynamic lighting.  The effect is pushed onto the front of Spatial's
    // effect array so that lighting occurs before other shader effects.
    LightingEffectPtr m_spkLEffect;

// internal use
public:
    // Render state and lights in path to this object.  An attached effect
    // provides additional render state, lights, and any other information
    // needed to draw the object.

    enum GeometryType
    {
        GT_POLYPOINT,
        GT_POLYLINE_SEGMENTS,
        GT_POLYLINE_OPEN,
        GT_POLYLINE_CLOSED,
        GT_TRIMESH,
        GT_MAX_QUANTITY
    };

    GeometryType Type;
    GlobalStatePtr States[GlobalState::MAX_STATE_TYPE];
};

WM4_REGISTER_STREAM(Geometry);
typedef Pointer<Geometry> GeometryPtr;
#include "Wm4Geometry.inl"

}

#endif
