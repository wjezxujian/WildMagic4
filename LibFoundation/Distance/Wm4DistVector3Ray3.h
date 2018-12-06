// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTVECTOR3RAY3_H
#define WM4DISTVECTOR3RAY3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ray3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistVector3Ray3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistVector3Ray3 (const Vector3<Real>& rkVector,
        const Ray3<Real>& rkRay);

    // object access
    const Vector3<Real>& GetVector () const;
    const Ray3<Real>& GetRay () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest line point.
    Real GetRayParameter () const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Vector3<Real>& m_rkVector;
    const Ray3<Real>& m_rkRay;

    // Information about the closest ray point.
    Real m_fRayParameter;  // closest1 = ray.origin+param*ray.direction
};

typedef DistVector3Ray3<float> DistVector3Ray3f;
typedef DistVector3Ray3<double> DistVector3Ray3d;

}

#endif
