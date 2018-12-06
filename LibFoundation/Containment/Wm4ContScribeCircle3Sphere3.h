// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTSCRIBECIRCLE3SPHERE3_H
#define WM4CONTSCRIBECIRCLE3SPHERE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Circle3.h"
#include "Wm4Sphere3.h"

namespace Wm4
{

// All functions return 'true' if circle/sphere has been constructed,
// 'false' otherwise (input points are linearly dependent).

// circle containing three 3D points
template <class Real> WM4_FOUNDATION_ITEM
bool Circumscribe (const Vector3<Real>& rkV0, const Vector3<Real>& rkV1,
    const Vector3<Real>& rkV2, Circle3<Real>& rkCircle);

// sphere containing four 3D points
template <class Real> WM4_FOUNDATION_ITEM
bool Circumscribe (const Vector3<Real>& rkV0, const Vector3<Real>& rkV1,
    const Vector3<Real>& rkV2, const Vector3<Real>& rkV3,
    Sphere3<Real>& rkSphere);

// circle inscribing triangle of three 3D points
template <class Real> WM4_FOUNDATION_ITEM
bool Inscribe (const Vector3<Real>& rkV0, const Vector3<Real>& rkV1,
    const Vector3<Real>& rkV2, Circle3<Real>& rkCircle);

// sphere inscribing tetrahedron of four 3D points
template <class Real> WM4_FOUNDATION_ITEM
bool Inscribe (const Vector3<Real>& rkV0, const Vector3<Real>& rkV1,
    const Vector3<Real>& rkV2, const Vector3<Real>& rkV3,
    Sphere3<Real>& rkSphere);

}

#endif
