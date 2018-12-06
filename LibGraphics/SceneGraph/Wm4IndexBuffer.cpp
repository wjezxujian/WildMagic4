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
#include "Wm4IndexBuffer.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,IndexBuffer,Object);
WM4_IMPLEMENT_STREAM(IndexBuffer);
WM4_IMPLEMENT_DEFAULT_NAME_ID(IndexBuffer,Object);

//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer (int iIQuantity)
{
    assert(iIQuantity > 0);

    m_iIQuantity = iIQuantity;
    m_aiIndex = WM4_NEW int[m_iIQuantity];
    memset(m_aiIndex,0,m_iIQuantity*sizeof(int));
}
//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer (const IndexBuffer* pkIBuffer)
{
    assert(pkIBuffer);
    m_iIQuantity = pkIBuffer->m_iIQuantity;
    m_aiIndex = WM4_NEW int[m_iIQuantity];
    size_t uiSize = m_iIQuantity*sizeof(int);
    System::Memcpy(m_aiIndex,uiSize,pkIBuffer->m_aiIndex,uiSize);
}
//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer ()
{
    m_iIQuantity = 0;
    m_aiIndex = 0;
}
//----------------------------------------------------------------------------
IndexBuffer::~IndexBuffer ()
{
    // Inform all renderers using this index buffer that it is being
    // destroyed.  This allows the renderer to free up any associated
    // resources.
    Release();

    WM4_DELETE[] m_aiIndex;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void IndexBuffer::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    rkStream.Read(m_iIQuantity);
    m_aiIndex = WM4_NEW int[m_iIQuantity];
    rkStream.Read(m_iIQuantity,m_aiIndex);

    WM4_END_DEBUG_STREAM_LOAD(IndexBuffer);
}
//----------------------------------------------------------------------------
void IndexBuffer::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool IndexBuffer::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void IndexBuffer::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);
    rkStream.Write(m_iIQuantity);
    rkStream.Write(m_iIQuantity,m_aiIndex);

    WM4_END_DEBUG_STREAM_SAVE(IndexBuffer);
}
//----------------------------------------------------------------------------
int IndexBuffer::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion) +
        sizeof(m_iIQuantity) +
        m_iIQuantity*sizeof(m_aiIndex[0]);
}
//----------------------------------------------------------------------------
StringTree* IndexBuffer::SaveStrings (const char* acTitle)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    // children
    pkTree->Append(Object::SaveStrings());
    pkTree->Append(Format(acTitle,m_iIQuantity,m_aiIndex));

    return pkTree;
}
//----------------------------------------------------------------------------
