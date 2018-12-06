// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTLINE2SEGMENT2_H
#define WM4DISTLINE2SEGMENT2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Line2.h"
#include "Wm4Segment2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistLine2Segment2
    : public Distance<Real,Vector2<Real> >
{
public:
    DistLine2Segment2 (const Line2<Real>& rkLine,
        const Segment2<Real>& rkSegment);

    // object access
    const Line2<Real>& GetLine () const;
    const Segment2<Real>& GetSegment () const;

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

    const Line2<Real>& m_rkLine;
    const Segment2<Real>& m_rkSegment;
};

typedef DistLine2Segment2<float> DistLine2Segment2f;
typedef DistLine2Segment2<double> DistLine2Segment2d;

}

#endif
