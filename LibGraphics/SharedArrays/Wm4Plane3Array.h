// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PLANE3ARRAY_H
#define WM4PLANE3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Plane3.h"

namespace Wm4
{
typedef TSharedArray<Plane3f> Plane3fArray;
typedef Pointer<Plane3fArray> Plane3fArrayPtr;
WM4_REGISTER_STREAM(Plane3fArray);

typedef TSharedArray<Plane3d> Plane3dArray;
typedef Pointer<Plane3dArray> Plane3dArrayPtr;
WM4_REGISTER_STREAM(Plane3dArray);
}

#endif
