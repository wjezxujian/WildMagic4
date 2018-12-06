// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GRAPHICSLIB_H
#define WM4GRAPHICSLIB_H

// For the DLL library.
#ifdef WM4_GRAPHICS_DLL_EXPORT
#define WM4_GRAPHICS_ITEM __declspec(dllexport)

// For a client of the DLL library.
#else
#ifdef WM4_GRAPHICS_DLL_IMPORT
#define WM4_GRAPHICS_ITEM __declspec(dllimport)

// For the static library.
#else
#define WM4_GRAPHICS_ITEM

#endif
#endif
#endif
