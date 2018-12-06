// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef BSPLINEFITCONTINUOUS_H
#define BSPLINEFITCONTINUOUS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class BSplineFitContinuous : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    BSplineFitContinuous ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();

protected:
    Polyline* OriginalPolyline (int iCtrlQuantity, Vector3d* akCtrl);
    Polyline* ReducedPolyline (int iCtrlQuantity, Vector3d* akCtrl,
        double dFraction);

    NodePtr m_spkScene, m_spkTrnNode;
    Culler m_kCuller;
    int m_iDegree;
};

WM4_REGISTER_INITIALIZE(BSplineFitContinuous);

#endif
