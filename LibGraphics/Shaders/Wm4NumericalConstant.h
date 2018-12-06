// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4NUMERICALCONSTANT_H
#define WM4NUMERICALCONSTANT_H

#include "Wm4GraphicsLIB.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM NumericalConstant
{
public:
    // Construction and destruction.  The register must be nonnegative.  A
    // numerical constant corresponds to four floating-point numbers.
    NumericalConstant (int iRegister, float afData[4]);
    ~NumericalConstant ();

    // Member access.  The renderer will use these to pass the information to
    // the graphics API (specifically, to DirectX).
    int GetRegister () const;
    float* GetData () const;

private:
    int m_iRegister;
    float m_afData[4];
};

#include "Wm4NumericalConstant.inl"

}

#endif
