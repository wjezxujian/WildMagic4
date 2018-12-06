// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSEGMENT3BOX3_H
#define WM4INTRSEGMENT3BOX3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Segment3.h"
#include "Wm4Box3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSegment3Box3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrSegment3Box3 (const Segment3<Real>& rkSegment,
        const Box3<Real>& rkBox, bool bSolid);

    // object access
    const Segment3<Real>& GetSegment () const;
    const Box3<Real>& GetBox () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    // the intersection set
    int GetQuantity () const;
    const Vector3<Real>& GetPoint (int i) const;

private:
    using Intersector<Real,Vector3<Real> >::m_iIntersectionType;

    // the objects to intersect
    const Segment3<Real>& m_rkSegment;
    const Box3<Real>& m_rkBox;
    bool m_bSolid;

    // information about the intersection set
    int m_iQuantity;
    Vector3<Real> m_akPoint[2];
};

typedef IntrSegment3Box3<float> IntrSegment3Box3f;
typedef IntrSegment3Box3<double> IntrSegment3Box3d;

}

#endif
