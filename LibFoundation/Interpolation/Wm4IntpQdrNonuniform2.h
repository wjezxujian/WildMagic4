// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTPQUADRATICNONUNIFORM2_H
#define WM4INTPQUADRATICNONUNIFORM2_H

// Quadratic interpolation of a network of triangles whose vertices are of
// the form (x,y,f(x,y)).  This code is an implementation of the algorithm
// found in
//
//   Zoltan J. Cendes and Steven H. Wong,
//   C1 quadratic interpolation over arbitrary point sets,
//   IEEE Computer Graphics & Applications,
//   pp. 8-16, 1987

#include "Wm4FoundationLIB.h"
#include "Wm4Delaunay2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntpQdrNonuniform2
{
public:
    // Construction and destruction.  If you want IntpQdrNonuniform2 to
    // delete the input array during destruction, set bOwner to 'true'.
    // Otherwise, you own the array and must delete it yourself.
    //
    // The first constructor requires you to specify function values F and
    // first-order partial derivative values Fx and Fy.  The second
    // constructor requires only F, but the Fx and Fy values are estimated
    // at the sample points.

    IntpQdrNonuniform2 (const Delaunay2<Real>& rkDT, Real* afF, Real* afFx,
        Real* afFy, bool bOwner);

    IntpQdrNonuniform2 (const Delaunay2<Real>& rkDT, Real* afF, bool bOwner);

    ~IntpQdrNonuniform2 ();

    // Quadratic interpolation.  The return value is 'true' if and only if the
    // input point is in the convex hull of the input vertices, in which case
    // the interpolation is valid.
    bool Evaluate (const Vector2<Real>& rkP, Real& rfF, Real& rfFx,
        Real& rfFy);

private:
    class WM4_FOUNDATION_ITEM TriangleData
    {
    public:
        Vector2<Real> Center;
        Vector2<Real> Intersect[3];
        Real Coeff[19];
    };

    class WM4_FOUNDATION_ITEM Jet
    {
    public:
        Real F, Fx, Fy;
    };

    const Delaunay2<Real>& m_rkDT;
    Real* m_afF;
    Real* m_afFx;
    Real* m_afFy;
    TriangleData* m_akTData;  // triangle data
    bool m_bFOwner, m_bFxFyOwner;

    void EstimateDerivatives ();
    void ProcessTriangles ();
    void ComputeCrossEdgeIntersections (int iT);
    void ComputeCoefficients (int iT);
};

typedef IntpQdrNonuniform2<float> IntpQdrNonuniform2f;
typedef IntpQdrNonuniform2<double> IntpQdrNonuniform2d;

}

#endif
