// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MULTIPLECURVE2_H
#define WM4MULTIPLECURVE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Curve2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM MultipleCurve2 : public Curve2<Real>
{
public:
    // Construction and destruction for abstract base class.  MultipleCurve2
    // accepts responsibility for deleting the input array.
    MultipleCurve2 (int iSegments, Real* afTime);
    virtual ~MultipleCurve2 ();

    // member access
    int GetSegments () const;
    const Real* GetTimes () const;

    // length-from-time and time-from-length
    virtual Real GetLength (Real fT0, Real fT1) const;
    virtual Real GetTime (Real fLength, int iIterations = 32,
        Real fTolerance = (Real)1e-06) const;

    // support for subdivision
    virtual Real GetVariation (Real fT0, Real fT1,
        const Vector2<Real>* pkP0 = 0, const Vector2<Real>* pkP1 = 0) const;

protected:
    using Curve2<Real>::m_fTMin;
    using Curve2<Real>::m_fTMax;

    int m_iSegments;
    Real* m_afTime;

    // These quantities are allocated by GetLength when they are needed the
    // first time.  The allocations occur in InitializeLength (called by
    // GetLength), so this member function must be 'const'. In order to
    // allocate the arrays in a 'const' function, they must be declared as
    // 'mutable'.
    mutable Real* m_afLength;
    mutable Real* m_afAccumLength;

    void GetKeyInfo (Real fTime, int& riKey, Real& rfDt) const;

    void InitializeLength () const;
    virtual Real GetSpeedKey (int iKey, Real fTime) const = 0;
    virtual Real GetLengthKey (int iKey, Real fT0, Real fT1) const = 0;
    virtual Real GetVariationKey (int iKey, Real fT0, Real fT1,
        const Vector2<Real>& rkA, const Vector2<Real>& rkB) const = 0;

    static Real GetSpeedWithData (Real fTime, void* pvData);
};

typedef MultipleCurve2<float> MultipleCurve2f;
typedef MultipleCurve2<double> MultipleCurve2d;

}

#endif
