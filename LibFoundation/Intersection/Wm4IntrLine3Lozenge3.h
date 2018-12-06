// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTRLINE3LOZENGE3_H
#define WM4INTRLINE3LOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Intersector.h"
#include "Wm4Line3.h"
#include "Wm4Lozenge3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntrLine3Lozenge3
    : public Intersector<Real,Vector3<Real> >
{
public:
    IntrLine3Lozenge3 (const Line3<Real>& rkLine,
        const Lozenge3<Real>& rkLozenge);

    // object access
    const Line3<Real>& GetLine () const;
    const Lozenge3<Real>& GetLozenge () const;

    // static intersection query
    virtual bool Test ();

private:
    // the objects to intersect
    const Line3<Real>& m_rkLine;
    const Lozenge3<Real>& m_rkLozenge;
};

typedef IntrLine3Lozenge3<float> IntrLine3Lozenge3f;
typedef IntrLine3Lozenge3<double> IntrLine3Lozenge3d;

}

#endif
