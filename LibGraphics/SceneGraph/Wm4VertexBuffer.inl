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
inline const Attributes& VertexBuffer::GetAttributes () const
{
    return m_kAttributes;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetVertexSize () const
{
    return m_iVertexSize;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetVertexQuantity () const
{
    return m_iVertexQuantity;
}
//----------------------------------------------------------------------------
inline int VertexBuffer::GetChannelQuantity () const
{
    return m_iChannelQuantity;
}
//----------------------------------------------------------------------------
inline float* VertexBuffer::GetData ()
{
    return m_afChannel;
}
//----------------------------------------------------------------------------
inline const float* VertexBuffer::GetData () const
{
    return m_afChannel;
}
//----------------------------------------------------------------------------
inline void VertexBuffer::SetVertexQuantity (int iVQuantity)
{
    m_iVertexQuantity = iVQuantity;
}
//----------------------------------------------------------------------------
