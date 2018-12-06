// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BOXBVTREE_H
#define WM4BOXBVTREE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BoundingVolumeTree.h"
#include "Wm4BoxBV.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM BoxBVTree : public BoundingVolumeTree
{
    WM4_DECLARE_INITIALIZE;

public:
    BoxBVTree (const TriMesh* pkMesh, int iMaxTrisPerLeaf = 1,
        bool bStoreInteriorTris = false);

protected:
    static BoundingVolume* CreateModelBound (const TriMesh* pkMesh, int i0,
        int i1, int* aiISplit, Line3f& rkLine);

    static BoundingVolume* CreateWorldBound ();
};

WM4_REGISTER_INITIALIZE(BoxBVTree);

}

#endif
