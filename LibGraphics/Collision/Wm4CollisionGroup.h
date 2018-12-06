// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4COLLISIONGROUP_H
#define WM4COLLISIONGROUP_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class CollisionRecord;

class WM4_GRAPHICS_ITEM CollisionGroup
{
public:
    CollisionGroup ();
    ~CollisionGroup ();

    // CollisionGroup assumes responsibility for deleting the collision
    // records, so the input records should be dynamically allocated.
    bool Add (CollisionRecord* pkRecord);
    bool Remove (CollisionRecord* pkRecord);

    // Intersection queries.  If two objects in the group collide, the
    // corresponding records process the information accordingly.

    // The objects are assumed to be stationary (velocities are ignored) and
    // all pairs of objects are compared.
    void TestIntersection ();
    void FindIntersection ();
    
    // The objects are assumed to be moving.  Objects are compared when at
    // least one of them has a velocity vector associated with it (that
    // vector is allowed to be the zero vector).
    void TestIntersection (float fTMax);
    void FindIntersection (float fTMax);

protected:
    std::vector<CollisionRecord*> m_kRecord;
};

}

#endif
