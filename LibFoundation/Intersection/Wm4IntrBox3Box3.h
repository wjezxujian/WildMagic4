// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRBOX3BOX3_H
#define WM4INTRBOX3BOX3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Box3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrBox3Box3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrBox3Box3 (const Box3<Real>& rkBox0, const Box3<Real>& rkBox1);

    // object access
    const Box3<Real>& GetBox0 () const;
    const Box3<Real>& GetBox1 () const;

    // static test-intersection query
    virtual bool Test ();

    // Dynamic test-intersection query.  The first time of contact (if any)
    // is computed, but not any information about the contact set.
    virtual bool Test (Real fTMax, const Vector3<Real>& rkVelocity0,
        const Vector3<Real>& rkVelocity1);

private:
    using Intersector<Real,Vector3<Real> >::m_fContactTime;

    // Support for dynamic queries.  The inputs are the projection intervals
    // for the boxes onto a potential separating axis, the relative speed of
    // the intervals, and the maximum time for the query.  The outputs are
    // the first time when separating fails and the last time when separation
    // begins again along that axis.  The outputs are *updates* in the sense
    // that this function is called repeatedly for the potential separating
    // axes.  The output first time is updated only if it is larger than
    // the input first time.  The output last time is updated only if it is
    // smaller than the input last time.
    bool IsSeparated (Real fMin0, Real fMax0, Real fMin1, Real fMax1,
        Real fSpeed, Real fTMax, Real& rfTFirst, Real& rfTLast);

    // the objects to intersect
    const Box3<Real>& m_rkBox0;
    const Box3<Real>& m_rkBox1;
};

typedef IntrBox3Box3<float> IntrBox3Box3f;
typedef IntrBox3Box3<double> IntrBox3Box3d;

}

#endif
