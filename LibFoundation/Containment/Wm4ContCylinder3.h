// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTCYLINDER3_H
#define WM4CONTCYLINDER3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Cylinder3.h"

namespace Wm4
{

// Compute the cylinder axis segment using least-squares fit.  The radius is
// the maximum distance from points to the axis.  The height is determined by
// projection of points onto the axis and determining the containing interval.
template <class Real> WM4_FOUNDATION_ITEM
Cylinder3<Real> ContCylinder (int iQuantity, const Vector3<Real>* akPoint);

}

#endif
