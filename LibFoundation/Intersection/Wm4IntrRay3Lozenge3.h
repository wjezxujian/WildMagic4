// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRRAY3LOZENGE3_H
#define WM4INTRRAY3LOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Ray3.h"
#include "Wm4Lozenge3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrRay3Lozenge3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrRay3Lozenge3 (const Ray3<Real>& rkRay,
        const Lozenge3<Real>& rkLozenge);

    // object access
    const Ray3<Real>& GetRay () const;
    const Lozenge3<Real>& GetLozenge () const;

    // static intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Ray3<Real>& m_rkRay;
    const Lozenge3<Real>& m_rkLozenge;
};

typedef IntrRay3Lozenge3<float> IntrRay3Lozenge3f;
typedef IntrRay3Lozenge3<double> IntrRay3Lozenge3d;

}

#endif
