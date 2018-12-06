// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4LINE2_H
#define WM4LINE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class Line2
{
public:
    // The line is represented as P+t*D where P is the line origin and D is
    // a unit-length direction vector.  The user must ensure that the
    // direction vector satisfies this condition.

    // construction
    Line2 ();  // uninitialized
    Line2 (const Vector2<Real>& rkOrigin, const Vector2<Real>& rkDirection);

    Vector2<Real> Origin, Direction;
};

#include "Wm4Line2.inl"

typedef Line2<float> Line2f;
typedef Line2<double> Line2d;

}

#endif
