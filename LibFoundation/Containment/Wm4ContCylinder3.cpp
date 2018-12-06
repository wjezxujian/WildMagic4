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
#include "Wm4ContCylinder3.h"
#include "Wm4ApprLineFit3.h"
#include "Wm4DistVector3Line3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
Cylinder3<Real> ContCylinder (int iQuantity, const Vector3<Real>* akPoint)
{
    Cylinder3<Real> kCylinder;

    Line3<Real> kLine = OrthogonalLineFit3(iQuantity,akPoint);

    Real fMaxRadiusSqr = (Real)0.0;
    int i;
    for (i = 0; i < iQuantity; i++)
    {
        Real fRadiusSqr = DistVector3Line3<Real>(akPoint[i],
            kLine).GetSquared();
        if (fRadiusSqr > fMaxRadiusSqr)
        {
            fMaxRadiusSqr = fRadiusSqr;
        }
    }

    Vector3<Real> kDiff = akPoint[0] - kLine.Origin;
    Real fWMin = kLine.Direction.Dot(kDiff), fWMax = fWMin;
    for (i = 1; i < iQuantity; i++)
    {
        kDiff = akPoint[i] - kLine.Origin;
        Real fW = kLine.Direction.Dot(kDiff);
        if (fW < fWMin)
        {
            fWMin = fW;
        }
        else if (fW > fWMax)
        {
            fWMax = fW;
        }
    }

    kCylinder.Segment.Origin = kLine.Origin +
        (((Real)0.5)*(fWMax+fWMin))*kLine.Direction;
    kCylinder.Segment.Direction = kLine.Direction;
    kCylinder.Radius = Math<Real>::Sqrt(fMaxRadiusSqr);
    kCylinder.Height = fWMax - fWMin;

    return kCylinder;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
Cylinder3<float> ContCylinder<float> (int, const Vector3<float>*);

template WM4_FOUNDATION_ITEM
Cylinder3<double> ContCylinder<double> (int, const Vector3<double>*);
//----------------------------------------------------------------------------
}
