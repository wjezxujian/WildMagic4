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
#include "Wm4VisibleSet.h"
using namespace Wm4;

//----------------------------------------------------------------------------
VisibleSet::VisibleSet (int iMaxQuantity, int iGrowBy)
{
    m_akVisible = 0;
    Resize(iMaxQuantity,iGrowBy);
}
//----------------------------------------------------------------------------
VisibleSet::~VisibleSet ()
{
    WM4_DELETE[] m_akVisible;
}
//----------------------------------------------------------------------------
void VisibleSet::Insert (Spatial* pkObject, Effect* pkGlobalEffect)
{
    // Increase the array storage if necessary.
    if (++m_iQuantity > m_iMaxQuantity)
    {
        int iNewMaxQuantity = m_iMaxQuantity + m_iGrowBy;
        VisibleObject* akNewVisible = WM4_NEW VisibleObject[iNewMaxQuantity];
        size_t uiSize = m_iQuantity*sizeof(VisibleObject);
        System::Memcpy(akNewVisible,uiSize,m_akVisible,uiSize);
        WM4_DELETE[] m_akVisible;
        m_akVisible = akNewVisible;
        m_iMaxQuantity = iNewMaxQuantity;
    }

    // Append the potentially visible object to the set.
    int iIndex = m_iQuantity-1;
    m_akVisible[iIndex].Object = pkObject;
    m_akVisible[iIndex].GlobalEffect = pkGlobalEffect;
}
//----------------------------------------------------------------------------
void VisibleSet::Resize (int iMaxQuantity, int iGrowBy)
{
    if (iMaxQuantity > 0)
    {
        m_iMaxQuantity = iMaxQuantity;
    }
    else
    {
        m_iMaxQuantity = VS_DEFAULT_MAX_QUANTITY;
    }

    if (iGrowBy > 0)
    {
        m_iGrowBy = iGrowBy;
    }
    else
    {
        m_iGrowBy = VS_DEFAULT_GROWBY;
    }

    WM4_DELETE[] m_akVisible;
    m_iQuantity = 0;
    m_akVisible = WM4_NEW VisibleObject[m_iMaxQuantity];
}
//----------------------------------------------------------------------------
