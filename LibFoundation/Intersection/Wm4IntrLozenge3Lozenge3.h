// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRLOZENGE3LOZENGE3_H
#define WM4INTRLOZENGE3LOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Lozenge3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrLozenge3Lozenge3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrLozenge3Lozenge3 (const Lozenge3<Real>& rkLozenge0,
        const Lozenge3<Real>& rkLozenge1);

    // object access
    const Lozenge3<Real>& GetLozenge0 () const;
    const Lozenge3<Real>& GetLozenge1 () const;

    // static intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Lozenge3<Real>& m_rkLozenge0;
    const Lozenge3<Real>& m_rkLozenge1;
};

typedef IntrLozenge3Lozenge3<float> IntrLozenge3Lozenge3f;
typedef IntrLozenge3Lozenge3<double> IntrLozenge3Lozenge3d;

}

#endif
