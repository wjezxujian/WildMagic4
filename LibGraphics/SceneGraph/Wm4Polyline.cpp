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
#include "Wm4Polyline.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Polyline,Geometry);
WM4_IMPLEMENT_STREAM(Polyline);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Polyline,Geometry);

//----------------------------------------------------------------------------
Polyline::Polyline (VertexBuffer* pkVBuffer, bool bClosed, bool bContiguous)
    :
    Geometry(pkVBuffer,0)
{
    int iVQuantity = VBuffer->GetVertexQuantity();
    assert(iVQuantity >= 2);

    m_iActiveQuantity = iVQuantity;
    m_bClosed = bClosed;
    m_bContiguous = bContiguous;

    // One extra slot is allocated for the indices to allow for closed
    // polylines.  In that case, aiIndex[iVQuantity] is set to aiIndex[0].
    IBuffer = WM4_NEW IndexBuffer(iVQuantity+1);
    int* aiIndex = IBuffer->GetData();
    for (int i = 0; i < iVQuantity; i++)
    {
        aiIndex[i] = i;
    }
    aiIndex[iVQuantity] = 0;

    if (!m_bContiguous || !m_bClosed)
    {
        // If the curve starts out not closed, reduce the index quantity so
        // that the renderer ignores the extra index.
        IBuffer->SetIndexQuantity(iVQuantity);
    }

    SetGeometryType();
}
//----------------------------------------------------------------------------
Polyline::Polyline ()
{
    m_iActiveQuantity = 0;
    m_bClosed = false;
    m_bContiguous = false;
    SetGeometryType();
}
//----------------------------------------------------------------------------
Polyline::~Polyline ()
{
}
//----------------------------------------------------------------------------
void Polyline::SetGeometryType ()
{
    if (m_bContiguous)
    {
        if (m_bClosed)
        {
            if (Type != GT_POLYLINE_CLOSED)
            {
                // Increase the index quantity to account for closing the
                // polyline.
                IBuffer->SetIndexQuantity(IBuffer->GetIndexQuantity()+1);
                IBuffer->Release();
            }
            Type = GT_POLYLINE_CLOSED;
        }
        else
        {
            if (Type == GT_POLYLINE_CLOSED)
            {
                // Decrease the index quantity to account for closing the
                // polyline.
                IBuffer->SetIndexQuantity(IBuffer->GetIndexQuantity()-1);
                IBuffer->Release();
            }
            Type = GT_POLYLINE_OPEN;
        }
    }
    else
    {
        if (Type == GT_POLYLINE_CLOSED)
        {
            // Decrease the index quantity to account for closing the
            // polyline.
            IBuffer->SetIndexQuantity(IBuffer->GetIndexQuantity()-1);
            IBuffer->Release();
        }
        Type = GT_POLYLINE_SEGMENTS;
    }
}
//----------------------------------------------------------------------------
void Polyline::SetActiveQuantity (int iActiveQuantity)
{
    int iVQuantity = VBuffer->GetVertexQuantity();
    if (0 <= iActiveQuantity && iActiveQuantity <= iVQuantity)
    {
        m_iActiveQuantity = iActiveQuantity;
    }
    else
    {
        m_iActiveQuantity = iVQuantity;
    }

    IBuffer->SetIndexQuantity(m_iActiveQuantity);
}
//----------------------------------------------------------------------------
void Polyline::SetClosed (bool bClosed)
{
    m_bClosed = bClosed;
    SetGeometryType();
}
//----------------------------------------------------------------------------
void Polyline::SetContiguous (bool bContiguous)
{
    m_bContiguous = bContiguous;
    SetGeometryType();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Polyline::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Geometry::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_iActiveQuantity);
    rkStream.Read(m_bClosed);
    rkStream.Read(m_bContiguous);

    SetGeometryType();

    WM4_END_DEBUG_STREAM_LOAD(Polyline);
}
//----------------------------------------------------------------------------
void Polyline::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Geometry::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool Polyline::Register (Stream& rkStream) const
{
    return Geometry::Register(rkStream);
}
//----------------------------------------------------------------------------
void Polyline::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Geometry::Save(rkStream);

    // native data
    rkStream.Write(m_iActiveQuantity);
    rkStream.Write(m_bClosed);
    rkStream.Write(m_bContiguous);

    WM4_END_DEBUG_STREAM_SAVE(Polyline);
}
//----------------------------------------------------------------------------
int Polyline::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Geometry::GetDiskUsed(rkVersion) +
        sizeof(m_iActiveQuantity) +
        sizeof(char) + // m_bClosed
        sizeof(char);  // m_bContiguous
}
//----------------------------------------------------------------------------
StringTree* Polyline::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("active quantity =",m_iActiveQuantity));
    pkTree->Append(Format("closed =",m_bClosed));
    pkTree->Append(Format("contiguous =",m_bContiguous));

    // children
    pkTree->Append(Geometry::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
