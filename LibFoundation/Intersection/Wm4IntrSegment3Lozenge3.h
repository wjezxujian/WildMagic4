// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSEGMENT3LOZENGE3_H
#define WM4INTRSEGMENT3LOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Segment3.h"
#include "Wm4Lozenge3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSegment3Lozenge3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrSegment3Lozenge3 (const Segment3<Real>& rkSegment,
        const Lozenge3<Real>& rkLozenge);

    // object access
    const Segment3<Real>& GetSegment () const;
    const Lozenge3<Real>& GetLozenge () const;

    // static intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Segment3<Real>& m_rkSegment;
    const Lozenge3<Real>& m_rkLozenge;
};

typedef IntrSegment3Lozenge3<float> IntrSegment3Lozenge3f;
typedef IntrSegment3Lozenge3<double> IntrSegment3Lozenge3d;

}

#endif
