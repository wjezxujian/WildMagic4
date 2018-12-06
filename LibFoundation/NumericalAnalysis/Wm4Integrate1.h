// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTEGRATE1_H
#define WM4INTEGRATE1_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM Integrate1
{
public:
    // last parameter is for user-defined data
    typedef Real (*Function)(Real,void*);

    static Real RombergIntegral (int iOrder, Real fA, Real fB, Function oF,
        void* pvUserData = 0);

    static Real GaussianQuadrature (Real fA, Real fB, Function oF,
        void* pvUserData = 0);

    static Real TrapezoidRule (int iNumSamples, Real fA, Real fB,
        Function oF, void* pvUserData = 0);
};

typedef Integrate1<float> Integrate1f;
typedef Integrate1<double> Integrate1d;

}

#endif
