// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRBOX3FRUSTUM3_H
#define WM4INTRBOX3FRUSTUM3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Box3.h"
#include "Wm4Frustum3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrBox3Frustum3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrBox3Frustum3 (const Box3<Real>& rkBox,
        const Frustum3<Real>& rkFrustum);

    // object access
    const Box3<Real>& GetBox () const;
    const Frustum3<Real>& GetFrustum () const;

    // test-intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Box3<Real>& m_rkBox;
    const Frustum3<Real>& m_rkFrustum;
};

typedef IntrBox3Frustum3<float> IntrBox3Frustum3f;
typedef IntrBox3Frustum3<double> IntrBox3Frustum3d;

}

#endif
