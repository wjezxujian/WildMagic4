// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SINGLECURVE2_H
#define WM4SINGLECURVE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Curve2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM SingleCurve2 : public Curve2<Real>
{
public:
    // abstract base class
    SingleCurve2 (Real fTMin, Real fTMax);

    // length-from-time and time-from-length
    virtual Real GetLength (Real fT0, Real fT1) const;
    virtual Real GetTime (Real fLength, int iIterations = 32,
        Real fTolerance = (Real)1e-06) const;

protected:
    using Curve2<Real>::m_fTMin;
    using Curve2<Real>::m_fTMax;
    using Curve2<Real>::GetTotalLength;

    static Real GetSpeedWithData (Real fTime, void* pvData);
};

typedef SingleCurve2<float> SingleCurve2f;
typedef SingleCurve2<double> SingleCurve2d;

}

#endif
