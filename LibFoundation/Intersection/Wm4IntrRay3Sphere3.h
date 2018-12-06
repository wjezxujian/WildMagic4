// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY3SPHERE3_H
#define WM4INTRRAY3SPHERE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4Sphere3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Sphere3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Sphere3 (const Ray3<Real>& rkRay, const Sphere3<Real>& rkSphere);

    // object access
    const Ray3<Real>& GetRay () const;
    const Sphere3<Real>& GetSphere () const;

    // test-intersection query
    virtual bool Test ();

    // find-intersection query
    virtual bool Find ();
    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;
    Real GetRayT (int i) const;

private:
    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Sphere3<Real>& m_rkSphere;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
    Real m_afRayT[2];
};

typedef IntrRay3Sphere3<float> IntrRay3Sphere3f;
typedef IntrRay3Sphere3<double> IntrRay3Sphere3d;

}

#endif
