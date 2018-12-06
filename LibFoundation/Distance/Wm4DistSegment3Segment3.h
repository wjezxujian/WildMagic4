// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DISTSEGMENT3SEGMENT3_H
#define WM4DISTSEGMENT3SEGMENT3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Distance.h"
#include "Wm4Segment3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DistSegment3Segment3
    : public Distance<Real,Vector3<Real> >
{
public:
    DistSegment3Segment3 (const Segment3<Real>& rkSegment0,
        const Segment3<Real>& rkSegment1);

    // object access
    const Segment3<Real>& GetSegment0 () const;
    const Segment3<Real>& GetSegment1 () const;

    // static distance queries
    virtual Real Get ();
    virtual Real GetSquared ();

    // function calculations for dynamic distance queries
    virtual Real Get (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);
    virtual Real GetSquared (Real fT, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Information about the closest points.
    Real GetSegment0Parameter () const;
    Real GetSegment1Parameter () const;

private:
    using Distance<Real,Vector3<Real> >::m_kClosestPoint0;
    using Distance<Real,Vector3<Real> >::m_kClosestPoint1;

    const Segment3<Real>& m_rkSegment0;
    const Segment3<Real>& m_rkSegment1;

    // Information about the closest points.
    Real m_fSegment0Parameter;  // closest0 = seg0.origin+param*seg0.direction
    Real m_fSegment1Parameter;  // closest1 = seg1.origin+param*seg1.direction
};

typedef DistSegment3Segment3<float> DistSegment3Segment3f;
typedef DistSegment3Segment3<double> DistSegment3Segment3d;

}

#endif
