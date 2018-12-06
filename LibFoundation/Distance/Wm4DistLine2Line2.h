// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTLINE2LINE2_H
#define WM4DISTLINE2LINE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Line2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistLine2Line2
    : public Distance<Real,Vector2<Real> >
{
public:
    DistLine2Line2 (const Line2<Real>& rkLine0, const Line2<Real>& rkLine1);

    // object access
    const Line2<Real>& GetLine0 () const;
    const Line2<Real>& GetLine1 () const;

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

    const Line2<Real>& m_rkLine0;
    const Line2<Real>& m_rkLine1;
};

typedef DistLine2Line2<float> DistLine2Line2f;
typedef DistLine2Line2<double> DistLine2Line2d;

}

#endif
