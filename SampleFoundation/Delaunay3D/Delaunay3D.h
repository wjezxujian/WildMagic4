// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef DELAUNAY3D_H
#define DELAUNAY3D_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class Delaunay3D : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    Delaunay3D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateSphere () const;
    TriMesh* CreateTetra (int iIndex) const;
    void ChangeTetraStatus (int iIndex, const ColorRGBA& rkColor,
        bool bWireframe);
    void ChangeLastTetraStatus (int iIndex, int iVOpposite,
        const ColorRGBA& rkColor, const ColorRGBA& rkOppositeColor);
    void DoSearch ();

    NodePtr m_spkScene;
    Culler m_kCuller;
    Delaunay3f* m_pkDel;
    Vector3f m_kMin, m_kMax;
};

WM4_REGISTER_INITIALIZE(Delaunay3D);

#endif

