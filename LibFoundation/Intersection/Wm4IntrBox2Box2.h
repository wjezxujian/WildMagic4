// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRBOX2BOX2_H
#define WM4INTRBOX2BOX2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Box2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrBox2Box2
    : public Intersector<Real,Vector2<Real> >
{
public:
    IntrBox2Box2 (const Box2<Real>& rkBox0, const Box2<Real>& rkBox1);

    // object access
    const Box2<Real>& GetBox0 () const;
    const Box2<Real>& GetBox1 () const;

    // static test-intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Box2<Real>& m_rkBox0;
    const Box2<Real>& m_rkBox1;
};

typedef IntrBox2Box2<float> IntrBox2Box2f;
typedef IntrBox2Box2<double> IntrBox2Box2d;

}

#endif
