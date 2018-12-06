// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SINGLECURVE3_H
#define WM4SINGLECURVE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Curve3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM SingleCurve3 : public Curve3<Real>
{
public:
    // abstract base class
    SingleCurve3 (Real fTMin, Real fTMax);

    // length-from-time and time-from-length
    virtual Real GetLength (Real fT0, Real fT1) const;
    virtual Real GetTime (Real fLength, int iIterations = 32,
        Real fTolerance = (Real)1e-06) const;

protected:
    using Curve3<Real>::m_fTMin;
    using Curve3<Real>::m_fTMax;
    using Curve3<Real>::GetTotalLength;

    static Real GetSpeedWithData (Real fTime, void* pvData);
};

typedef SingleCurve3<float> SingleCurve3f;
typedef SingleCurve3<double> SingleCurve3d;

}

#endif
