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
#include "Wm4ClodMesh.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,ClodMesh,TriMesh);
WM4_IMPLEMENT_STREAM(ClodMesh);
WM4_IMPLEMENT_DEFAULT_NAME_ID(ClodMesh,TriMesh);

//----------------------------------------------------------------------------
ClodMesh::ClodMesh (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer,
    int iRecordQuantity, CollapseRecord* akRecord)
    :
    TriMesh(pkVBuffer,pkIBuffer)
{
    assert(iRecordQuantity > 0 && akRecord);

    m_iTargetRecord = 0;
    m_iCurrentRecord = 0;
    m_iRecordQuantity = iRecordQuantity;
    m_akRecord = akRecord;
}
//----------------------------------------------------------------------------
ClodMesh::ClodMesh ()
{
    m_iTargetRecord = 0;
    m_iCurrentRecord = 0;
    m_iRecordQuantity = 0;
    m_akRecord = 0;
}
//----------------------------------------------------------------------------
ClodMesh::~ClodMesh ()
{
    WM4_DELETE[] m_akRecord;
}
//----------------------------------------------------------------------------
void ClodMesh::SelectLevelOfDetail ()
{
    // Get target record.  The virtual function may be overridden by a
    // derived class to obtain a desired automated change in the target.
    int iTargetRecord = GetAutomatedTargetRecord();

    // collapse mesh (if necessary)
    int* aiIndex = IBuffer->GetData();
    int i, iC;
    while (m_iCurrentRecord < iTargetRecord)
    {
        m_iCurrentRecord++;

        // replace indices in connectivity array
        CollapseRecord& rkRecord = m_akRecord[m_iCurrentRecord];
        for (i = 0; i < rkRecord.IQuantity; i++)
        {
            iC = rkRecord.Index[i];
            assert(aiIndex[iC] == rkRecord.VThrow);
            aiIndex[iC] = rkRecord.VKeep;
        }

        // reduce vertex count (vertices are properly ordered)
        VBuffer->SetVertexQuantity(rkRecord.VQuantity);

        // reduce triangle count (triangles are properly ordered)
        IBuffer->SetIndexQuantity(3*rkRecord.TQuantity);

        // The vertices are unchanged, so only the index buffer needs
        // refreshing.
        IBuffer->Release();
    }

    // expand mesh (if necessary)
    while (m_iCurrentRecord > iTargetRecord)
    {
        // restore indices in connectivity array
        CollapseRecord& rkRecord = m_akRecord[m_iCurrentRecord];
        for (i = 0; i < rkRecord.IQuantity; i++)
        {
            iC = rkRecord.Index[i];
            assert(aiIndex[iC] == rkRecord.VKeep);
            aiIndex[iC] = rkRecord.VThrow;
        }

        m_iCurrentRecord--;
        CollapseRecord& rkPrevRecord = m_akRecord[m_iCurrentRecord];

        // increase vertex count (vertices are properly ordered)
        VBuffer->SetVertexQuantity(rkPrevRecord.VQuantity);

        // increase triangle count (triangles are properly ordered)
        IBuffer->SetIndexQuantity(3*rkPrevRecord.TQuantity);

        // The vertices are unchanged, so only the index buffer needs
        // refreshing.
        IBuffer->Release();
    }
}
//----------------------------------------------------------------------------
void ClodMesh::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    SelectLevelOfDetail();
    TriMesh::GetVisibleSet(rkCuller,bNoCull);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void ClodMesh::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    TriMesh::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_iCurrentRecord);
    rkStream.Read(m_iTargetRecord);
    rkStream.Read(m_iRecordQuantity);
    if (m_iRecordQuantity)
    {
        m_akRecord = WM4_NEW CollapseRecord[m_iRecordQuantity];
        for (int i = 0; i < m_iRecordQuantity; i++)
        {
            m_akRecord[i].Read(rkStream);
        }
    }
    else
    {
        m_akRecord = 0;
    }

    WM4_END_DEBUG_STREAM_LOAD(ClodMesh);
}
//----------------------------------------------------------------------------
void ClodMesh::Link (Stream& rkStream, Stream::Link* pkLink)
{
    TriMesh::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool ClodMesh::Register (Stream& rkStream) const
{
    return TriMesh::Register(rkStream);
}
//----------------------------------------------------------------------------
void ClodMesh::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    TriMesh::Save(rkStream);

    // native data
    rkStream.Write(m_iCurrentRecord);
    rkStream.Write(m_iTargetRecord);
    rkStream.Write(m_iRecordQuantity);
    for (int i = 0; i < m_iRecordQuantity; i++)
    {
        m_akRecord[i].Write(rkStream);
    }

    WM4_END_DEBUG_STREAM_SAVE(ClodMesh);
}
//----------------------------------------------------------------------------
int ClodMesh::GetDiskUsed (const StreamVersion& rkVersion) const
{
    int iSize = TriMesh::GetDiskUsed(rkVersion) +
        sizeof(m_iCurrentRecord) +
        sizeof(m_iTargetRecord) +
        sizeof(m_iRecordQuantity);

    for (int i = 0; i < m_iRecordQuantity; i++)
    {
        iSize += m_akRecord[i].GetDiskUsed();
    }

    return iSize;
}
//----------------------------------------------------------------------------
StringTree* ClodMesh::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("curr rec =",m_iCurrentRecord));
    pkTree->Append(Format("targ rec =",m_iTargetRecord));
    pkTree->Append(Format("rec quantity =",m_iRecordQuantity));

    // children
    pkTree->Append(TriMesh::SaveStrings());

    StringTree* pkAttrTree = WM4_NEW StringTree;
    pkAttrTree->Append(Format("records"));
    for (int i = 0; i < m_iRecordQuantity; i++)
    {
        CollapseRecord& rkRecord = m_akRecord[i];

        const size_t uiStringSize = 1024;
        const size_t uiDummySize = 128;
        char acString[uiStringSize], acDummy[uiDummySize];
        System::Sprintf(acString,uiStringSize,"keep = %d, ",rkRecord.VKeep);

        System::Sprintf(acDummy,uiDummySize,"throw = %d, ",rkRecord.VThrow);
        System::Strcat(acString,uiDummySize,acDummy);

        System::Sprintf(acDummy,uiDummySize,"vq = %d, ",rkRecord.VQuantity);
        System::Strcat(acString,uiDummySize,acDummy);

        System::Sprintf(acDummy,uiDummySize,"tq = %d, ",rkRecord.TQuantity);
        System::Strcat(acString,uiDummySize,acDummy);

        System::Sprintf(acDummy,uiDummySize,"iq = %d",rkRecord.IQuantity);
        System::Strcat(acString,uiDummySize,acDummy);

        pkAttrTree->Append(Format(acString,rkRecord.IQuantity,
            rkRecord.Index));
    }
    pkTree->Append(pkAttrTree);

    return pkTree;
}
//----------------------------------------------------------------------------
