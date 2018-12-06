// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4APPLICATIONMCR_H
#define WM4APPLICATIONMCR_H

//----------------------------------------------------------------------------
#define WM4_CONSOLE_APPLICATION(classname) \
WM4_IMPLEMENT_INITIALIZE(classname); \
\
void classname::Initialize () \
{ \
    Application::Run = &ConsoleApplication::Run; \
    TheApplication = WM4_NEW classname; \
}
//----------------------------------------------------------------------------
#define WM4_WINDOW_APPLICATION(classname) \
WM4_IMPLEMENT_INITIALIZE(classname); \
\
void classname::Initialize () \
{ \
    Application::Run = &WindowApplication::Run; \
    TheApplication = WM4_NEW classname; \
}
//----------------------------------------------------------------------------

#endif
