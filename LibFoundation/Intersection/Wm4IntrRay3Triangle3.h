// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY3TRIANGLE3_H
#define WM4INTRRAY3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Triangle3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Triangle3 (const Ray3<Real>& rkRay,
        const Triangle3<Real>& rkTriangle);

    // object access
    const Ray3<Real>& GetRay () const;
    const Triangle3<Real>& GetTriangle () const;

    // test-intersection query
    virtual bool Test ();

    // Find-intersection query.  The point of intersection is
    //   P = origin + t*direction = b0*V0 + b1*V1 + b2*V2
    virtual bool Find ();
    Real GetRayT () const;
    Real GetTriB0 () const;
    Real GetTriB1 () const;
    Real GetTriB2 () const;

private:
    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Triangle3<Real>& m_rkTriangle;

    // information about the intersection set
    Real m_fRayT, m_fTriB0, m_fTriB1, m_fTriB2;
};

typedef IntrRay3Triangle3<float> IntrRay3Triangle3f;
typedef IntrRay3Triangle3<double> IntrRay3Triangle3d;

}

#endif
