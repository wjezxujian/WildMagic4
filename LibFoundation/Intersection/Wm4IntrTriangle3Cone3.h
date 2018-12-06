// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRTRIANGLE3CONE3_H
#define WM4INTRTRIANGLE3CONE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Triangle3.h"
#include "Wm4Cone3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrTriangle3Cone3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrTriangle3Cone3 (const Triangle3<Real>& rkTriangle,
        const Cone3<Real>& rkCone);

    // object access
    const Triangle3<Real>& GetTriangle () const;
    const Cone3<Real>& GetCone () const;

    // static query
    virtual bool Test ();

private:
    // the objects to intersect
    const Triangle3<Real>& m_rkTriangle;
    const Cone3<Real>& m_rkCone;
};

typedef IntrTriangle3Cone3<float> IntrTriangle3Cone3f;
typedef IntrTriangle3Cone3<double> IntrTriangle3Cone3d;

}

#endif
