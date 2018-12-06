// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTLINE3CIRCLE3_H
#define WM4DISTLINE3CIRCLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Line3.h"
#include "Wm4Circle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistLine3Circle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistLine3Circle3 (const Line3<Real>& rkLine,
        const Circle3<Real>& rkCircle);

    // object access
    const Line3<Real>& GetLine () const;
    const Circle3<Real>& GetCircle () const;

    // Static distance queries.  Compute the distance from the point P to the
    // circle.  When P is on the normal line C+t*N where C is the circle
    // center and N is the normal to the plane containing the circle, then
    // all circle points are equidistant from P.  In this case the returned
    // point is (infinity,infinity,infinity).
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Line3<Real>& m_rkLine;
    const Circle3<Real>& m_rkCircle;
};

typedef DistLine3Circle3<float> DistLine3Circle3f;
typedef DistLine3Circle3<double> DistLine3Circle3d;

}

#endif
