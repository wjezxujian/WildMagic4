// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4COLLISIONRECORD_H
#define WM4COLLISIONRECORD_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BoundingVolumeTree.h"
#include "Wm4Intersector.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CollisionRecord
{
public:
    typedef void (*Callback) (CollisionRecord& rkRecord0, int iT0,
        CollisionRecord& rkRecord1, int iT1,
        Intersector<float,Vector3f>* pkIntersector);

    // Construction and destruction.  CollisionRecord assumes responsibility
    // for deleting pkTree, so it should be dynamically allocated.
    CollisionRecord (TriMesh* pkMesh, BoundingVolumeTree* pkTree,
        Vector3f* pkVelocity, Callback oCallback, void* pvCallbackData);

    ~CollisionRecord ();

    // member access
    TriMesh* GetMesh ();
    Vector3f* GetVelocity ();
    void* GetCallbackData ();

    // intersection queries
    void TestIntersection (CollisionRecord& rkRecord);
    void FindIntersection (CollisionRecord& rkRecord);
    void TestIntersection (float fTMax, CollisionRecord& rkRecord);
    void FindIntersection (float fTMax ,CollisionRecord& rkRecord);

protected:
    TriMesh* m_pkMesh;
    BoundingVolumeTree* m_pkTree;
    Vector3f* m_pkVelocity;
    Callback m_oCallback;
    void* m_pvCallbackData;
};

#include "Wm4CollisionRecord.inl"

}

#endif
