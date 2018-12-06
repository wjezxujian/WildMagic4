// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PLANE3_H
#define WM4PLANE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Vector3.h"

namespace Wm4
{

template <class Real>
class Plane3
{
public:
    // The plane is represented as Dot(N,X) = c where N is a unit-length
    // normal vector, c is the plane constant, and X is any point on the
    // plane.  The user must ensure that the normal vector satisfies this
    // condition.

    Plane3 ();  // uninitialized
    Plane3 (const Plane3& rkPlane);

    // specify N and c directly
    Plane3 (const Vector3<Real>& rkNormal, Real fConstant);

    // N is specified, c = Dot(N,P) where P is on the plane
    Plane3 (const Vector3<Real>& rkNormal, const Vector3<Real>& rkP);

    // N = Cross(P1-P0,P2-P0)/Length(Cross(P1-P0,P2-P0)), c = Dot(N,P0) where
    // P0, P1, P2 are points on the plane.
    Plane3 (const Vector3<Real>& rkP0, const Vector3<Real>& rkP1,
        const Vector3<Real>& rkP2);

    // assignment
    Plane3& operator= (const Plane3& rkPlane);

    // The "positive side" of the plane is the half space to which the plane
    // normal points.  The "negative side" is the other half space.  The
    // function returns +1 for the positive side, -1 for the negative side,
    // and 0 for the point being on the plane.
    int WhichSide (const Vector3<Real>& rkP) const;

    // Compute d = Dot(N,Q)-c where N is the plane normal and c is the plane
    // constant.  This is a signed distance.  The sign of the return value is
    // positive if the point is on the positive side of the plane, negative if
    // the point is on the negative side, and zero if the point is on the
    // plane.
    Real DistanceTo (const Vector3<Real>& rkQ) const;

    Vector3<Real> Normal;
    Real Constant;
};

#include "Wm4Plane3.inl"

typedef Plane3<float> Plane3f;
typedef Plane3<double> Plane3d;

}

#endif
