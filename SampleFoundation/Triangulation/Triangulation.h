// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class Triangulation : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Triangulation ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

protected:
    // The polygon to triangulate, with m_iVQuantity vertices, and ordered
    // counterclockwise.
    int m_iVQuantity;
    Vector2f* m_akVertex;

    // The triangulation stored as an array of triples of indices.  The
    // number of triangles is m_iTQuantity = m_iVQuantity-2.  The array has
    // 3*m_iTQuantity elements.
    int m_iTQuantity;
    int* m_aiIndex;
};

WM4_REGISTER_INITIALIZE(Triangulation);

#endif

