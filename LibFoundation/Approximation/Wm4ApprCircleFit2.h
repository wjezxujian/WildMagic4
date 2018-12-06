// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4APPRCIRCLEFIT2_H
#define WM4APPRCIRCLEFIT2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Circle2.h"

namespace Wm4
{

// Least-squares fit of a circle to a set of points.  Successful fit is
// indicated by return value of 'true'.  If return value is false, number of
// iterations was exceeded.  Try increasing the maximum number of iterations.
//
// If bInitialCenterIsAverage is set to 'true', the initial guess for the
// circle center is the average of the data points.  If the data points are
// clustered along a small arc, CircleFit2 is very slow to converge.  If
// bInitialCenterIsAverage is set to 'false', the initial guess for the
// circle center is computed using a least-squares estimate of the
// coefficients for a quadratic equation that represents a circle.  This
// approach tends to converge rapidly.

template <class Real> WM4_FOUNDATION_ITEM
bool CircleFit2 (int iQuantity, const Vector2<Real>* akPoint,
    int iMaxIterations, Circle2<Real>& rkCircle,
    bool bInitialCenterIsAverage);

}

#endif
