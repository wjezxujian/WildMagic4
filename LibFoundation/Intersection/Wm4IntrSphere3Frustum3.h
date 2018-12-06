// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRSPHERE3FRUSTUM3_H
#define WM4INTRSPHERE3FRUSTUM3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Sphere3.h"
#include "Wm4Frustum3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrSphere3Frustum3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrSphere3Frustum3 (const Sphere3<Real>& rkSphere,
        const Frustum3<Real>& rkFrustum);

    // object access
    const Sphere3<Real>& GetSphere () const;
    const Frustum3<Real>& GetFrustum () const;

    // static intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Sphere3<Real>& m_rkSphere;
    const Frustum3<Real>& m_rkFrustum;
};

typedef IntrSphere3Frustum3<float> IntrSphere3Frustum3f;
typedef IntrSphere3Frustum3<double> IntrSphere3Frustum3d;

}

#endif
