// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4LINCOMP2_H
#define WM4LINCOMP2_H

#include "Wm4FoundationLIB.h"
#include "Wm4LinComp.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class LinComp2 : public LinComp<Real>
{
public:
    // P is set to (0,0), D is set to (0,0), and [min,max] is set to
    // [MAX_REAL,-MAX_REAL].  The type is CT_EMPTY.
    LinComp2 ();

    // P and D are specified.  D must be unit length.
    LinComp2 (const Vector2<Real>& rkOrigin, const Vector2<Real>& rkDirection,
        Real fMin, Real fMax);

    // copy constructor
    LinComp2 (const LinComp2& rkComponent);

    // assignment
    LinComp2& operator= (const LinComp2& rkComponent);

    virtual void MakeCanonical ();

    Vector2<Real> Origin, Direction;

protected:
    using LinComp<Real>::CT_EMPTY;
    using LinComp<Real>::CT_POINT;
    using LinComp<Real>::CT_SEGMENT;
    using LinComp<Real>::CT_RAY;
    using LinComp<Real>::CT_LINE;
    using LinComp<Real>::m_iType;
    using LinComp<Real>::m_fMin;
    using LinComp<Real>::m_fMax;
};

#include "Wm4LinComp2.inl"

typedef LinComp2<float> LinComp2f;
typedef LinComp2<double> LinComp2d;

}

#endif
