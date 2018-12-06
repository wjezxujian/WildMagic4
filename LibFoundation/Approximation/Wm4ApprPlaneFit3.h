// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4APPRPLANEFIT3_H
#define WM4APPRPLANEFIT3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Plane3.h"

namespace Wm4
{

// Least-squares fit of a plane to (x,y,f(x,y)) data by using distance
// measurements in the z-direction.  The resulting plane is represented by
// z = A*x + B*y + C.  The return value is 'false' if the 3x3 coefficient
// matrix in the linear system that defines A, B, and C is (nearly) singular.
// In this case, A, B, and C are returned as MAX_REAL.
template <class Real> WM4_FOUNDATION_ITEM
bool HeightPlaneFit3 (int iQuantity, const Vector3<Real>* akPoint,
    Real& rfA, Real& rfB, Real& rfC);

// Least-squares fit of a plane to (x,y,z) data by using distance measurements
// orthogonal to the proposed plane.
template <class Real> WM4_FOUNDATION_ITEM
Plane3<Real> OrthogonalPlaneFit3 (int iQuantity,
    const Vector3<Real>* akPoint);

}

#endif
