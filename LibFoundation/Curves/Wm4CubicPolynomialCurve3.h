// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CUBICPOLYNOMIALCURVE3_H
#define WM4CUBICPOLYNOMIALCURVE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4PolynomialCurve3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM CubicPolynomialCurve3
    : public PolynomialCurve3<Real>
{
public:
    // Construction and destruction.  CubicPolynomialCurve3 accepts
    // responsibility for deleting the input polynomials.
    CubicPolynomialCurve3 (Polynomial1<Real>* pkXPoly,
        Polynomial1<Real>* pkYPoly, Polynomial1<Real>* pkZPoly);

    virtual ~CubicPolynomialCurve3 ();

    // tessellation data
    int GetVertexQuantity () const;
    Vector3<Real>* Vertices ();

    // tessellation by recursive subdivision
    void Tessellate (int iLevel);

protected:
    using PolynomialCurve3<Real>::m_fTMin;
    using PolynomialCurve3<Real>::m_fTMax;

    // precomputation
    class WM4_FOUNDATION_ITEM IntervalParameters
    {
    public:
        int m_iI0, m_iI1;
        Vector3<Real> m_akXuu[2];
    };

    // subdivide curve into two halves
    void Subdivide (int iLevel, Real fDSqr, Vector3<Real>* akX,
        IntervalParameters& rkIP);

    // tessellation data
    int m_iVertexQuantity;
    Vector3<Real>* m_akVertex;
};

typedef CubicPolynomialCurve3<float> CubicPolynomialCurve3f;
typedef CubicPolynomialCurve3<double> CubicPolynomialCurve3d;

}

#endif
