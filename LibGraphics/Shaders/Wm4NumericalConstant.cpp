// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4System.h"
#include "Wm4NumericalConstant.h"
using namespace Wm4;

//----------------------------------------------------------------------------
NumericalConstant::NumericalConstant (int iRegister, float afData[4])
{
    assert(iRegister >= 0);

    m_iRegister = iRegister;
    for (int i = 0; i < 4; i++)
    {
        m_afData[i] = afData[i];
    }
}
//----------------------------------------------------------------------------
NumericalConstant::~NumericalConstant ()
{
}
//----------------------------------------------------------------------------
