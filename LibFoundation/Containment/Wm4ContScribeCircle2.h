// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTSCRIBECIRCLE2_H
#define WM4CONTSCRIBECIRCLE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Circle2.h"
#include "Wm4LinearSystem.h"

namespace Wm4
{

// All functions return 'true' if circle has been constructed, 'false'
// otherwise (input points are linearly dependent).

// circle containing three 2D points
template <class Real> WM4_FOUNDATION_ITEM
bool Circumscribe (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
    const Vector2<Real>& rkV2, Circle2<Real>& rkCircle);

// circle inscribing triangle of three 2D points
template <class Real> WM4_FOUNDATION_ITEM
bool Inscribe (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
    const Vector2<Real>& rkV2, Circle2<Real>& rkCircle);

}

#endif
