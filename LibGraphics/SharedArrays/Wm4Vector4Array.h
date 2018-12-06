// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VECTOR4ARRAY_H
#define WM4VECTOR4ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector4.h"

namespace Wm4
{
typedef TSharedArray<Vector4f> Vector4fArray;
typedef Pointer<Vector4fArray> Vector4fArrayPtr;
WM4_REGISTER_STREAM(Vector4fArray);

typedef TSharedArray<Vector4d> Vector4dArray;
typedef Pointer<Vector4dArray> Vector4dArrayPtr;
WM4_REGISTER_STREAM(Vector4dArray);
}

#endif
