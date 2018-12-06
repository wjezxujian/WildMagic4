// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef DELAUNAY2D_H
#define DELAUNAY2D_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class Delaunay2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Delaunay2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    Delaunay1f* m_pkDel1;
    Delaunay2f* m_pkDel2;

    int m_iVQuantity;
    Vector2f* m_akVertex;
    int m_iTQuantity;
    int* m_aiTVertex;
    int* m_aiTAdjacent;

    int m_iCurrTriX, m_iCurrTriY;
    int m_iCurrentIndex;
};

WM4_REGISTER_INITIALIZE(Delaunay2D);

#endif
