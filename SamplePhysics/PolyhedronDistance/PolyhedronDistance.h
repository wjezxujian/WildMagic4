// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef POLYHEDRONDISTANCE_H
#define POLYHEDRONDISTANCE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class PolyhedronDistance : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    PolyhedronDistance ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    TriMesh* CreateTetra (float fSize, bool bBlack);
    Polyline* CreateLine ();
    TriMesh* CreatePlane ();
    void UpdateLine ();
    void InitialState ();
    bool Transform (unsigned char ucKey);

    // representation of bodies
    TTuple<3,int>* m_akFace;
    TriMesh* m_apkTetra[4];
    VertexBuffer* m_apkVBuffer[2];
    Vector3f m_akTV[2];
    Matrix3f m_akTM[2];

    // display variables
    float m_fSeparation;
    float m_fEdgeLength;
    float m_fSmall;

    // Offsets during calculation with LCPPolyDist to ensure that all of the
    // vertices are in the first octant.
    float m_fOffset;
 
    // the scene graph
    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    PolylinePtr m_aspkLine[2];
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(PolyhedronDistance);

#endif

