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
#include "Wm4CRMCuller.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CRMCuller::CRMCuller (int iMaxQuantity, int iGrowBy, const Camera* pkCamera)
    :
    Culler(iMaxQuantity,iGrowBy,pkCamera),
    m_kUnique(iMaxQuantity > 0 ? iMaxQuantity : 1024)
{
}
//----------------------------------------------------------------------------
CRMCuller::~CRMCuller ()
{
}
//----------------------------------------------------------------------------
void CRMCuller::Insert (Spatial* pkObject, Effect* pkGlobalEffect)
{
    if (pkObject)
    {
        if (&pkObject != m_kUnique.Insert(pkObject))
        {
            // The object was not in the list of unique objects.
            Culler::Insert(pkObject,pkGlobalEffect);
        }
    }
    else
    {
        // This is an end-sentinel for a global effect.  There can be
        // multiple copies of these.
        Culler::Insert(0,0);
    }
}
//----------------------------------------------------------------------------
