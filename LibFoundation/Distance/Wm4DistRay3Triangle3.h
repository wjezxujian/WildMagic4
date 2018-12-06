// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTRAY3TRIANGLE3_H
#define WM4DISTRAY3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ray3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistRay3Triangle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistRay3Triangle3 (const Ray3<Real>& rkRay,
        const Triangle3<Real>& rkTriangle);

    // object access
    const Ray3<Real>& GetRay () const;
    const Triangle3<Real>& GetTriangle () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest points.
    Real GetRayParameter () const;
    Real GetTriangleBary (int i) const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Ray3<Real>& m_rkRay;
    const Triangle3<Real>& m_rkTriangle;

    // Information about the closest points.
    Real m_fRayParameter;  // closest0 = ray.origin+param*ray.direction
    Real m_afTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
};

typedef DistRay3Triangle3<float> DistRay3Triangle3f;
typedef DistRay3Triangle3<double> DistRay3Triangle3d;

}

#endif
