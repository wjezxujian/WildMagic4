// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MATRIX3ARRAY_H
#define WM4MATRIX3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Matrix3.h"

namespace Wm4
{
typedef TSharedArray<Matrix3f> Matrix3fArray;
typedef Pointer<Matrix3fArray> Matrix3fArrayPtr;
WM4_REGISTER_STREAM(Matrix3fArray);

typedef TSharedArray<Matrix3d> Matrix3dArray;
typedef Pointer<Matrix3dArray> Matrix3dArrayPtr;
WM4_REGISTER_STREAM(Matrix3dArray);
}

#endif
