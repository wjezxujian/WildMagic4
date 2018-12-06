// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SIMPLEPENDULUM_H
#define SIMPLEPENDULUM_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class SimplePendulum : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    enum { SIZE = 512 };

    static float* ExplicitEuler (float fX0, float fY0, float fH);
    static float* ImplicitEuler (float fX0, float fY0, float fH);
    static float* RungeKutta (float fX0, float fY0, float fH);
    static float* LeapFrog (float fX0, float fY0, float fH);
    void SolveMethod (float* (*oMethod)(float,float,float),
        const char* acOutIm, const char* acOutTxt);

    void Stiff1 ();
    float F0 (float fT, float fX, float fY);
    float F1 (float fT, float fX, float fY);
    void Stiff2True ();
    void Stiff2Approximate ();

    static void DrawPixel (int iX, int iY);
    static ImageRGB82D* ms_pkImage;
    static unsigned int ms_uiColor;
    static float ms_fK;
};

WM4_REGISTER_INITIALIZE(SimplePendulum);

#endif

