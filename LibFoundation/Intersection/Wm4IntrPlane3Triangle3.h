// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRPLANE3TRIANGLE3_H
#define WM4INTRPLANE3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Plane3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrPlane3Triangle3
    : public Intersector<Real,Vector3<Real> >
{
public:
    // If you want a fuzzy determination, set the epsilon value to a small
    // positive number.
    IntrPlane3Triangle3 (const Plane3<Real>& rkPlane,
        const Triangle3<Real>& rkTriangle, Real fEpsilon = (Real)0.0);

    // object access
    const Plane3<Real>& GetPlane () const;
    const Triangle3<Real>& GetTriangle () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    // The intersection set, which is empty, a point, a line segment, or the
    // entire triangle (GetQuantity returns 0, 1, 2, or 3).
    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;

protected:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_POINT;
    using Intersector<Real,Vector3<Real> >::IT_SEGMENT;
    using Intersector<Real,Vector3<Real> >::IT_POLYGON;
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Plane3<Real>& m_rkPlane;
    const Triangle3<Real>& m_rkTriangle;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[3];

    // for fuzzy arithmetic
    Real m_fEpsilon;
};

typedef IntrPlane3Triangle3<float> IntrPlane3Triangle3f;
typedef IntrPlane3Triangle3<double> IntrPlane3Triangle3d;

}

#endif
