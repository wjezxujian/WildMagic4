// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PLATFORMS_H
#define WM4PLATFORMS_H

// Platform-specific information goes in this header file.  The defines to
// control which platform is included are:
//
// MINGW      :  Minimalist GNU for Windows
// _WIN32     :  Microsoft Windows 2000/XP
// __APPLE__  :  Macintosh OS X (10.2.3 or higher required)
// __sgi      :  Silicon Graphics Irix
// __sun      :  Sun Solaris
// <none>     :  Linux
//
// Add others as needed.

//----------------------------------------------------------------------------
// Minimalist GNU for Windows
//----------------------------------------------------------------------------
#if defined(MINGW)

typedef long long Integer64;

//----------------------------------------------------------------------------
// Microsoft Windows 2000/XP platform
//----------------------------------------------------------------------------
#elif defined(_WIN32)

#if defined(_MSC_VER)

// Microsoft Visual C++ specific pragmas.  MSVC6 is version 12.00, MSVC7.0 is
// version 13.00, and MSVC7.1 is version 13.10.  MSVC8.0 is version 14.00.
#if _MSC_VER < 1300
#define WM4_USING_VC6
#elif _MSC_VER < 1310
#define WM4_USING_VC70
#elif _MSC_VER < 1400
#define WM4_USING_VC71
#else
#define WM4_USING_VC80
#endif

#if defined(WM4_USING_VC6)

// Disable the warning "non dll-interface class FOO used as base for
// dll-interface class BAR."  These occur in the derivations
// class Binary2D : public ImageInt2D; class Binary3D : public ImageInt3D;
//#pragma warning( disable : 4275 )

// Disable the warning about truncating the debug names to 255 characters.
// This warning shows up often with STL code in MSVC6, but not MSVC7.
#pragma warning( disable : 4786 )

// This warning is disabled because MSVC6 warns about not finding
// implementations for the pure virtual functions that occur in the template
// classes 'template <class Real>' when explicitly instantiating the classes.
// NOTE:  If you create your own template classes that will be explicitly
// instantiated, you should re-enable the warning to make sure that in fact
// all your member data and functions have been defined and implemented.
#pragma warning( disable : 4661 )

#endif

// The use of WM4_FOUNDATION_ITEM to export an entire class generates warnings
// when member data and functions involving templates or inlines occur.  To
// avoid the warning, WM4_FOUNDATION_ITEM can be applied only to those items
// that really need to be exported.
#pragma warning( disable : 4251 ) 

typedef __int64 Integer64;

#endif
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Macintosh OS X platform
//----------------------------------------------------------------------------
#elif defined(__APPLE__)

#if defined(__BIG_ENDIAN__)
#define WM4_BIG_ENDIAN
#else
#define WM4_LITTLE_ENDIAN
#endif

#include <stdint.h>
typedef int64_t Integer64;
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Linux platform
//----------------------------------------------------------------------------
#else

#include <stdint.h>
typedef int64_t Integer64;

#endif
//----------------------------------------------------------------------------

#endif
