// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4QUERY2TINTEGER_H
#define WM4QUERY2TINTEGER_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query2.h"
#include "Wm4TInteger.h"

namespace Wm4
{

template <class Real>
class Query2TInteger : public Query2<Real>
{
public:
    // The components of the input vertices are truncated to 32-bit integer
    // values, so you should guarantee that the vertices are sufficiently
    // large to give a good distribution of numbers.  The value N in
    // TInteger<N> is chosen large enough so that the exact arithmetic is
    // correct for the functions.
    Query2TInteger (int iVQuantity, const Vector2<Real>* akVertex);

    // run-time type information
    virtual Query::Type GetType () const;

    // Queries about the relation of a point to various geometric objects.

    virtual int ToLine (const Vector2<Real>& rkP, int iV0, int iV1) const;

    virtual int ToCircumcircle (const Vector2<Real>& rkP, int iV0, int iV1,
        int iV2) const;

private:
    using Query2<Real>::m_akVertex;

    static TInteger<2> Dot (TInteger<2>& rkX0, TInteger<2>& rkY0,
        TInteger<2>& rkX1, TInteger<2>& rkY1);

    static TInteger<2> Det2 (TInteger<2>& rkX0, TInteger<2>& rkY0,
        TInteger<2>& rkX1, TInteger<2>& rkY1);

    static TInteger<4> Det3 (TInteger<4>& rkX0, TInteger<4>& rkY0,
        TInteger<4>& rkZ0, TInteger<4>& rkX1, TInteger<4>& rkY1,
        TInteger<4>& rkZ1, TInteger<4>& rkX2, TInteger<4>& rkY2,
        TInteger<4>& rkZ2);
};

#include "Wm4Query2TInteger.inl"

typedef Query2TInteger<float> Query2TIntegerf;
typedef Query2TInteger<double> Query2TIntegerd;

}

#endif
