// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRLINE2ARC2_H
#define WM4INTRLINE2ARC2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Line2.h"
#include "Wm4Arc2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrLine2Arc2
    : public Intersector<Real,Vector2<Real> >
{
public:
    IntrLine2Arc2 (const Line2<Real>& rkLine, const Arc2<Real>& rkArc);

    // object access
    const Line2<Real>& GetLine () const;
    const Arc2<Real>& GetArc () const;

    // static intersection query
    virtual bool Find ();

    // the intersection set
    int GetQuantity () const;
    const Vector2<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector2<Real> >::IT_EMPTY;
    using Intersector<Real,Vector2<Real> >::IT_POINT;
    using Intersector<Real,Vector2<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Line2<Real>& m_rkLine;
    const Arc2<Real>& m_rkArc;

    // information about the intersection set
    int m_iQuantity;
    Vector2<Real> m_akPoint[2];
};

typedef IntrLine2Arc2<float> IntrLine2Arc2f;
typedef IntrLine2Arc2<double> IntrLine2Arc2d;

}

#endif
