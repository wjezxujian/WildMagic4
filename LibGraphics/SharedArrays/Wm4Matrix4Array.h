// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MATRIX4ARRAY_H
#define WM4MATRIX4ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Matrix4.h"

namespace Wm4
{
typedef TSharedArray<Matrix4f> Matrix4fArray;
typedef Pointer<Matrix4fArray> Matrix4fArrayPtr;
WM4_REGISTER_STREAM(Matrix4fArray);

typedef TSharedArray<Matrix4d> Matrix4dArray;
typedef Pointer<Matrix4dArray> Matrix4dArrayPtr;
WM4_REGISTER_STREAM(Matrix4dArray);
}

#endif
