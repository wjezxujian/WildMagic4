// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BSPLINEFITDISCRETE_H
#define BSPLINEFITDISCRETE_H

#include "Wm4WindowApplication3.h"
#include "Wm4BSplineFit.h"
using namespace Wm4;

class BSplineFitDiscrete : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineFitDiscrete ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void CreateBSplinePolyline ();

    NodePtr m_spkScene;
    VertexColor3EffectPtr m_spkEffect;
    Culler m_kCuller;

    int m_iSampleQuantity;
    Vector3f* m_akSample;
    int m_iDegree;
    int m_iCtrlQuantity;
    BSplineFitf* m_pkBSpline;

    enum { MESSAGE_SIZE = 128 };
    char m_acMessage[MESSAGE_SIZE];
};

WM4_REGISTER_INITIALIZE(BSplineFitDiscrete);

#endif
