// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRLINCOMP2TRIANGLE2_H
#define WM4INTRLINCOMP2TRIANGLE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4LinComp2.h"
#include "Wm4Triangle2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrLinComp2Triangle2
    : public Intersector<Real,Vector2<Real> >
{
public:
    IntrLinComp2Triangle2 (const LinComp2<Real>& rkComponent,
        const Triangle2<Real>& rkTriangle);

    // object access
    const LinComp2<Real>& GetComponent () const;
    const Triangle2<Real>& GetTriangle () const;

    // static intersection queries
    virtual bool Test ();
    virtual bool Find ();

    // Information about the intersection set.  GetIntersectionType() returns
    // IT_EMPTY, IT_POINT, or IT_SEGMENT.
    const LinComp2<Real>& GetIntersectionComponent() const;

protected:
    using Intersector<Real,Vector2<Real> >::IT_EMPTY;
    using Intersector<Real,Vector2<Real> >::IT_POINT;
    using Intersector<Real,Vector2<Real> >::IT_SEGMENT;
    using Intersector<Real,Vector2<Real> >::m_iIntersectionType;

    // Determine how the triangle and line intersect (if at all).
    void TriangleLineRelations (Real afDist[3], int aiSign[3],
        int& riPositive, int& riNegative, int& riZero);

    // Compute the parameter interval for the segment of intersection when
    // the triangle transversely intersects the line.
    void GetInterval (const Real afDist[3], const int aiSign[3],
        Real afParam[2]);

    // the objects to intersect
    const LinComp2<Real>& m_rkComponent;
    const Triangle2<Real>& m_rkTriangle;

    // information about the intersection set
    LinComp2<Real> m_kIntrComponent;
};

typedef IntrLinComp2Triangle2<float> IntrLinComp2Triangle2f;
typedef IntrLinComp2Triangle2<double> IntrLinComp2Triangle2d;

}

#endif
