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
#include "Wm4ConvexRegion.h"
#include "Wm4Portal.h"
#include "Wm4Renderer.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,ConvexRegion,Node);
WM4_IMPLEMENT_STREAM(ConvexRegion);

//----------------------------------------------------------------------------
ConvexRegion::ConvexRegion (int iPQuantity, Portal** apkPortal)
{
    m_iPQuantity = iPQuantity;
    m_apkPortal = apkPortal;
    m_bVisited = false;
}
//----------------------------------------------------------------------------
ConvexRegion::ConvexRegion ()
{
    m_iPQuantity = 0;
    m_apkPortal = 0;
    m_bVisited = false;
}
//----------------------------------------------------------------------------
ConvexRegion::~ConvexRegion ()
{
    for (int i = 0; i < m_iPQuantity; i++)
    {
        WM4_DELETE m_apkPortal[i];
    }

    WM4_DELETE[] m_apkPortal;
}
//----------------------------------------------------------------------------
void ConvexRegion::UpdateWorldData (double dAppTime)
{
    // Update the region walls and contained objects.
    Node::UpdateWorldData(dAppTime);

    // Update the portal geometry.
    for (int i = 0; i < m_iPQuantity; i++)
    {
        m_apkPortal[i]->UpdateWorldData(World);
    }
}
//----------------------------------------------------------------------------
void ConvexRegion::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    if (!m_bVisited)
    {
        m_bVisited = true;

        // Add anything visible through open portals.
        for (int i = 0; i < m_iPQuantity; i++)
        {
            m_apkPortal[i]->GetVisibleSet(rkCuller,bNoCull);
        }

        // Add the region walls and contained objects.
        Node::GetVisibleSet(rkCuller,bNoCull);

        m_bVisited = false;
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* ConvexRegion::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Node::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    for (int i = 0; i < m_iPQuantity; i++)
    {
        pkFound = m_apkPortal[i]->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void ConvexRegion::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Node::GetAllObjectsByName(rkName,rkObjects);

    for (int i = 0; i < m_iPQuantity; i++)
    {
        m_apkPortal[i]->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* ConvexRegion::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Node::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    for (int i = 0; i < m_iPQuantity; i++)
    {
        pkFound = m_apkPortal[i]->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void ConvexRegion::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Node::Load(rkStream,pkLink);

    // link data
    rkStream.Read(m_iPQuantity);
    if (m_iPQuantity > 0)
    {
        m_apkPortal = WM4_NEW Portal*[m_iPQuantity];
        for (int i = 0; i < m_iPQuantity; i++)
        {
            Object* pkPortal;
            rkStream.Read(pkPortal);
            pkLink->Add(pkPortal);
        }
    }

    WM4_END_DEBUG_STREAM_LOAD(ConvexRegion);
}
//----------------------------------------------------------------------------
void ConvexRegion::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Node::Link(rkStream,pkLink);

    for (int i = 0; i < m_iPQuantity; i++)
    {
        Object* pkLinkID = pkLink->GetLinkID();
        m_apkPortal[i] = (Portal*)rkStream.GetFromMap(pkLinkID);
    }
}
//----------------------------------------------------------------------------
bool ConvexRegion::Register (Stream& rkStream) const
{
    if (!Node::Register(rkStream))
    {
        return false;
    }

    for (int i = 0; i < m_iPQuantity; i++)
    {
        m_apkPortal[i]->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void ConvexRegion::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Node::Save(rkStream);

    // link data
    rkStream.Write(m_iPQuantity);
    for (int i = 0; i < m_iPQuantity; i++)
    {
        rkStream.Write(m_apkPortal[i]);
    }

    WM4_END_DEBUG_STREAM_SAVE(ConvexRegion);
}
//----------------------------------------------------------------------------
int ConvexRegion::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Node::GetDiskUsed(rkVersion) +
        sizeof(m_iPQuantity) +
        m_iPQuantity*sizeof(m_apkPortal[0]);
}
//----------------------------------------------------------------------------
StringTree* ConvexRegion::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("portal quantity =",m_iPQuantity));

    // children
    pkTree->Append(Node::SaveStrings());
    for (int i = 0; i < m_iPQuantity; i++)
    {
        pkTree->Append(m_apkPortal[i]->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
