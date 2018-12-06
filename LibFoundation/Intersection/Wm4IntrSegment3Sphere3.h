// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSEGMENT3SPHERE3_H
#define WM4INTRSEGMENT3SPHERE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Segment3.h"
#include "Wm4Sphere3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSegment3Sphere3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrSegment3Sphere3 (const Segment3<Real>& rkSegment,
        const Sphere3<Real>& rkSphere);

    // object access
    const Segment3<Real>& GetSegment () const;
    const Sphere3<Real>& GetSphere () const;

    // test-intersection query
    virtual bool Test ();

    // find-intersection query
    virtual bool Find ();
    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;
    Real GetSegmentT (int i) const;

    // dynamic test-intersection query
    virtual bool Test (Real fTMax, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    // Dynamic find-intersection query.  The first point of contact is
    // accessed by GetPoint(0).  The first time of contact is accessed by
    // GetContactTime().
    virtual bool Find (Real fTMax, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

    Real ZeroThreshold;  // default = Math<Real>::ZERO_TOLERANCE

private:
    using Intersector<Real,Vector3<Real> >::IT_EMPTY;
    using Intersector<Real,Vector3<Real> >::IT_OTHER;
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;
    using Intersector<Real,Vector3<Real> >::m_fContactTime;

    // the objects to intersect
    const Segment3<Real>& m_rkSegment;
    const Sphere3<Real>& m_rkSphere;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
    Real m_afSegmentT[2];
};

typedef IntrSegment3Sphere3<float> IntrSegment3Sphere3f;
typedef IntrSegment3Sphere3<double> IntrSegment3Sphere3d;

}

#endif
