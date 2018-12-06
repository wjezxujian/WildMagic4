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
#include "Wm4UserConstant.h"
using namespace Wm4;

//----------------------------------------------------------------------------
UserConstant::UserConstant (const std::string& rkName, int iBaseRegister,
    int iRegisterQuantity)
    :
    m_kName(rkName)
{
    assert(iBaseRegister >= 0);
    assert(iRegisterQuantity > 0);

    m_iBaseRegister = iBaseRegister;
    m_iRegisterQuantity = iRegisterQuantity;

    // To be set later in the effect creation.
    m_afData = 0;
}
//----------------------------------------------------------------------------
UserConstant::~UserConstant ()
{
    // The memory pointed to by m_afData is not owned by UserConstant, so
    // no deletion occurs here.
}
//----------------------------------------------------------------------------
void UserConstant::SetDataSource (float* afData)
{
    assert(afData);

    m_afData = afData;
}
//----------------------------------------------------------------------------
