// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef EXTREMALQUERY_H
#define EXTREMALQUERY_H

#include "Wm4WindowApplication3.h"
#include "Wm4ExtremalQuery3.h"
using namespace Wm4;

class ExtremalQuery : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ExtremalQuery ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void CreateConvexPolyhedron (int iVQuantity);
    Node* CreateVisualConvexPolyhedron ();
    void UpdateExtremePoints ();

    ConvexPolyhedron3f* m_pkConvexPolyhedron;
    ExtremalQuery3f* m_pkExtremalQuery;

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    CullStatePtr m_spkCull;
    TriMeshPtr m_spkMaxSphere, m_spkMinSphere;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(ExtremalQuery);

#endif

