// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4APPRLINEFIT2_H
#define WM4APPRLINEFIT2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Line2.h"

namespace Wm4
{

// Least-squares fit of a line to (x,f(x)) data by using distance
// measurements in the y-direction.  The resulting line is represented by
// y = A*x + B.  The return value is 'false' if the 2x2 coefficient matrix
// in the linear system that defines A and B is (nearly) singular.  In this
// case, A and B are returned as MAX_REAL.
template <class Real> WM4_FOUNDATION_ITEM
bool HeightLineFit2 (int iQuantity, const Vector2<Real>* akPoint, Real& rfA,
    Real& rfB);

// Least-squares fit of a line to (x,y,z) data by using distance measurements
// orthogonal to the proposed line.
template <class Real> WM4_FOUNDATION_ITEM
Line2<Real> OrthogonalLineFit2 (int iQuantity, const Vector2<Real>* akPoint);

}

#endif
