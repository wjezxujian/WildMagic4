// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4Camera.h"
#include "Wm4ConvexRegionManager.h"
#include "Wm4ConvexRegion.h"
#include "Wm4Renderer.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,ConvexRegionManager,BspNode);
WM4_IMPLEMENT_STREAM(ConvexRegionManager);
WM4_IMPLEMENT_DEFAULT_STREAM(ConvexRegionManager,BspNode);
WM4_IMPLEMENT_DEFAULT_NAME_ID(ConvexRegionManager,BspNode);

//----------------------------------------------------------------------------
ConvexRegionManager::ConvexRegionManager ()
{
}
//----------------------------------------------------------------------------
ConvexRegionManager::~ConvexRegionManager ()
{
}
//----------------------------------------------------------------------------
SpatialPtr ConvexRegionManager::AttachOutside (Spatial* pkOutside)
{
    return SetChild(1,pkOutside);
}
//----------------------------------------------------------------------------
SpatialPtr ConvexRegionManager::DetachOutside ()
{
    return DetachChildAt(1);
}
//----------------------------------------------------------------------------
SpatialPtr ConvexRegionManager::GetOutside ()
{
    return GetChild(1);
}
//----------------------------------------------------------------------------
ConvexRegion* ConvexRegionManager::GetContainingRegion (
    const Vector3f& rkPoint)
{
    return DynamicCast<ConvexRegion>(GetContainingNode(rkPoint));
}
//----------------------------------------------------------------------------
void ConvexRegionManager::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    ConvexRegion* pkRegion = GetContainingRegion(
        rkCuller.GetCamera()->GetLocation());

    if (pkRegion)
    {
        // Accumulate visible objects starting in the region containing the
        // camera.  Use the CRMCuller to maintain a list of unique objects.
        //pkRegion->GetVisibleSet(m_kCuller,bNoCull);
        m_kCuller.SetCamera(rkCuller.GetCamera());
        m_kCuller.SetFrustum(rkCuller.GetFrustum());
        m_kCuller.ComputeVisibleSet(pkRegion);

        // Copy the unique list to the scene culler.
        VisibleSet& rkVisible = m_kCuller.GetVisibleSet();
        const int iQuantity = rkVisible.GetQuantity();
        for (int i = 0; i < iQuantity; i++)
        {
            VisibleObject& rkVObj = rkVisible.GetVisible(i);
            rkCuller.Insert(rkVObj.Object,rkVObj.GlobalEffect);
        }
    }
    else
    {
        // The camera is outside the set of regions.  Accumulate visible
        // objects for the outside scene (if it exists).
        if (GetOutside())
        {
            GetOutside()->GetVisibleSet(rkCuller,bNoCull);
        }
    }
}
//----------------------------------------------------------------------------
