// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4AXISALIGNEDBOX3_H
#define WM4AXISALIGNEDBOX3_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <class Real>
class AxisAlignedBox3
{
public:
    // construction
    AxisAlignedBox3 ();  // uninitialized

    // The caller must ensure that fXMin <= fXMax and fYMin <= fYMax.  The
    // class will not check for validity of the input.
    AxisAlignedBox3 (Real fXMin, Real fXMax, Real fYMin, Real fYMax,
        Real fZMin, Real fZMax);

    // Overlap testing is in the strict sense.  If the two boxes are just
    // touching along a common edge, the boxes are reported as overlapping.
    bool HasXOverlap (const AxisAlignedBox3& rkBox) const;
    bool HasYOverlap (const AxisAlignedBox3& rkBox) const;
    bool HasZOverlap (const AxisAlignedBox3& rkBox) const;
    bool TestIntersection (const AxisAlignedBox3& rkBox) const;

    // The return value is 'true' if there is overlap.  In this case the
    // intersection is stored in rkIntr.  If the return value is 'false',
    // if there is no overlap.  In this case rkIntr is undefined.
    bool FindIntersection (const AxisAlignedBox3& rkBox,
        AxisAlignedBox3& rkIntr) const;

    Real Min[3], Max[3];
};

#include "Wm4AxisAlignedBox3.inl"

typedef AxisAlignedBox3<float> AxisAlignedBox3f;
typedef AxisAlignedBox3<double> AxisAlignedBox3d;

}

#endif
