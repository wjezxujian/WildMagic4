// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4APPRLINEFIT3_H
#define WM4APPRLINEFIT3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Line3.h"

namespace Wm4
{

// Least-squares fit of a line to (x,y,z) data by using distance measurements
// orthogonal to the proposed line.
template <class Real> WM4_FOUNDATION_ITEM
Line3<Real> OrthogonalLineFit3 (int iQuantity, const Vector3<Real>* akPoint);

}

#endif
