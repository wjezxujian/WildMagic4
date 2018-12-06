// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline int Attributes::GetChannelQuantity () const
{
    return m_iChannelQuantity;
}
//----------------------------------------------------------------------------
inline int Attributes::GetPOffset () const
{
    return m_iPOffset;
}
//----------------------------------------------------------------------------
inline int Attributes::GetPChannels () const
{
    return m_iPChannels;
}
//----------------------------------------------------------------------------
inline bool Attributes::HasPosition () const
{
    return m_iPChannels > 0;
}
//----------------------------------------------------------------------------
inline int Attributes::GetNOffset () const
{
    return m_iNOffset;
}
//----------------------------------------------------------------------------
inline int Attributes::GetNChannels () const
{
    return m_iNChannels;
}
//----------------------------------------------------------------------------
inline bool Attributes::HasNormal () const
{
    return m_iNChannels > 0;
}
//----------------------------------------------------------------------------
inline int Attributes::GetMaxColors () const
{
    return (int)m_kCChannels.size();
}
//----------------------------------------------------------------------------
inline int Attributes::GetMaxTCoords () const
{
    return (int)m_kTChannels.size();
}
//----------------------------------------------------------------------------
