// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CAMERAANDLIGHTNODES_H
#define CAMERAANDLIGHTNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class CameraAndLightNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    CameraAndLightNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual void MoveForward ();
    virtual void MoveBackward ();
    virtual void TurnLeft ();
    virtual void TurnRight ();
    virtual void MoveUp ();
    virtual void MoveDown ();
    virtual void LookUp ();
    virtual void LookDown ();

protected:
    void CreateScene ();
    TriMesh* CreateGround ();
    TriMesh* CreateLightTarget (Light* pkLight);
    Node* CreateLightFixture (LightPtr& rspkAdjustableLight);
    void CreateScreenPolygon ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframeState;
    CameraNodePtr m_spkCNode;
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkSky;
    LightPtr m_spkAdjustableLight0, m_spkAdjustableLight1;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(CameraAndLightNodes);

#endif
