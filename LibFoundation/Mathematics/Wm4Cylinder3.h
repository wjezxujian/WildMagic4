// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CYLINDER3_H
#define WM4CYLINDER3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Segment3.h"

namespace Wm4
{

template <class Real>
class Cylinder3
{
public:
    // Cylinder line segment has end points C-(H/2)*D and C+(H/2)*D where
    // D is a unit-length vector.  H is infinity for infinite cylinder.

    // construction
    Cylinder3 ();  // uninitialized
    Cylinder3 (const Segment3<Real>& rkSegment, Real fHeight, Real fRadius);

    Segment3<Real> Segment;
    Real Height, Radius;
};

#include "Wm4Cylinder3.inl"

typedef Cylinder3<float> Cylinder3f;
typedef Cylinder3<double> Cylinder3d;

}

#endif
