// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4FOUNDATIONLIB_H
#define WM4FOUNDATIONLIB_H

// For the DLL library.
#ifdef WM4_FOUNDATION_DLL_EXPORT
#define WM4_FOUNDATION_ITEM __declspec(dllexport)

// For a client of the DLL library.
#else
#ifdef WM4_FOUNDATION_DLL_IMPORT
#define WM4_FOUNDATION_ITEM __declspec(dllimport)

// For the static library.
#else
#define WM4_FOUNDATION_ITEM

#endif
#endif
#endif
