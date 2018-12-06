// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CONVEXHULL2D_H
#define CONVEXHULL2D_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class ConvexHull2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    ConvexHull2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual void ScreenOverlay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void GenerateHull0D ();
    void GenerateHull1D ();
    void GenerateHull2D ();
    void GenerateHullManyCollinear ();
    void RegenerateHull ();
    int UnitToScreen (float fValue);

    const float m_fEpsilon;
    Query::Type m_eQueryType;
    ConvexHullf* m_pkHull;
    int m_iVQuantity;
    Vector2f* m_akVertex;
};

WM4_REGISTER_INITIALIZE(ConvexHull2D);

#endif
