// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTELLIPSOID3_H
#define WM4CONTELLIPSOID3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Ellipsoid3.h"
#include "Wm4Line3.h"

namespace Wm4
{

// The input points are fit with a Gaussian distribution.  The center C of the
// ellipsoid is chosen to be the mean of the distribution.  The axes of the
// ellipsoid are chosen to be the eigenvectors of the covariance matrix M.
// The shape of the ellipsoid is determined by the absolute values of the
// eigenvalues.
//
// WARNING.  The construction is ill-conditioned if the points are (nearly)
// collinear or (nearly) planar.  In this case M has a (nearly) zero
// eigenvalue, so inverting M is problematic.
template <class Real> WM4_FOUNDATION_ITEM
Ellipsoid3<Real> ContEllipsoid (int iQuantity, const Vector3<Real>* akPoint);

// Project an ellipsoid onto a line.  The projection interval is [min,max]
// and corresponds to the line segment P+t*D, where min <= t <= max.
template <class Real> WM4_FOUNDATION_ITEM
void ProjectEllipsoid (const Ellipsoid3<Real>& rkEllipsoid,
   const Line3<Real>& rkLine, Real& rfMin, Real& rfMax);

// Construct a bounding ellipsoid for the two input ellipsoids.
template <class Real> WM4_FOUNDATION_ITEM
const Ellipsoid3<Real> MergeEllipsoids (const Ellipsoid3<Real>& rkEllipsoid0,
    const Ellipsoid3<Real>& rkEllipsoid1);

}

#endif
