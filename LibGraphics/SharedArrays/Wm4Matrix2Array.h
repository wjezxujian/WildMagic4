// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MATRIX2ARRAY_H
#define WM4MATRIX2ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Matrix2.h"

namespace Wm4
{
typedef TSharedArray<Matrix2f> Matrix2fArray;
typedef Pointer<Matrix2fArray> Matrix2fArrayPtr;
WM4_REGISTER_STREAM(Matrix2fArray);

typedef TSharedArray<Matrix2d> Matrix2dArray;
typedef Pointer<Matrix2dArray> Matrix2dArrayPtr;
WM4_REGISTER_STREAM(Matrix2dArray);
}

#endif
