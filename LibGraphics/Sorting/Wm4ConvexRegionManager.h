// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONVEXREGIONMANAGER_H
#define WM4CONVEXREGIONMANAGER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BspNode.h"
#include "Wm4CRMCuller.h"

namespace Wm4
{

class Camera;
class ConvexRegion;

class WM4_GRAPHICS_ITEM ConvexRegionManager : public BspNode
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  The BSP tree should be built so that
    // the leaf nodes are where the ConvexRegion objects are located.
    ConvexRegionManager ();
    virtual ~ConvexRegionManager ();

    // The middle child of ConvexRegionManager is where the representation
    // of the outside of the set of regions is stored.  This can be an
    // arbitrary subgraph, not just drawable geometry.
    SpatialPtr AttachOutside (Spatial* pkOutside);
    SpatialPtr DetachOutside ();
    SpatialPtr GetOutside ();

    // Determine region that contains the point.  If the point is outside
    // the set of regions, the return values is null.
    ConvexRegion* GetContainingRegion (const Vector3f& rkPoint);

protected:
    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    CRMCuller m_kCuller;
};

WM4_REGISTER_STREAM(ConvexRegionManager);
typedef Pointer<ConvexRegionManager> ConvexRegionManagerPtr;

}

#endif
