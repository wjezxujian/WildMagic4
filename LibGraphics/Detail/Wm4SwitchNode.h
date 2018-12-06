// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SWITCHNODE_H
#define WM4SWITCHNODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Node.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM SwitchNode : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SwitchNode ();
    virtual ~SwitchNode ();

    enum { SN_INVALID_CHILD = -1 };

    void SetActiveChild (int iActiveChild);
    int GetActiveChild () const;
    void DisableAllChildren ();

    // Picking support.  The origin and direction of the ray must be in world
    // coordinates.  The application is responsible for deleting the pick
    // records in the array.  This function only picks on the active child.
    // If there is a demand to support inactive children, a data member must
    // be added to indicate whether or not the caller wants active-only
    // or all children to be picked.
    virtual void DoPick (const Ray3f& rkRay, PickArray& rkResults);

protected:
    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    int m_iActiveChild;
};

WM4_REGISTER_STREAM(SwitchNode);
typedef Pointer<SwitchNode> SwitchNodePtr;
#include "Wm4SwitchNode.inl"

}

#endif
