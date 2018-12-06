// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MAINMCR_H
#define WM4MAINMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_INITIALIZE \
public: \
    static bool RegisterInitialize (); \
    static void Initialize (); \
private: \
    static bool ms_bInitializeRegistered
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_INITIALIZE(classname) \
bool classname::ms_bInitializeRegistered = false; \
bool classname::RegisterInitialize () \
{ \
    if (!ms_bInitializeRegistered) \
    { \
        Main::AddInitializer(classname::Initialize); \
        ms_bInitializeRegistered = true; \
    } \
    return ms_bInitializeRegistered; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_INITIALIZE(classname) \
static bool gs_bInitializeRegistered_##classname = \
    classname::RegisterInitialize ()
//----------------------------------------------------------------------------
#define WM4_DECLARE_TERMINATE \
public: \
    static bool RegisterTerminate (); \
    static void Terminate (); \
private: \
    static bool ms_bTerminateRegistered
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_TERMINATE(classname) \
bool classname::ms_bTerminateRegistered = false; \
bool classname::RegisterTerminate () \
{ \
    if (!ms_bTerminateRegistered) \
    { \
        Main::AddTerminator(classname::Terminate); \
        ms_bTerminateRegistered = true; \
    } \
    return ms_bTerminateRegistered; \
}
//----------------------------------------------------------------------------
#define WM4_REGISTER_TERMINATE(classname) \
static bool gs_bTerminateRegistered_##classname = \
    classname::RegisterTerminate ()
//----------------------------------------------------------------------------

#endif
