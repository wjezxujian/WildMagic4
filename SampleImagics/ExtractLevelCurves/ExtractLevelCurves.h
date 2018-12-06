// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef EXTRACTLEVELCURVES_H
#define EXTRACTLEVELCURVES_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class ExtractLevelCurves : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    enum { MAGNIFY = 8, SIZE = 32, XPOS = 100, YPOS = 100 };

    bool Extract ();

    static void DrawPixel (int iX, int iY);
    static ImageRGB82D* ms_pkColor;
    static unsigned int ms_uiColor;
    static float ms_fMultiply;
};

WM4_REGISTER_INITIALIZE(ExtractLevelCurves);

#endif

