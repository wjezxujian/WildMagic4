// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4ApplicationPCH.h"
#include "Wm4ConsoleApplication.h"
using namespace Wm4;

//----------------------------------------------------------------------------
ConsoleApplication::ConsoleApplication ()
{
}
//----------------------------------------------------------------------------
ConsoleApplication::~ConsoleApplication ()
{
}
//----------------------------------------------------------------------------
int ConsoleApplication::Run (int iQuantity, char** apcArgument)
{
    ConsoleApplication* pkTheApp = (ConsoleApplication*)TheApplication;
    return pkTheApp->Main(iQuantity,apcArgument);
}
//----------------------------------------------------------------------------
