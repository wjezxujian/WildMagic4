// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTLOZENGE3_H
#define WM4CONTLOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Lozenge3.h"

namespace Wm4
{

// Compute plane of lozenge rectangle using least-squares fit.  Parallel
// planes are chosen close enough together so that all the data points lie
// between them.  The radius is half the distance between the two planes.
// The half-cylinder and quarter-cylinder side pieces are chosen using a
// method similar to that used for fitting by capsules.
template <class Real> WM4_FOUNDATION_ITEM
Lozenge3<Real> ContLozenge (int iQuantity, const Vector3<Real>* akPoint);

// Test for containment of a point x by a lozenge.
template <class Real> WM4_FOUNDATION_ITEM
bool InLozenge (const Vector3<Real>& rkPoint,
    const Lozenge3<Real>& rkLozenge);

}

#endif
