// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BISECT1_H
#define WM4BISECT1_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM Bisect1
{
public:
    typedef Real (*Function)(Real);

    Bisect1 (Function oF, int iMaxLevel, Real fTolerance);

    bool Bisect (Real fX0, Real fX1, Real& rfRoot);

private:
    // input data and functions
    Function m_oF;
    int m_iMaxLevel;
    Real m_fTolerance;
};

typedef Bisect1<float> Bisect1f;
typedef Bisect1<double> Bisect1d;

}

#endif
