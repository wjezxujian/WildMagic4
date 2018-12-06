// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTTRIANGLE3RECTANGLE3_H
#define WM4DISTTRIANGLE3RECTANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Triangle3.h"
#include "Wm4Rectangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistTriangle3Rectangle3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistTriangle3Rectangle3 (const Triangle3<Real>& rkTriangle,
        const Rectangle3<Real>& rkRectangle);

    // object access
    const Triangle3<Real>& GetTriangle () const;
    const Rectangle3<Real>& GetRectangle () const;

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

    const Triangle3<Real>& m_rkTriangle;
    const Rectangle3<Real>& m_rkRectangle;
};

typedef DistTriangle3Rectangle3<float> DistTriangle3Rectangle3f;
typedef DistTriangle3Rectangle3<double> DistTriangle3Rectangle3d;

}

#endif
