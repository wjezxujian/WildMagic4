// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY3CAPSULE3_H
#define WM4INTRRAY3CAPSULE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4Capsule3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Capsule3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Capsule3 (const Ray3<Real>& rkRay,
        const Capsule3<Real>& rkCapsule);

    // object access
    const Ray3<Real>& GetRay () const;
    const Capsule3<Real>& GetCapsule () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_POINT;
    using Intersector<Real,Vector3<Real> >::IT_SEGMENT;
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Capsule3<Real>& m_rkCapsule;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
};

typedef IntrRay3Capsule3<float> IntrRay3Capsule3f;
typedef IntrRay3Capsule3<double> IntrRay3Capsule3d;

}

#endif
