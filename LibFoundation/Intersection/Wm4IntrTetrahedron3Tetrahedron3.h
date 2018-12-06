// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRTETRAHEDRON3TETRAHEDRON3_H
#define WM4INTRTETRAHEDRON3TETRAHEDRON3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Tetrahedron3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrTetrahedron3Tetrahedron3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrTetrahedron3Tetrahedron3 (const Tetrahedron3<Real>& rkTetrahedron0,
        const Tetrahedron3<Real>& rkTetrahedron1);

    // object access
    const Tetrahedron3<Real>& GetTetrahedron0 () const;
    const Tetrahedron3<Real>& GetTetrahedron1 () const;

    // static query
    virtual bool Find ();

    // information about the intersection set
    const std::vector<Tetrahedron3<Real> >& GetIntersection () const;

private:
    static void SplitAndDecompose (Tetrahedron3<Real> kTetra,
        const Plane3<Real>& rkPlane,
        std::vector<Tetrahedron3<Real> >& rkInside);

    // the objects to intersect
    const Tetrahedron3<Real>& m_rkTetrahedron0;
    const Tetrahedron3<Real>& m_rkTetrahedron1;

    std::vector<Tetrahedron3<Real> > m_kIntersection;
};

typedef IntrTetrahedron3Tetrahedron3<float> IntrTetrahedron3Tetrahedron3f;
typedef IntrTetrahedron3Tetrahedron3<double> IntrTetrahedron3Tetrahedron3d;

}

#endif
