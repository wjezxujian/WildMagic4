// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTRAY2RAY2_H
#define WM4DISTRAY2RAY2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ray2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistRay2Ray2 : public Distance<Real,Vector2<Real> >
{
public:
    DistRay2Ray2 (const Ray2<Real>& rkRay0, const Ray2<Real>& rkRay1);

    // object access
    const Ray2<Real>& GetRay0 () const;
    const Ray2<Real>& GetRay1 () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector2<Real>& rkVelocity0,
        const Vector2<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector2<Real>& rkVelocity0,
        const Vector2<Real>& rkVelocity1);

private:
    using Distance<Real,Vector2<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector2<Real> >::m_kClosestPoint1;

    const Ray2<Real>& m_rkRay0;
    const Ray2<Real>& m_rkRay1;
};

typedef DistRay2Ray2<float> DistRay2Ray2f;
typedef DistRay2Ray2<double> DistRay2Ray2d;

}

#endif
