// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTCIRCLE3CIRCLE3_H
#define WM4DISTCIRCLE3CIRCLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Circle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistCircle3Circle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistCircle3Circle3 (const Circle3<Real>& rkCircle0,
        const Circle3<Real>& rkCircle1);

    // object access
    const Circle3<Real>& GetCircle0 () const;
    const Circle3<Real>& GetCircle1 () const;

    // static distance queries
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

    const Circle3<Real>& m_rkCircle0;
    const Circle3<Real>& m_rkCircle1;
};

typedef DistCircle3Circle3<float> DistCircle3Circle3f;
typedef DistCircle3Circle3<double> DistCircle3Circle3d;

}

#endif
