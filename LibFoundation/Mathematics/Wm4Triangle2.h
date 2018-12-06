// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TRIANGLE2_H
#define WM4TRIANGLE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class Triangle2
{
public:
    // The triangle is represented as an array of three vertices, V0, V1,
    // and V2.

    // construction
    Triangle2 ();  // uninitialized
    Triangle2 (const Vector2<Real>& rkV0, const Vector2<Real>& rkV1,
        const Vector2<Real>& rkV2);
    Triangle2 (const Vector2<Real> akV[3]);

    // distance from the point Q to the triangle
    Real DistanceTo (const Vector2<Real>& rkQ) const;

    Vector2<Real> V[3];
};

#include "Wm4Triangle2.inl"

typedef Triangle2<float> Triangle2f;
typedef Triangle2<double> Triangle2d;

}

#endif
