// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CAPSULE3_H
#define WM4CAPSULE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Segment3.h"

namespace Wm4
{

template <class Real>
class Capsule3
{
public:
    // construction
    Capsule3 ();  // uninitialized
    Capsule3 (const Segment3<Real>& rkSegment, Real fRadius);

    Segment3<Real> Segment;
    Real Radius;
};

#include "Wm4Capsule3.inl"

typedef Capsule3<float> Capsule3f;
typedef Capsule3<double> Capsule3d;

}

#endif
