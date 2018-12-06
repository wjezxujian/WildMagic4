// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CLODMESHES_H
#define CLODMESHES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ClodMeshes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ClodMeshes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void DrawTriangleQuantity (int iX, int iY, const ColorRGBA& rkColor);

    // turret-based camera motion
    virtual void MoveForward ();
    virtual void MoveBackward ();

    // model is a face mesh
    NodePtr m_spkScene;
    ClodMeshPtr m_spkClod;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(ClodMeshes);

#endif
