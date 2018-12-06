// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TORUS_H
#define WM4TORUS_H

// Implementation of torus centered at (0,0,0) with z-axis as the
// axis of symmetry (axis about which circle is rotated to generate
// the torus).
//
// algebraic form
//      Ro > 0 is radius from center of torus
//      Ri > 0 is radius of tube of torus
//      p^2 = x^2+y^2+z^2
//      p^4-2*(Ro^2+Ri^2)*p^2+4*Ro^2*z^2+(Ro^2-Ri^2)^2 = 0
//
// parametric form
//      0 <= s <= 1, 0 <= t <= 1
//      Rc = Ro+Ri*cos(2*PI*t)
//      x = Rc*cos(2*PI*s)
//      y = Rc*sin(2*PI*s)
//      z = Ri*sin(2*PI*t)

#include "Wm4FoundationLIB.h"
#include "Wm4Vector3.h"

namespace Wm4
{

template <class Real>
class Torus3
{
public:
    // construction
    Torus3 ();  // uninitialized
    Torus3 (Real fRo, Real fRi);

    Vector3<Real> Position (Real fS, Real fT);
    Vector3<Real> Normal (Real fS, Real fT);

    // for use in intersection testing
    void GetParameters (const Vector3<Real>& rkPos, Real& rfS,
        Real& rfT) const;

    Real Ro, Ri;
};

#include "Wm4Torus3.inl"

typedef Torus3<float> Torus3f;
typedef Torus3<double> Torus3d;

}

#endif
