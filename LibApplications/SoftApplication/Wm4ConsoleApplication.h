// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONSOLEAPPLICATION_H
#define WM4CONSOLEAPPLICATION_H

#include "Wm4Application.h"

namespace Wm4
{

class ConsoleApplication : public Application
{
public:
    ConsoleApplication ();
    virtual ~ConsoleApplication ();

    // Entry point to be implemented by the application.  The return value
    // is an exit code, if desired.
    virtual int Main (int iQuantity, char** apcArgument) = 0;

protected:
    // The hookup to the 'main' entry point into the executable.
    static int Run (int iQuantity, char** apcArgument);
};

}

#endif
