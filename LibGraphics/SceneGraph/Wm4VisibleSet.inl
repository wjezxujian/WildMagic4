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
inline int VisibleSet::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline VisibleObject* VisibleSet::GetVisible ()
{
    return m_akVisible;
}
//----------------------------------------------------------------------------
inline VisibleObject& VisibleSet::GetVisible (int i)
{
    assert(0 <= i && i < m_iQuantity);
    return m_akVisible[i];
}
//----------------------------------------------------------------------------
inline void VisibleSet::Clear ()
{
    m_iQuantity = 0;
}
//----------------------------------------------------------------------------
