// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTVECTOR2ELLIPSE2_H
#define WM4DISTVECTOR2ELLIPSE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Ellipse2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistVector2Ellipse2
    : public Distance<Real,Vector2<Real> >
{
public:
    DistVector2Ellipse2 (const Vector2<Real>& rkVector,
        const Ellipse2<Real>& rkEllipse);

    // object access
    const Vector2<Real>& GetVector () const;
    const Ellipse2<Real>& GetEllipse () const;

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

    const Vector2<Real>& m_rkVector;
    const Ellipse2<Real>& m_rkEllipse;
};

typedef DistVector2Ellipse2<float> DistVector2Ellipse2f;
typedef DistVector2Ellipse2<double> DistVector2Ellipse2d;

}

#endif
