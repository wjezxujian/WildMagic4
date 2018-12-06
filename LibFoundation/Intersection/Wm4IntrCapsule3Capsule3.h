// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRCAPSULE3CAPSULE3_H
#define WM4INTRCAPSULE3CAPSULE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Capsule3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrCapsule3Capsule3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrCapsule3Capsule3 (const Capsule3<Real>& rkCapsule0,
        const Capsule3<Real>& rkCapsule1);

    // object access
    const Capsule3<Real>& GetCapsule0 () const;
    const Capsule3<Real>& GetCapsule1 () const;

    // static test-intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Capsule3<Real>& m_rkCapsule0;
    const Capsule3<Real>& m_rkCapsule1;
};

typedef IntrCapsule3Capsule3<float> IntrCapsule3Capsule3f;
typedef IntrCapsule3Capsule3<double> IntrCapsule3Capsule3d;

}

#endif
