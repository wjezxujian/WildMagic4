// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4LINE3_H
#define WM4LINE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector3.h"

namespace Wm4
{

template <class Real>
class Line3
{
public:
    // The line is represented as P+t*D where P is the line origin and D is
    // a unit-length direction vector.  The user must ensure that the
    // direction vector satisfies this condition.

    // construction
    Line3 ();  // uninitialized
    Line3 (const Vector3<Real>& rkOrigin, const Vector3<Real>& rkDirection);

    Vector3<Real> Origin, Direction;
};

#include "Wm4Line3.inl"

typedef Line3<float> Line3f;
typedef Line3<double> Line3d;

}

#endif
