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
#include "Wm4Attributes.h"
using namespace Wm4;

//----------------------------------------------------------------------------
Attributes::Attributes ()
{
    m_iChannelQuantity = 0;
    m_iPOffset = -1;
    m_iPChannels = 0;
    m_iNOffset = -1;
    m_iNChannels = 0;
}
//----------------------------------------------------------------------------
Attributes::~Attributes ()
{
}
//----------------------------------------------------------------------------
void Attributes::SetPChannels (int iPChannels)
{
    assert(0 <= iPChannels && iPChannels <= 4);

    m_iPChannels = iPChannels;
    UpdateOffsets();
}
//----------------------------------------------------------------------------
void Attributes::SetNChannels (int iNChannels)
{
    assert(0 <= iNChannels && iNChannels <= 4);

    m_iNChannels = iNChannels;
    UpdateOffsets();
}
//----------------------------------------------------------------------------
void Attributes::SetCChannels (int iUnit, int iCChannels)
{
    assert(0 <= iUnit && 0 <= iCChannels && iCChannels <= 4);

    int iMaxUnits = (int)m_kCChannels.size();
    if (iUnit >= iMaxUnits)
    {
        m_kCChannels.resize(iUnit+1);
    }

    m_kCChannels[iUnit] = iCChannels;
    UpdateOffsets();
}
//----------------------------------------------------------------------------
void Attributes::SetTChannels (int iUnit, int iTChannels)
{
    assert(0 <= iUnit && 0 <= iTChannels && iTChannels <= 4);

    int iMaxUnits = (int)m_kTChannels.size();
    if (iUnit >= iMaxUnits)
    {
        m_kTChannels.resize(iUnit+1);
    }

    m_kTChannels[iUnit] = iTChannels;
    UpdateOffsets();
}
//----------------------------------------------------------------------------
int Attributes::GetCOffset (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kCOffset.size())
    {
        return m_kCOffset[iUnit];
    }
    return -1;
}
//----------------------------------------------------------------------------
int Attributes::GetCChannels (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kCChannels.size())
    {
        return m_kCChannels[iUnit];
    }
    return 0;
}
//----------------------------------------------------------------------------
bool Attributes::HasColor (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kCChannels.size())
    {
        return m_kCChannels[iUnit] > 0;
    }
    return false;
}
//----------------------------------------------------------------------------
int Attributes::GetTOffset (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kTOffset.size())
    {
        return m_kTOffset[iUnit];
    }
    return -1;
}
//----------------------------------------------------------------------------
int Attributes::GetTChannels (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kTChannels.size())
    {
        return m_kTChannels[iUnit];
    }
    return 0;
}
//----------------------------------------------------------------------------
bool Attributes::HasTCoord (int iUnit) const
{
    if (0 <= iUnit && iUnit < (int)m_kTChannels.size())
    {
        return m_kTChannels[iUnit] > 0;
    }
    return false;
}
//----------------------------------------------------------------------------
bool Attributes::Matches (const Attributes& rkAttr, bool bIncludeP,
    bool bIncludeN, bool bIncludeC, bool bIncludeT) const
{
    int i;

    if (bIncludeP)
    {
        if (m_iPChannels != rkAttr.m_iPChannels)
        {
            return false;
        }
    }

    if (bIncludeN)
    {
        if (m_iNChannels != rkAttr.m_iNChannels)
        {
            return false;
        }
    }

    if (bIncludeC)
    {
        if (m_kCChannels.size() != rkAttr.m_kCChannels.size())
        {
            return false;
        }
        for (i = 0; i < (int)m_kCChannels.size(); i++)
        {
            if (m_kCChannels[i] != rkAttr.m_kCChannels[i])
            {
                return false;
            }
        }
    }

    if (bIncludeT)
    {
        if (m_kTChannels.size() != rkAttr.m_kTChannels.size())
        {
            return false;
        }
        for (i = 0; i < (int)m_kTChannels.size(); i++)
        {
            if (m_kTChannels[i] != rkAttr.m_kTChannels[i])
            {
                return false;
            }
        }
    }

    return true;
}
//----------------------------------------------------------------------------
bool Attributes::operator== (const Attributes& rkAttr) const
{
    // We need self.value == rkAttr.value for all values.
    int i;

    if (rkAttr.m_iPChannels != m_iPChannels)
    {
        return false;
    }

    if (rkAttr.m_iNChannels != m_iNChannels)
    {
        return false;
    }

    if (rkAttr.m_kCChannels.size() != m_kCChannels.size())
    {
        return false;
    }
    for (i = 0; i < (int)m_kCChannels.size(); i++)
    {
        if (rkAttr.m_kCChannels[i] != m_kCChannels[i])
        {
            return false;
        }
    }

    if (rkAttr.m_kTChannels.size() != m_kTChannels.size())
    {
        return false;
    }
    for (i = 0; i < (int)m_kTChannels.size(); i++)
    {
        if (rkAttr.m_kTChannels[i] != m_kTChannels[i])
        {
            return false;
        }
    }

    return true;
}
//----------------------------------------------------------------------------
bool Attributes::operator!= (const Attributes& rkAttr) const
{
    return !operator==(rkAttr);
}
//----------------------------------------------------------------------------
void Attributes::UpdateOffsets ()
{
    m_iChannelQuantity = 0;
    m_iPOffset = -1;
    m_iNOffset = -1;
    m_kCOffset.resize(m_kCChannels.size());
    m_kTOffset.resize(m_kTChannels.size());

    if (m_iPChannels > 0)
    {
        m_iPOffset = m_iChannelQuantity;
        m_iChannelQuantity += m_iPChannels;
    }

    if (m_iNChannels > 0)
    {
        m_iNOffset = m_iChannelQuantity;
        m_iChannelQuantity += m_iNChannels;
    }

    int i;
    for (i = 0; i < (int)m_kCChannels.size(); i++)
    {
        if (m_kCChannels[i] > 0)
        {
            m_kCOffset[i] = m_iChannelQuantity;
            m_iChannelQuantity += m_kCChannels[i];
        }
    }

    for (i = 0; i < (int)m_kTChannels.size(); i++)
    {
        if (m_kTChannels[i] > 0)
        {
            m_kTOffset[i] = m_iChannelQuantity;
            m_iChannelQuantity += m_kTChannels[i];
        }
    }
}
//----------------------------------------------------------------------------
