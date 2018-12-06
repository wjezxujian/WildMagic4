// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRLINE3PLANE3_H
#define WM4INTRLINE3PLANE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Line3.h"
#include "Wm4Plane3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrLine3Plane3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrLine3Plane3 (const Line3<Real>& rkLine, const Plane3<Real>& rkPlane);

    // object access
    const Line3<Real>& GetLine () const;
    const Plane3<Real>& GetPlane () const;

    // test-intersection query
    virtual bool Test ();

    // Find-intersection query.  The point of intersection is
    // P = origin + t*direction.
    virtual bool Find ();
    Real GetLineT () const;

private:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_POINT;
    using Intersector<Real,Vector3<Real> >::IT_LINE;
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Line3<Real>& m_rkLine;
    const Plane3<Real>& m_rkPlane;

    // information about the intersection set
    Real m_fLineT;
};

typedef IntrLine3Plane3<float> IntrLine3Plane3f;
typedef IntrLine3Plane3<double> IntrLine3Plane3d;

}

#endif
