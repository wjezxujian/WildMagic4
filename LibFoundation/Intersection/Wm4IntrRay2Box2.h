// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY2BOX2_H
#define WM4INTRRAY2BOX2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray2.h"
#include "Wm4Box2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay2Box2
    : public Intersector<Real,Vector2<Real> >
{
public:
    IntrRay2Box2 (const Ray2<Real>& rkRay, const Box2<Real>& rkBox);

    // object access
    const Ray2<Real>& GetRay () const;
    const Box2<Real>& GetBox () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    // the intersection set
    int GetQuantity () const;
    const Vector2<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector2<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Ray2<Real>& m_rkRay;
    const Box2<Real>& m_rkBox;

    // information about the intersection set
    int m_iQuantity;
    Vector2<Real> m_akPoint[2];
};

typedef IntrRay2Box2<float> IntrRay2Box2f;
typedef IntrRay2Box2<double> IntrRay2Box2d;

}

#endif
