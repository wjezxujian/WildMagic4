// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4ARC2_H
#define WM4ARC2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Circle2.h"

namespace Wm4
{

template <class Real>
class Arc2 : public Circle2<Real>
{
public:
    // The arc is defined by two points End0 and End1 on the circle so that
    // End1 is obtained from End0 by traversing counterclockwise.  The
    // application is responsible for ensuring that End0 and End1 are on the
    // circle and that they are properly ordered.

    Arc2 ();  // uninitialized
    Arc2 (const Vector2<Real>& rkCenter, Real fRadius,
        const Vector2<Real>& rkEnd0, const Vector2<Real>& rkEnd1);

    // Test if P is on the arc.  The application must ensure that P is on the
    // circle; that is, |P-C| = R.  This test works regardless of the angle
    // between B-C and A-C.
    bool Contains (const Vector2<Real>& rkP) const;

    Vector2<Real> End0, End1;
};

#include "Wm4Arc2.inl"

typedef Arc2<float> Arc2f;
typedef Arc2<double> Arc2d;

}

#endif
