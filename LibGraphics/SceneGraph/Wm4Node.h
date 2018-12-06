// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4NODE_H
#define WM4NODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Spatial.h"
#include "Wm4Culler.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Node : public Spatial
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Node ();
    virtual ~Node ();

    // children
    int GetQuantity () const;
    int AttachChild (Spatial* pkChild);
    int DetachChild (Spatial* pkChild);
    SpatialPtr DetachChildAt (int i);
    SpatialPtr SetChild (int i, Spatial* pkChild);
    SpatialPtr GetChild (int i);

    // Picking support.  The origin and direction of the ray must be in world
    // coordinates.  The application is responsible for deleting the pick
    // records in the array.
    virtual void DoPick (const Ray3f& rkRay, PickArray& rkResults);

protected:
    // geometric updates
    virtual void UpdateWorldData (double dAppTime);
    virtual void UpdateWorldBound ();

    // render state updates
    virtual void UpdateState (std::vector<GlobalState*>* akGStack,
        std::vector<Light*>* pkLStack);

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // children
    std::vector<SpatialPtr> m_kChild;
};

WM4_REGISTER_STREAM(Node);
typedef Pointer<Node> NodePtr;
#include "Wm4Node.inl"

}

#endif
