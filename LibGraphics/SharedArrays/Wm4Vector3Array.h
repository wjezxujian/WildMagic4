// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VECTOR3ARRAY_H
#define WM4VECTOR3ARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector3.h"

namespace Wm4
{
typedef TSharedArray<Vector3f> Vector3fArray;
typedef Pointer<Vector3fArray> Vector3fArrayPtr;
WM4_REGISTER_STREAM(Vector3fArray);

typedef TSharedArray<Vector3d> Vector3dArray;
typedef Pointer<Vector3dArray> Vector3dArrayPtr;
WM4_REGISTER_STREAM(Vector3dArray);
}

#endif
