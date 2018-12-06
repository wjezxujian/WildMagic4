// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CIRCLE2_H
#define WM4CIRCLE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class Circle2
{
public:
    // construction
    Circle2 ();  // uninitialized
    Circle2 (const Vector2<Real>& rkCenter, Real fRadius);

    Vector2<Real> Center;
    Real Radius;
};

#include "Wm4Circle2.inl"

typedef Circle2<float> Circle2f;
typedef Circle2<double> Circle2d;

}

#endif
