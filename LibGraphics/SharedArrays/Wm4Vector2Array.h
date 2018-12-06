// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VECTOR2ARRAY_H
#define WM4VECTOR2ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector2.h"

namespace Wm4
{
typedef TSharedArray<Vector2f> Vector2fArray;
typedef Pointer<Vector2fArray> Vector2fArrayPtr;
WM4_REGISTER_STREAM(Vector2fArray);

typedef TSharedArray<Vector2d> Vector2dArray;
typedef Pointer<Vector2dArray> Vector2dArrayPtr;
WM4_REGISTER_STREAM(Vector2dArray);
}

#endif
