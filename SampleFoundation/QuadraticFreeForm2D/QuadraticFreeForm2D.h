// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef QUADRATICFREEFORM2D_H
#define QUADRATICFREEFORM2D_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class QuadraticFreeForm2D : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    QuadraticFreeForm2D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

    // Allows user to drag control points.
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    float ScreenToControl (int iScreen) const;
    int ControlToScreen (float fControl) const;
    Vector2f Evaluate (const Vector2f& rkParam) const;
    void SelectVertex (int iX, int iY);

    // The image to map to the free-form region.
    Image* m_pkImage;

    // The control points that define the free-form region.
    int m_aaiCtrlX[3][3], m_aaiCtrlY[3][3];
    Vector2f m_aakCtrl[3][3];

    // Support for dragging the control points.
    bool m_bMouseDown;
    int m_iRow, m_iCol;
};

WM4_REGISTER_INITIALIZE(QuadraticFreeForm2D);

#endif

