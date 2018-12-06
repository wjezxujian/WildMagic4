// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRPLANE3CYLINDER3_H
#define WM4INTRPLANE3CYLINDER3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Plane3.h"
#include "Wm4Cylinder3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrPlane3Cylinder3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrPlane3Cylinder3 (const Plane3<Real>& rkPlane,
        const Cylinder3<Real>& rkCylinder);

    // object access
    const Plane3<Real>& GetPlane () const;
    const Cylinder3<Real>& GetCylinder () const;

    // static intersection query
    virtual bool Test ();

    // Culling support.  The view frustum is assumed to be on the positive
    // side of the plane.  The cylinder is culled if it is on the negative
    // side of the plane.
    bool CylinderIsCulled () const;

protected:
    // the objects to intersect
    const Plane3<Real>& m_rkPlane;
    const Cylinder3<Real>& m_rkCylinder;
};

typedef IntrPlane3Cylinder3<float> IntrPlane3Cylinder3f;
typedef IntrPlane3Cylinder3<double> IntrPlane3Cylinder3d;

}

#endif
