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
inline int SoftFrameBuffer::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int SoftFrameBuffer::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline int SoftFrameBuffer::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
inline void SoftFrameBuffer::SetColorBufferUI (unsigned int* auiColorBuffer)
{
    m_auiColorBuffer = auiColorBuffer;
    m_bColorBufferOwner = false;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetColorBufferUI () const
{
    return m_auiColorBuffer;
}
//----------------------------------------------------------------------------
inline ColorRGBA* SoftFrameBuffer::GetColorBufferRGBA () const
{
    return m_akColorBuffer;
}
//----------------------------------------------------------------------------
inline unsigned int SoftFrameBuffer::GetMaxDepthValue () const
{
    return m_uiMaxDepthValue;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetDepthBufferUI () const
{
    return m_auiDepthBuffer;
}
//----------------------------------------------------------------------------
inline float* SoftFrameBuffer::GetDepthBufferF () const
{
    return m_afDepthBuffer;
}
//----------------------------------------------------------------------------
inline unsigned int SoftFrameBuffer::GetMaxStencilValue () const
{
    return m_uiMaxStencilValue;
}
//----------------------------------------------------------------------------
inline unsigned int* SoftFrameBuffer::GetStencilBuffer () const
{
    return m_auiStencilBuffer;
}
//----------------------------------------------------------------------------
