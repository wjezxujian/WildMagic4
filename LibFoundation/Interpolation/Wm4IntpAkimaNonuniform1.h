// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INTPAKIMANONUNIFORM1_H
#define WM4INTPAKIMANONUNIFORM1_H

#include "Wm4FoundationLIB.h"
#include "Wm4IntpAkima1.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM IntpAkimaNonuniform1 : public IntpAkima1<Real>
{
public:
    // Construction and destruction.  IntpAkimaNonuniform1 does not
    // accept responsibility for deleting the input arrays.  The application
    // must do so.  The interpolator is for arbitrarily spaced x-values.
    IntpAkimaNonuniform1 (int iQuantity, Real* afX, Real* afF);
    virtual ~IntpAkimaNonuniform1 ();

    const Real* GetX () const;
    virtual Real GetXMin () const;
    virtual Real GetXMax () const;

protected:
    using IntpAkima1<Real>::m_iQuantity;
    using IntpAkima1<Real>::m_akPoly;

    virtual bool Lookup (Real fX, int& riIndex, Real& rfDX) const;

    Real* m_afX;
};

typedef IntpAkimaNonuniform1<float> IntpAkimaNonuniform1f;
typedef IntpAkimaNonuniform1<double> IntpAkimaNonuniform1d;

}

#endif
