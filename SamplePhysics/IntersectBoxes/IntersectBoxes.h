// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef INTERSECTBOXES_H
#define INTERSECTBOXES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class IntersectBoxes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectBoxes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ModifyBoxes ();
    void ModifyMesh (int i);

    std::vector<AxisAlignedBox3f> m_kBoxes;
    IntersectingBoxesf* m_pkIB;
    bool m_bDoSimulation;
    float m_fLastIdle;

    NodePtr m_spkScene;
    MaterialStatePtr m_spkBlue, m_spkRed;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    static float ms_fSize;
};

WM4_REGISTER_INITIALIZE(IntersectBoxes);

#endif

