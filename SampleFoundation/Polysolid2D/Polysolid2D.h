// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef POLYSOLID2D_H
#define POLYSOLID2D_H

#include "Wm4WindowApplication2.h"
#include "Polysolid2.h"
using namespace Wm4;

class Polysolid2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    Polysolid2D ();
    virtual ~Polysolid2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void ConstructPolygon (Polysolid2& rkPoly);
    void ConstructPentagon (Polysolid2& rkPoly);
    void ConstructSquare (Polysolid2& rkPoly);
    void ConstructSShape (Polysolid2& rkPoly);
    void ConstructPolyWithHoles (Polysolid2& rkPoly);
    void ConstructAnotherSquare (Polysolid2& rkPoly);
    void ConstructAnotherOne (Polysolid2& rkPoly);

    void DrawPolysolid (Polysolid2& rkPoly, Color kColor, bool bFill);

    Polysolid2 m_kPoly0, m_kPoly1;
    Polysolid2 m_kIntersection, m_kUnion, m_kDifferenceAmB;
    Polysolid2 m_kDifferenceBmA, m_kExclusiveOr;
    Polysolid2* m_pkActive;
};

WM4_REGISTER_INITIALIZE(Polysolid2D);

#endif
