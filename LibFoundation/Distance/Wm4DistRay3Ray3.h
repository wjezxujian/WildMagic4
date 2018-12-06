// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTRAY3RAY3_H
#define WM4DISTRAY3RAY3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ray3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistRay3Ray3 : public Distance<Real,Vector3<Real> >
{
public:
    DistRay3Ray3 (const Ray3<Real>& rkRay0, const Ray3<Real>& rkRay1);

    // object access
    const Ray3<Real>& GetRay0 () const;
    const Ray3<Real>& GetRay1 () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest points.
    Real GetRay0Parameter () const;
    Real GetRay1Parameter () const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Ray3<Real>& m_rkRay0;
    const Ray3<Real>& m_rkRay1;

    // Information about the closest points.
    Real m_fRay0Parameter;  // closest0 = ray0.origin+param*ray0.direction
    Real m_fRay1Parameter;  // closest1 = ray1.origin+param*ray1.direction
};

typedef DistRay3Ray3<float> DistRay3Ray3f;
typedef DistRay3Ray3<double> DistRay3Ray3d;

}

#endif
