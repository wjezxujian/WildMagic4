// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BILLBOARDNODE_H
#define WM4BILLBOARDNODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Node.h"
#include "Wm4Camera.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM BillboardNode : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // The model space of the billboard has an up vector of (0,1,0) that is
    // chosen to be the billboard's axis of rotation.

    // Construction and destruction.
    BillboardNode (Camera* pkCamera = 0);
    virtual ~BillboardNode ();

    // the camera to which the billboard is aligned
    void AlignTo (Camera* pkCamera);

protected:
    // geometric updates
    virtual void UpdateWorldData (double dAppTime);

    Pointer<Camera> m_spkCamera;
};

WM4_REGISTER_STREAM(BillboardNode);
typedef Pointer<BillboardNode> BillboardNodePtr;
#include "Wm4BillboardNode.inl"

}

#endif
