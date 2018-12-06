// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef NURBSCURVEEXAMPLE_H
#define NURBSCURVEEXAMPLE_H

#include "Wm4WindowApplication2.h"
using namespace Wm4;

class NURBSCurveExample : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    NURBSCurveExample ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void DoSimulation1 ();
    void DoSimulation2 ();
    void InitialConfiguration ();
    void NextConfiguration ();

    NURBSCurve2f* m_pkSpline;
    NURBSCurve2f* m_pkCircle;
    Vector2f* m_akCtrlPoint;
    Vector2f* m_akTarget;
    float m_fH, m_fD;
    float m_fSimTime, m_fSimDelta;

    bool m_bDrawControlPoints;
};

WM4_REGISTER_INITIALIZE(NURBSCurveExample);

#endif

