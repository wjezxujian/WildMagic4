// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef INTERSECTINTERVALS_H
#define INTERSECTINTERVALS_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class IntersectIntervals : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    IntersectIntervals ();

    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void BookExample ();
};

WM4_REGISTER_INITIALIZE(IntersectIntervals);

#endif

