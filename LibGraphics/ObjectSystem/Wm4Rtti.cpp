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
#include "Wm4Rtti.h"
using namespace Wm4;

//----------------------------------------------------------------------------
Rtti::Rtti (const char* acName, const Rtti* pkBaseType)
{
    m_acName = acName;
    m_pkBaseType = pkBaseType;
}
//----------------------------------------------------------------------------
Rtti::~Rtti ()
{
}
//----------------------------------------------------------------------------
bool Rtti::IsDerived (const Rtti& rkType) const
{
    const Rtti* pkSearch = this;
    while (pkSearch)
    {
        if (pkSearch == &rkType)
        {
            return true;
        }
        pkSearch = pkSearch->m_pkBaseType;
    }
    return false;
}
//----------------------------------------------------------------------------
