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
#include "Wm4ApprGaussPointsFit2.h"
#include "Wm4Eigen.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
Box2<Real> GaussPointsFit2 (int iQuantity, const Vector2<Real>* akPoint)
{
    Box2<Real> kBox(Vector2<Real>::ZERO,Vector2<Real>::UNIT_X,
        Vector2<Real>::UNIT_Y,(Real)1.0,(Real)1.0);

    // compute the mean of the points
    kBox.Center = akPoint[0];
    int i;
    for (i = 1; i < iQuantity; i++)
    {
        kBox.Center += akPoint[i];
    }
    Real fInvQuantity = ((Real)1.0)/iQuantity;
    kBox.Center *= fInvQuantity;

    // compute the covariance matrix of the points
    Real fSumXX = (Real)0.0, fSumXY = (Real)0.0, fSumYY = (Real)0.0;
    for (i = 0; i < iQuantity; i++)
    {
        Vector2<Real> kDiff = akPoint[i] - kBox.Center;
        fSumXX += kDiff.X()*kDiff.X();
        fSumXY += kDiff.X()*kDiff.Y();
        fSumYY += kDiff.Y()*kDiff.Y();
    }

    fSumXX *= fInvQuantity;
    fSumXY *= fInvQuantity;
    fSumYY *= fInvQuantity;

    // setup the eigensolver
    Eigen<Real> kES(2);
    kES(0,0) = fSumXX;
    kES(0,1) = fSumXY;
    kES(1,0) = fSumXY;
    kES(1,1) = fSumYY;
    kES.IncrSortEigenStuff2();

    for (i = 0; i < 2; i++)
    {
        kBox.Extent[i] = kES.GetEigenvalue(i);
        kES.GetEigenvector(i,kBox.Axis[i]);
    }

    return kBox;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
Box2<float> GaussPointsFit2<float> (int, const Vector2<float>*);

template WM4_FOUNDATION_ITEM
Box2<double> GaussPointsFit2<double> (int, const Vector2<double>*);
//----------------------------------------------------------------------------
}
