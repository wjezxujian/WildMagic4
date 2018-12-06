// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4BSplineGeodesic.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
BSplineGeodesic<Real>::BSplineGeodesic (
    const BSplineRectangle<Real>& rkBSpline)
    :
    RiemannianGeodesic<Real>(2),
    m_rkBSpline(rkBSpline)
{
}
//----------------------------------------------------------------------------
template <class Real>
BSplineGeodesic<Real>::~BSplineGeodesic ()
{
}
//----------------------------------------------------------------------------
template <class Real>
void BSplineGeodesic<Real>::ComputeMetric (const GVector<Real>& rkPoint)
{
    Vector3<Real> kDer0 = m_rkBSpline.PU(rkPoint[0],rkPoint[1]);
    Vector3<Real> kDer1 = m_rkBSpline.PV(rkPoint[0],rkPoint[1]);

    m_kMetric[0][0] = kDer0.Dot(kDer0);
    m_kMetric[0][1] = kDer0.Dot(kDer1);
    m_kMetric[1][0] = m_kMetric[0][1];
    m_kMetric[1][1] = kDer1.Dot(kDer1);
}
//----------------------------------------------------------------------------
template <class Real>
void BSplineGeodesic<Real>::ComputeChristoffel1 (const GVector<Real>& rkPoint)
{
    Vector3<Real> kDer0 = m_rkBSpline.PU(rkPoint[0],rkPoint[1]);
    Vector3<Real> kDer1 = m_rkBSpline.PV(rkPoint[0],rkPoint[1]);
    Vector3<Real> kDer00 = m_rkBSpline.PUU(rkPoint[0],rkPoint[1]);
    Vector3<Real> kDer01 = m_rkBSpline.PUV(rkPoint[0],rkPoint[1]);
    Vector3<Real> kDer11 = m_rkBSpline.PVV(rkPoint[0],rkPoint[1]);

    m_akChristoffel1[0][0][0] = kDer00.Dot(kDer0);
    m_akChristoffel1[0][0][1] = kDer01.Dot(kDer0);
    m_akChristoffel1[0][1][0] = m_akChristoffel1[0][0][1];
    m_akChristoffel1[0][1][1] = kDer11.Dot(kDer0);

    m_akChristoffel1[1][0][0] = kDer00.Dot(kDer1);
    m_akChristoffel1[1][0][1] = kDer01.Dot(kDer1);
    m_akChristoffel1[1][1][0] = m_akChristoffel1[1][0][1];
    m_akChristoffel1[1][1][1] = kDer11.Dot(kDer1);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class BSplineGeodesic<float>;

template WM4_FOUNDATION_ITEM
class BSplineGeodesic<double>;
}
//----------------------------------------------------------------------------
