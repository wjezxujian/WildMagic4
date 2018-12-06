// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TIVECTOR_H
#define WM4TIVECTOR_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <int VSIZE>
class TIVector
{
public:
    // construction
    TIVector ();
    TIVector (const TIVector& rkV);

    // coordinate access
    operator const Integer64* () const;
    operator Integer64* ();
    Integer64 operator[] (int i) const;
    Integer64& operator[] (int i);

    // assignment
    TIVector& operator= (const TIVector& rkV);

    // comparison
    bool operator== (const TIVector& rkV) const;
    bool operator!= (const TIVector& rkV) const;
    bool operator<  (const TIVector& rkV) const;
    bool operator<= (const TIVector& rkV) const;
    bool operator>  (const TIVector& rkV) const;
    bool operator>= (const TIVector& rkV) const;

    // arithmetic operations
    TIVector operator+ (const TIVector& rkV) const;
    TIVector operator- (const TIVector& rkV) const;
    TIVector operator* (const Integer64& riI) const;
    TIVector operator/ (const Integer64& riI) const;
    TIVector operator- () const;

    // arithmetic updates
    TIVector& operator+= (const TIVector& rkV);
    TIVector& operator-= (const TIVector& rkV);
    TIVector& operator*= (const Integer64& riI);
    TIVector& operator/= (const Integer64& riI);

    // vector operations
    Integer64 SquaredLength () const;
    Integer64 Dot (const TIVector& rkV) const;

protected:
    // support for comparisons
    int CompareArrays (const TIVector& rkV) const;

    Integer64 m_aiTuple[VSIZE];
};

template <int VSIZE>
TIVector<VSIZE> operator* (const Integer64& riI, const TIVector<VSIZE>& rkV);

#include "Wm4TIVector.inl"

}

#endif
