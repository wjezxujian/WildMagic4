// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CAMERANODE_H
#define WM4CAMERANODE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Camera.h"
#include "Wm4Node.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CameraNode : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  The node's world translation is used
    // as the camera's location.  The node's world rotation matrix is used
    // for the camera's coordinate axes.  Column 0 of the world rotation
    // matrix is the camera's direction vector, column 1 of the world rotation
    // matrix is the camera's up vector, and column 2 of the world rotation
    // matrix is the camera's right vector.
    //
    // On construction, the node's local transformation is set to the
    // camera's current coordinate system.
    //   local translation       = camera location
    //   local rotation column 0 = camera direction
    //   local rotation column 1 = camera up
    //   local rotation column 2 = camera right
    CameraNode (Camera* pkCamera = 0);
    virtual ~CameraNode ();

    // When you set the camera, the node's local transformation is set to the
    // camera's current current coordinate system.  The node's world
    // transformation is computed, and the camera's coordinate system is set
    // to use the node's world transformation.
    void SetCamera (Camera* pkCamera);

    Camera* GetCamera ();
    const Camera* GetCamera () const;

protected:
    // geometric updates
    virtual void UpdateWorldData (double dAppTime);

    CameraPtr m_spkCamera;
};

WM4_REGISTER_STREAM(CameraNode);
typedef Pointer<CameraNode> CameraNodePtr;
#include "Wm4CameraNode.inl"

}

#endif
