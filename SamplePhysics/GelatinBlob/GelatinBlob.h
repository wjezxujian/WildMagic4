// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef GELATINBLOB_H
#define GELATINBLOB_H

#include "Wm4WindowApplication3.h"
#include "PhysicsModule.h"
using namespace Wm4;

class GelatinBlob : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GelatinBlob ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    // a mass-spring system
    PhysicsModule* m_pkModule;
    void DoPhysical ();

    // scene graph
    void CreateSphere ();
    void CreateSprings ();
    void CreateSegments ();
    void CreateScene ();
    NodePtr m_spkScene, m_spkTrnNode, m_spkSegments;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkIcosahedron;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(GelatinBlob);

#endif
