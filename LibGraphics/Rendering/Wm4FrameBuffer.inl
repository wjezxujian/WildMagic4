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
inline FrameBuffer::FormatType FrameBuffer::GetFormatType () const
{
    return m_eFormat;
}
//----------------------------------------------------------------------------
inline FrameBuffer::DepthType FrameBuffer::GetDepthType () const
{
    return m_eDepth;
}
//----------------------------------------------------------------------------
inline FrameBuffer::StencilType FrameBuffer::GetStencilType () const
{
    return m_eStencil;
}
//----------------------------------------------------------------------------
inline FrameBuffer::BufferingType FrameBuffer::GetBufferingType () const
{
    return m_eBuffering;
}
//----------------------------------------------------------------------------
inline FrameBuffer::MultisamplingType FrameBuffer::GetMultisamplingType ()
    const
{
    return m_eMultisampling;
}
//----------------------------------------------------------------------------
inline Renderer* FrameBuffer::GetRenderer ()
{
    return m_pkRenderer;
}
//----------------------------------------------------------------------------
inline Texture* FrameBuffer::GetTarget ()
{
    return m_pkTarget;
}
//----------------------------------------------------------------------------
