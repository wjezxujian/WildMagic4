// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BSPLINEGEODESIC_H
#define WM4BSPLINEGEODESIC_H

#include "Wm4FoundationLIB.h"
#include "Wm4RiemannianGeodesic.h"
#include "Wm4BSplineRectangle.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM BSplineGeodesic : public RiemannianGeodesic<Real>
{
public:
    BSplineGeodesic (const BSplineRectangle<Real>& rkBSpline);
    virtual ~BSplineGeodesic ();

    virtual void ComputeMetric (const GVector<Real>& rkPoint);
    virtual void ComputeChristoffel1 (const GVector<Real>& rkPoint);

private:
    using RiemannianGeodesic<Real>::m_kMetric;
    using RiemannianGeodesic<Real>::m_akChristoffel1;

    const BSplineRectangle<Real>& m_rkBSpline;
};

typedef BSplineGeodesic<float> BSplineGeodesicf;
typedef BSplineGeodesic<double> BSplineGeodesicd;

}

#endif
