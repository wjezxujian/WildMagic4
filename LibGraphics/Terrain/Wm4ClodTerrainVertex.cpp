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
#include "Wm4ClodTerrainVertex.h"
using namespace Wm4;

//----------------------------------------------------------------------------
ClodTerrainVertex::ClodTerrainVertex ()
{
    m_akDependent[0] = 0;
    m_akDependent[1] = 0;
    m_bEnabled = false;
}
//----------------------------------------------------------------------------
void ClodTerrainVertex::Enable ()
{
    m_bEnabled = true;

    if (m_akDependent[0])
    {
        if (!m_akDependent[0]->m_bEnabled)
        {
            m_akDependent[0]->Enable();
        }
    }
    
    if (m_akDependent[1])
    {
        if (!m_akDependent[1]->m_bEnabled)
        {
            m_akDependent[1]->Enable();
        }
    }
}
//----------------------------------------------------------------------------
void ClodTerrainVertex::Disable ()
{
    m_bEnabled = false;
    
    if (m_akDependent[0])
    {
        if (m_akDependent[0]->m_bEnabled)
        {
            m_akDependent[0]->Disable();
        }
    }

    if (m_akDependent[1])
    {
        if (m_akDependent[1]->m_bEnabled)
        {
            m_akDependent[1]->Disable();
        }
    }
}
//----------------------------------------------------------------------------
