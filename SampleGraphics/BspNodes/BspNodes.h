// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BSPNODES_H
#define BSPNODES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BspNodes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BspNodes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    BspNode* CreateNode (const Vector2f& rkV0, const Vector2f& rkV1,
        const ColorRGB& rkColor);

    NodePtr m_spkScene;
    BspNodePtr m_spkBsp;
    WireframeStatePtr m_spkWireframe;

    // for rectangles used to visualize the binary separating planes
    CullStatePtr m_spkRCull;
    WireframeStatePtr m_spkRWireframe;

    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(BspNodes);

#endif
