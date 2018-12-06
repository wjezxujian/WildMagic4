// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTPVECTORFIELD2_H
#define WM4INTPVECTORFIELD2_H

// Given points (x0[i],y0[i]) which are mapped to (x1[i],y1[i]) for
// 0 <= i < N, interpolate positions (xIn,yIn) to (xOut,yOut).

#include "Wm4FoundationLIB.h"
#include "Wm4IntpQdrNonuniform2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntpVectorField2
{
public:
    // Construction and destruction.  If you want IntpVectorField2 to delete
    // the input arrays during destruction, set bOwner to 'true'.  Otherwise,
    // you own the arrays and must delete them yourself.
    //
    // The computation type is for the Delaunay triangulation and should be
    // one of Query::{QT_INT64,QT_INTEGER,QT_RATIONAL,QT_REAL}.
    IntpVectorField2 (int iQuantity, Vector2<Real>* akDomain,
        Vector2<Real>* akRange, bool bOwner, Query::Type eQueryType);

    ~IntpVectorField2 ();

    // Return 'true' if and only if (xIn,yIn) is in the convex hull of the
    // input points.  In this case, (xOut,yOut) is valid.  If the return
    // value is 'false', (xOut,yOut) is invalid and should not be used.
    bool Evaluate (const Vector2<Real>& rkInput, Vector2<Real>& rkOutput); 

protected:
    Delaunay2<Real>* m_pkDel;
    IntpQdrNonuniform2<Real>* m_pkXInterp;
    IntpQdrNonuniform2<Real>* m_pkYInterp;
};

typedef IntpVectorField2<float> IntpVectorField2f;
typedef IntpVectorField2<double> IntpVectorField2d;

}

#endif
