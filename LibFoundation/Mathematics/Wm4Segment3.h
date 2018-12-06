// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SEGMENT3_H
#define WM4SEGMENT3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector3.h"

namespace Wm4
{

template <class Real>
class Segment3
{
public:
    // The segment is represented as P+t*D, where P is the segment origin,
    // D is a unit-length direction vector and |t| <= e.  The value e is
    // referred to as the extent of the segment.  The end points of the
    // segment are P-e*D and P+e*D.  The user must ensure that the direction
    // vector is unit-length.  The representation for a segment is analogous
    // to that for an oriented bounding box.  P is the center, D is the
    // axis direction, and e is the extent.

    // construction
    Segment3 ();  // uninitialized
    Segment3 (const Vector3<Real>& rkOrigin, const Vector3<Real>& rkDirection,
        Real fExtent);

    // end points
    Vector3<Real> GetPosEnd () const;  // P+e*D
    Vector3<Real> GetNegEnd () const;  // P-e*D

    Vector3<Real> Origin, Direction;
    Real Extent;
};

#include "Wm4Segment3.inl"

typedef Segment3<float> Segment3f;
typedef Segment3<double> Segment3d;

}

#endif
