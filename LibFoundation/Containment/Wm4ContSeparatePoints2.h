// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTSEPARATEPOINTS2_H
#define WM4CONTSEPARATEPOINTS2_H

// Separate two point sets, if possible, by computing a line for which the
// point sets lie on opposite sides.  The algorithm computes the convex hull
// of the point sets, then uses the method of separating axes to determine if
// the two convex polygons are disjoint.  The convex hull calculation is
// O(n*log(n)).  There is a randomized linear approach that takes O(n), but
// I have not yet implemented it.
//
// The return value of the function is 'true' if and only if there is a
// separation.  If 'true', the returned line is a separating line.

#include "Wm4FoundationLIB.h"
#include "Wm4Line2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM SeparatePoints2
{
public:
    SeparatePoints2 (int iQuantity0, const Vector2<Real>* akVertex0,
        int iQuantity1, const Vector2<Real>* akVertex1,
        Line2<Real>& rkSeprLine);

    // Return the result of the constructor call.  If 'true', the output
    // line rkSeprLine is valid.
    operator bool ();

private:
    static int OnSameSide (const Vector2<Real>& rkLineNormal,
        Real fLineConstant, int iEdgeQuantity, const int* aiEdge,
        const Vector2<Real>* akPoint);

    static int WhichSide (const Vector2<Real>& rkLineNormal,
        Real fLineConstant, int iEdgeQuantity, const int* aiEdge,
        const Vector2<Real>* akPoint);

    bool m_bSeparated;
};

typedef SeparatePoints2<float> SeparatePoints2f;
typedef SeparatePoints2<double> SeparatePoints2d;

}

#endif
