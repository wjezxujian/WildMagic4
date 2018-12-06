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
inline int Stream::GetOrderedQuantity () const
{
    return (int)m_kOrdered.size();
}
//----------------------------------------------------------------------------
inline Object* Stream::GetOrderedObject (int i) const
{
    assert(0 <= i && i < (int)m_kOrdered.size());
    if (i < 0 || i >= (int)m_kOrdered.size())
    {
        return 0;
    }

    return m_kOrdered[i];
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferSize () const
{
    return m_iBufferSize;
}
//----------------------------------------------------------------------------
inline int Stream::GetBufferNext () const
{
    return m_iBufferNext;
}
//----------------------------------------------------------------------------
inline StreamVersion Stream::GetVersion () const
{
    return m_kVersion;
}
//----------------------------------------------------------------------------
