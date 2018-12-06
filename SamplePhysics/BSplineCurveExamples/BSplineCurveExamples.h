// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BSPLINECURVEEXAMPLES_H
#define BSPLINECURVEEXAMPLES_H

#include "Wm4WindowApplication2.h"
#include "Wm4BSplineCurve2.h"
using namespace Wm4;

class BSplineCurveExamples : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineCurveExamples ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    BSplineCurve2f* m_pkSpline;
    int m_iNumCtrlPoints, m_iDegree;
    Vector2f* m_akCtrlPoint;
    float* m_afKnot;
    float m_afLocCtrlMin[6], m_afLocCtrlMax[6];
    int m_iCurveType;
    bool m_bModified;
};

WM4_REGISTER_INITIALIZE(BSplineCurveExamples);

#endif

