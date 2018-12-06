// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTCIRCLE2_H
#define WM4CONTCIRCLE2_H

// Compute the minimum area circle containing the input set of points.  The
// algorithm randomly permutes the input points so that the construction
// occurs in 'expected' O(N) time.

#include "Wm4FoundationLIB.h"
#include "Wm4Circle2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM MinCircle2
{
public:
    // The epsilon value is a floating-point tolerance used for various
    // computations.
    MinCircle2 (int iQuantity, const Vector2<Real>* akPoint,
        Circle2<Real>& rkMinimal, Real fEpsilon = (Real)1e-05);

private:
    // indices of points that support current minimum area circle
    class WM4_FOUNDATION_ITEM Support
    {
    public:
        bool Contains (int iIndex, Vector2<Real>** apkPoint, Real fEpsilon)
        {
            for (int i = 0; i < Quantity; i++)
            {
                Vector2<Real> kDiff = *apkPoint[iIndex] - *apkPoint[Index[i]];
                if (kDiff.SquaredLength() < fEpsilon)
                {
                    return true;
                }
            }
            return false;
        }

        int Quantity;
        int Index[3];
    };

    // test if point P is inside circle C
    bool Contains (const Vector2<Real>& rkP, const Circle2<Real>& rkC,
        Real& rfDistDiff);

    Circle2<Real> ExactCircle1 (const Vector2<Real>& rkP);
    Circle2<Real> ExactCircle2 (const Vector2<Real>& rkP0,
        const Vector2<Real>& rkP1);
    Circle2<Real> ExactCircle3 (const Vector2<Real>& rkP0,
        const Vector2<Real>& rkP1, const Vector2<Real>& rkP2);

    Circle2<Real> UpdateSupport1 (int i, Vector2<Real>** apkPerm,
        Support& rkSupp);
    Circle2<Real> UpdateSupport2 (int i, Vector2<Real>** apkPerm,
        Support& rkSupp);
    Circle2<Real> UpdateSupport3 (int i, Vector2<Real>** apkPerm,
        Support& rkSupp);

    typedef Circle2<Real> (MinCircle2<Real>::*UpdateFunction)(
        int,Vector2<Real>**,Support&);

    Real m_fEpsilon;
    UpdateFunction m_aoUpdate[4];
};

typedef MinCircle2<float> MinCircle2f;
typedef MinCircle2<double> MinCircle2d;

}

#endif
