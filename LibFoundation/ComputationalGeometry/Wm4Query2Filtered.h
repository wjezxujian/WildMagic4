// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4QUERY2FILTERED_H
#define WM4QUERY2FILTERED_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query2TRational.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class Query2Filtered : public Query2<Real>
{
public:
    // The base class handles floating-point queries.  Each query involves
    // comparing a determinant to zero.  If the determinant is sufficiently
    // close to zero, numerical round-off errors may cause the determinant
    // sign to be misclassified.  To avoid this, the query is repeated with
    // exact rational arithmetic.  You specify the closeness to zero for the
    // switch to rational arithmetic via fUncertainty, a value in the
    // interval [0,1].  The uncertainty of 0 causes the class to behave
    // as if it were Query2.  The uncertainty of 1 causes the class to
    // behave as if it were Query2TRational.
    Query2Filtered (int iVQuantity, const Vector2<Real>* akVertex,
        Real fUncertainty);
    virtual ~Query2Filtered ();

    // run-time type information
    virtual Query::Type GetType () const;

    // Queries about the relation of a point to various geometric objects.

    virtual int ToLine (const Vector2<Real>& rkP, int iV0, int iV1) const;

    virtual int ToCircumcircle (const Vector2<Real>& rkP, int iV0, int iV1,
        int iV2) const;

private:
    using Query2<Real>::m_akVertex;

    Query2TRational<Real> m_kRQuery;
    Real m_fUncertainty;
};

#include "Wm4Query2Filtered.inl"

typedef Query2Filtered<float> Query2Filteredf;
typedef Query2Filtered<double> Query2Filteredd;

}

#endif
