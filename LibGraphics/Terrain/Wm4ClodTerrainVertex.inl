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
inline void ClodTerrainVertex::SetDependent (int i,
    ClodTerrainVertex* pkDependent)
{
    assert(0 <= i && i <= 1);
    m_akDependent[i] = pkDependent;
}
//----------------------------------------------------------------------------
inline ClodTerrainVertex* ClodTerrainVertex::GetDependent (int i)
{
    assert(0 <= i && i <= 1);
    return m_akDependent[i];
}
//----------------------------------------------------------------------------
inline bool ClodTerrainVertex::GetEnabled () const
{
    return m_bEnabled;
}
//----------------------------------------------------------------------------
