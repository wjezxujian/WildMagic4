// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VECTOR4_H
#define WM4VECTOR4_H

#include "Wm4FoundationLIB.h"
#include "Wm4Math.h"

namespace Wm4
{

template <class Real>
class Vector4
{
public:
    // construction
    Vector4 ();  // uninitialized
    Vector4 (Real fX, Real fY, Real fZ, Real fW);
    Vector4 (const Real* afTuple);
    Vector4 (const Vector4& rkV);

    // coordinate access
    operator const Real* () const;
    operator Real* ();
    Real operator[] (int i) const;
    Real& operator[] (int i);
    Real X () const;
    Real& X ();
    Real Y () const;
    Real& Y ();
    Real Z () const;
    Real& Z ();
    Real W () const;
    Real& W ();

    // assignment
    Vector4& operator= (const Vector4& rkV);

    // comparison
    bool operator== (const Vector4& rkV) const;
    bool operator!= (const Vector4& rkV) const;
    bool operator<  (const Vector4& rkV) const;
    bool operator<= (const Vector4& rkV) const;
    bool operator>  (const Vector4& rkV) const;
    bool operator>= (const Vector4& rkV) const;

    // arithmetic operations
    Vector4 operator+ (const Vector4& rkV) const;
    Vector4 operator- (const Vector4& rkV) const;
    Vector4 operator* (Real fScalar) const;
    Vector4 operator/ (Real fScalar) const;
    Vector4 operator- () const;

    // arithmetic updates
    Vector4& operator+= (const Vector4& rkV);
    Vector4& operator-= (const Vector4& rkV);
    Vector4& operator*= (Real fScalar);
    Vector4& operator/= (Real fScalar);

    // vector operations
    Real Length () const;
    Real SquaredLength () const;
    Real Dot (const Vector4& rkV) const;
    Real Normalize ();

    // special vectors
    WM4_FOUNDATION_ITEM static const Vector4 ZERO;
    WM4_FOUNDATION_ITEM static const Vector4 UNIT_X;
    WM4_FOUNDATION_ITEM static const Vector4 UNIT_Y;
    WM4_FOUNDATION_ITEM static const Vector4 UNIT_Z;
    WM4_FOUNDATION_ITEM static const Vector4 UNIT_W;

private:
    // support for comparisons
    int CompareArrays (const Vector4& rkV) const;

    Real m_afTuple[4];
};

// arithmetic operations
template <class Real>
Vector4<Real> operator* (Real fScalar, const Vector4<Real>& rkV);

// debugging output
template <class Real>
std::ostream& operator<< (std::ostream& rkOStr, const Vector4<Real>& rkV);

#include "Wm4Vector4.inl"

typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;

}

#endif
