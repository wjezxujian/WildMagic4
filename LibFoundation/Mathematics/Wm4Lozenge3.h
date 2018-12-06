// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4LOZENGE3_H
#define WM4LOZENGE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Rectangle3.h"

namespace Wm4
{

template <class Real>
class Lozenge3
{
public:
    // construction
    Lozenge3 ();  // uninitialized
    Lozenge3 (const Rectangle3<Real>& rkRectangle, Real fRadius);

    Rectangle3<Real> Rectangle;
    Real Radius;
};

#include "Wm4Lozenge3.inl"

typedef Lozenge3<float> Lozenge3f;
typedef Lozenge3<double> Lozenge3d;

}

#endif
