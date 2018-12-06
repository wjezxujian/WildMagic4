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
inline int IndexBuffer::GetIndexQuantity () const
{
    return m_iIQuantity;
}
//----------------------------------------------------------------------------
inline int* IndexBuffer::GetData ()
{
    return m_aiIndex;
}
//----------------------------------------------------------------------------
inline const int* IndexBuffer::GetData () const
{
    return m_aiIndex;
}
//----------------------------------------------------------------------------
inline int IndexBuffer::operator[] (int i) const
{
    assert(0 <= i && i < m_iIQuantity);
    return m_aiIndex[i];
}
//----------------------------------------------------------------------------
inline int& IndexBuffer::operator[] (int i)
{
    assert(0 <= i && i < m_iIQuantity);
    return m_aiIndex[i];
}
//----------------------------------------------------------------------------
inline void IndexBuffer::SetIndexQuantity (int iIQuantity)
{
    m_iIQuantity = iIQuantity;
}
//----------------------------------------------------------------------------
