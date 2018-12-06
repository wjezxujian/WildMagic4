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
#include "Wm4Node.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Node,Spatial);
WM4_IMPLEMENT_STREAM(Node);

//----------------------------------------------------------------------------
Node::Node ()
{
}
//----------------------------------------------------------------------------
Node::~Node ()
{
    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        SpatialPtr spkChild = DetachChildAt(i);
        spkChild = 0;
    }
}
//----------------------------------------------------------------------------
int Node::AttachChild (Spatial* pkChild)
{
    // Some folks are under the impression that a node can have multiple
    // parents, the scene graph therefore being a DAG.  That is not the case.
    // The parent-child relationships form a tree.  This assertion is to let
    // folks know this and to warn them that a child is being kidnapped from
    // another parent.  To be safe, you should really call DetachChild before
    // you reattach somewhere else with AttachChild or SetChild.  If you do
    // call DetachChild first, be aware that the child might self-destruct.
    // If you want this not to happen, hang onto the child via a smart
    // pointer.  For example,
    //
    //     Node* pkNode0 = WM4_NEW Node;
    //     Spatial* pkChild0 = <...>;
    //     pkNode0->AttachChild(pkChild0);  // child at index 0
    //     Node* pkNode1 = <...>;
    //
    //     // This asserts because pkChild0 already has a parent (pkNode0).
    //     pkNode1->AttachChild(pkChild0);
    //
    //     // Instead do this and avoid the potential self-destruction of
    //     // pkChild0).
    //     SpatialPtr spkSaveChild = pkNode0->GetChild(0);
    //     pkNode0->DetachChild(spkSaveChild);
    //     pkNode1->AttachChild(spkSaveChild);

    assert(pkChild && !pkChild->GetParent());

    pkChild->SetParent(this);

    // attach child in first available slot (if any)
    int iQuantity = (int)m_kChild.size();
    for (int i = 0; i < iQuantity; i++)
    {
        if (m_kChild[i] == 0)
        {
            m_kChild[i] = pkChild;
            return i;
        }
    }

    // all slots used, increase array size
    m_kChild.push_back(pkChild);
    return iQuantity;
}
//----------------------------------------------------------------------------
int Node::DetachChild (Spatial* pkChild)
{
    if (pkChild)
    {
        // search to see if child exists
        for (int i = 0; i < (int)m_kChild.size(); i++)
        {
            if (m_kChild[i] == pkChild)
            {
                // child found, detach it
                pkChild->SetParent(0);
                m_kChild[i] = 0;
                return i;
            }
        }
    }

    return -1;
}
//----------------------------------------------------------------------------
SpatialPtr Node::DetachChildAt (int i)
{
    if (0 <= i && i < (int)m_kChild.size())
    {
        SpatialPtr spkChild = m_kChild[i];
        if (spkChild)
        {
            // child exists in slot, detach it
            spkChild->SetParent(0);
            m_kChild[i] = 0;
        }
        return spkChild;
    }
    return 0;
}
//----------------------------------------------------------------------------
SpatialPtr Node::SetChild (int i, Spatial* pkChild)
{
    // Some folks are under the impression that a node can have multiple
    // parents, the scene graph therefore being a DAG.  That is not the case.
    // The parent-child relationships form a tree.  This assertion is to let
    // folks know this and to warn them that a child is being kidnapped from
    // another parent.  To be safe, you should really call DetachChild before
    // you reattach somewhere else with AttachChild or SetChild.  If you do
    // call DetachChild first, be aware that the child might self-destruct.
    // If you want this not to happen, hang onto the child via a smart
    // pointer.  For example,
    //
    //     Node* pkNode0 = WM4_NEW Node;
    //     Spatial* pkChild0 = <...>;
    //     pkNode0->AttachChild(pkChild0);  // child at index 0
    //     Node* pkNode1 = <...>;
    //
    //     // This asserts because pkChild0 already has a parent (pkNode0).
    //     pkNode1->AttachChild(pkChild0);
    //
    //     // Instead do this and avoid the potential self-destruction of
    //     // pkChild0).
    //     SpatialPtr spkSaveChild = pkNode0->GetChild(0);
    //     pkNode0->DetachChild(spkSaveChild);
    //     pkNode1->AttachChild(spkSaveChild);

    if (pkChild)
    {
        assert(!pkChild->GetParent());
    }

    if (0 <= i && i < (int)m_kChild.size())
    {
        // detach child currently in slot
        SpatialPtr spkPreviousChild = m_kChild[i];
        if (spkPreviousChild)
        {
            spkPreviousChild->SetParent(0);
        }

        // attach new child to slot
        if (pkChild)
        {
            pkChild->SetParent(this);
        }

        m_kChild[i] = pkChild;
        return spkPreviousChild;
    }

    // index out of range, increase array size and attach new child
    pkChild->SetParent(this);
    m_kChild.push_back(pkChild);
    return 0;
}
//----------------------------------------------------------------------------
SpatialPtr Node::GetChild (int i)
{
    if (0 <= i && i < (int)m_kChild.size())
    {
        return m_kChild[i];
    }
    return 0;
}
//----------------------------------------------------------------------------
void Node::UpdateWorldData (double dAppTime)
{
    Spatial::UpdateWorldData(dAppTime);

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkChild->UpdateGS(dAppTime,false);
        }
    }
}
//----------------------------------------------------------------------------
void Node::UpdateWorldBound ()
{
    if (!WorldBoundIsCurrent)
    {
        bool bFoundFirstBound = false;
        for (int i = 0; i < (int)m_kChild.size(); i++)
        {
            Spatial* pkChild = m_kChild[i];
            if (pkChild)
            {
                if (bFoundFirstBound)
                {
                    // merge current world bound with child world bound
                    WorldBound->GrowToContain(pkChild->WorldBound);
                }
                else
                {
                    // set world bound to first non-null child world bound
                    bFoundFirstBound = true;
                    WorldBound->CopyFrom(pkChild->WorldBound);
                }
            }
        }
    }
}
//----------------------------------------------------------------------------
void Node::UpdateState (std::vector<GlobalState*>* akGStack,
    std::vector<Light*>* pkLStack)
{
    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkChild->UpdateRS(akGStack,pkLStack);
        }
    }
}
//----------------------------------------------------------------------------
void Node::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    int i;
    for (i = 0; i < (int)m_kEffects.size(); i++)
    {
        // This is a global effect.  Place a 'begin' marker in the visible
        // set to indicate the effect is active.
        rkCuller.Insert(this,m_kEffects[i]);
    }

    // All Geometry objects in the subtree are added to the visible set.  If
    // a global effect is active, the Geometry objects in the subtree will be
    // drawn using it.
    for (i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkChild->OnGetVisibleSet(rkCuller,bNoCull);
        }
    }

    for (i = 0; i < (int)m_kEffects.size(); i++)
    {
        // Place an 'end' marker in the visible set to indicate that the
        // global effect is inactive.
        rkCuller.Insert(0,0);
    }
}
//----------------------------------------------------------------------------
void Node::DoPick (const Ray3f& rkRay, PickArray& rkResults)
{
    if (WorldBound->TestIntersection(rkRay))
    {
        for (int i = 0; i < (int)m_kChild.size(); i++)
        {
            Spatial* pkChild = m_kChild[i];
            if (pkChild)
            {
                pkChild->DoPick(rkRay,rkResults);
            }
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* Node::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Spatial::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkFound = pkChild->GetObjectByName(rkName);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void Node::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Spatial::GetAllObjectsByName(rkName,rkObjects);

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkChild->GetAllObjectsByName(rkName,rkObjects);
        }
    }
}
//----------------------------------------------------------------------------
Object* Node::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Spatial::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkFound = pkChild->GetObjectByID(uiID);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Node::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Spatial::Load(rkStream,pkLink);

    // link data
    int iMaxQuantity, iGrowBy, iQuantity;
    rkStream.Read(iMaxQuantity);
    m_kChild.resize(iMaxQuantity);

    // TO DO:  The growby parameter no longer exists, but to remove it
    // requires fixing the streaming system "IsValid" behavior.
    rkStream.Read(iGrowBy);

    rkStream.Read(iQuantity);
    for (int i = 0; i < iMaxQuantity; i++)
    {
        Object* pkObject;
        rkStream.Read(pkObject);
        pkLink->Add(pkObject);
    }

    WM4_END_DEBUG_STREAM_LOAD(Node);
}
//----------------------------------------------------------------------------
void Node::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Spatial::Link(rkStream,pkLink);

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Object* pkLinkID = pkLink->GetLinkID();
        Spatial* pkChild = (Spatial*)rkStream.GetFromMap(pkLinkID);
        if (pkChild)
        {
            SetChild(i,pkChild);
        }
    }
}
//----------------------------------------------------------------------------
bool Node::Register (Stream& rkStream) const
{
    if (!Spatial::Register(rkStream))
    {
        return false;
    }

    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        if (m_kChild[i])
        {
            m_kChild[i]->Register(rkStream);
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void Node::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Spatial::Save(rkStream);

    // link data
    rkStream.Write((int)m_kChild.size());  // was maxquantity

    // TO DO: Delete these lines once streaming is fixed.
    int iGrowBy = 0;
    rkStream.Write(iGrowBy);

    rkStream.Write((int)m_kChild.size());
    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        rkStream.Write(m_kChild[i]);
    }

    WM4_END_DEBUG_STREAM_SAVE(Node);
}
//----------------------------------------------------------------------------
int Node::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Spatial::GetDiskUsed(rkVersion) +
        3*sizeof(int) +  // m_kChild maxquantity, growby, quantity
        ((int)m_kChild.size())*sizeof(m_kChild[0]);
}
//----------------------------------------------------------------------------
StringTree* Node::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("child quantity =",(int)m_kChild.size()));

    // children
    pkTree->Append(Spatial::SaveStrings());
    for (int i = 0; i < (int)m_kChild.size(); i++)
    {
        Spatial* pkChild = m_kChild[i];
        if (pkChild)
        {
            pkTree->Append(pkChild->SaveStrings());
        }
        else
        {
            StringTree* pkEmpty = WM4_NEW StringTree;
            pkEmpty->Append(Format("unused slot"));
            pkTree->Append(pkEmpty);
        }
    }

    return pkTree;
}
//----------------------------------------------------------------------------
