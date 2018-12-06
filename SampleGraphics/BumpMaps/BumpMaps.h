// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BUMPMAPS_H
#define BUMPMAPS_H

#include "Wm4WindowApplication3.h"
#include "SimpleBumpMapEffect.h"
using namespace Wm4;

class BumpMaps : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BumpMaps ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    TriMesh* CreateTorus ();
    TriMesh* CreateSquare ();
    void UpdateBumpMap ();

    NodePtr m_spkScene;
    Culler m_kCuller;
    bool m_bUseTorus;
    bool m_bUseBumpMap;
};

WM4_REGISTER_INITIALIZE(BumpMaps);

#endif
