// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY3BOX3_H
#define WM4INTRRAY3BOX3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4IntrLine3Box3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Box3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Box3 (const Ray3<Real>& rkRay, const Box3<Real>& rkBox);

    // object access
    const Ray3<Real>& GetRay () const;
    const Box3<Real>& GetBox () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    // the intersection set
    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Box3<Real>& m_rkBox;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
};

typedef IntrRay3Box3<float> IntrRay3Box3f;
typedef IntrRay3Box3<double> IntrRay3Box3d;

}

#endif
