// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef INTERSECTRECTANGLES_H
#define INTERSECTRECTANGLES_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class IntersectRectangles : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectRectangles ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void ModifyRectangles ();
    void DrawRectangles ();

    std::vector<AxisAlignedBox2f> m_kRects;
    IntersectingRectanglesf* m_pkIR;
    bool m_bMouseDown;
    float m_fLastIdle;
};

WM4_REGISTER_INITIALIZE(IntersectRectangles);

#endif

