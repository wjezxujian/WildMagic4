// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSEGMENT2BOX2_H
#define WM4INTRSEGMENT2BOX2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Segment2.h"
#include "Wm4Box2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSegment2Box2
    : public Intersector<Real,Vector2<Real> >
{
public:
    IntrSegment2Box2 (const Segment2<Real>& rkSegment,
        const Box2<Real>& rkBox, bool bSolid);

    // object access
    const Segment2<Real>& GetSegment () const;
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
    const Segment2<Real>& m_rkSegment;
    const Box2<Real>& m_rkBox;
    bool m_bSolid;

    // information about the intersection set
    int m_iQuantity;
    Vector2<Real> m_akPoint[2];
};

typedef IntrSegment2Box2<float> IntrSegment2Box2f;
typedef IntrSegment2Box2<double> IntrSegment2Box2d;

}

#endif
