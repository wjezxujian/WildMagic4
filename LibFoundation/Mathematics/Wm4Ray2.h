// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RAY2_H
#define WM4RAY2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class Ray2
{
public:
    // The ray is represented as P+t*D, where P is the ray origin, D is a
    // unit-length direction vector, and t >= 0.  The user must ensure that
    // the direction vector satisfies this condition.

    // construction
    Ray2 ();  // uninitialized
    Ray2 (const Vector2<Real>& rkOrigin, const Vector2<Real>& rkDirection);

    Vector2<Real> Origin, Direction;
};

#include "Wm4Ray2.inl"

typedef Ray2<float> Ray2f;
typedef Ray2<double> Ray2d;

}

#endif
