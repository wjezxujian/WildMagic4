// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSEGMENT3TRIANGLE3_H
#define WM4INTRSEGMENT3TRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Segment3.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSegment3Triangle3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrSegment3Triangle3 (const Segment3<Real>& rkSegment,
        const Triangle3<Real>& rkTriangle);

    // object access
    const Segment3<Real>& GetSegment () const;
    const Triangle3<Real>& GetTriangle () const;

    // test-intersection query
    virtual bool Test ();

    // Find-intersection query.  The point of intersection is
    //   P = origin + t*direction = b0*V0 + b1*V1 + b2*V2
    virtual bool Find ();
    Real GetSegmentT () const;
    Real GetTriB0 () const;
    Real GetTriB1 () const;
    Real GetTriB2 () const;

private:
    // the objects to intersect
    const Segment3<Real>& m_rkSegment;
    const Triangle3<Real>& m_rkTriangle;

    // information about the intersection set
    Real m_fSegmentT, m_fTriB0, m_fTriB1, m_fTriB2;
};

typedef IntrSegment3Triangle3<float> IntrSegment3Triangle3f;
typedef IntrSegment3Triangle3<double> IntrSegment3Triangle3d;

}

#endif
