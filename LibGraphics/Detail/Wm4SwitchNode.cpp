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
#include "Wm4SwitchNode.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SwitchNode,Node);
WM4_IMPLEMENT_STREAM(SwitchNode);
WM4_IMPLEMENT_DEFAULT_NAME_ID(SwitchNode,Node);

//----------------------------------------------------------------------------
SwitchNode::SwitchNode ()
{
    m_iActiveChild = SN_INVALID_CHILD;
}
//----------------------------------------------------------------------------
SwitchNode::~SwitchNode ()
{
}
//----------------------------------------------------------------------------
void SwitchNode::DoPick (const Ray3f& rkRay, PickArray& rkResults)
{
    if (m_iActiveChild != SN_INVALID_CHILD)
    {
        if (WorldBound->TestIntersection(rkRay))
        {
            Spatial* pkChild = m_kChild[m_iActiveChild];
            if (pkChild)
            {
                pkChild->DoPick(rkRay,rkResults);
            }
        }
    }
}
//----------------------------------------------------------------------------
void SwitchNode::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    if (m_iActiveChild == SN_INVALID_CHILD)
    {
        return;
    }

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
    Spatial* pkChild = m_kChild[m_iActiveChild];
    if (pkChild)
    {
        pkChild->OnGetVisibleSet(rkCuller,bNoCull);
    }

    for (i = 0; i < (int)m_kEffects.size(); i++)
    {
        // Place an 'end' marker in the visible set to indicate that the
        // global effect is inactive.
        rkCuller.Insert(0,0);
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SwitchNode::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Node::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_iActiveChild);

    WM4_END_DEBUG_STREAM_LOAD(SwitchNode);
}
//----------------------------------------------------------------------------
void SwitchNode::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Node::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool SwitchNode::Register (Stream& rkStream) const
{
    return Node::Register(rkStream);
}
//----------------------------------------------------------------------------
void SwitchNode::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Node::Save(rkStream);

    // native data
    rkStream.Write(m_iActiveChild);

    WM4_END_DEBUG_STREAM_SAVE(SwitchNode);
}
//----------------------------------------------------------------------------
int SwitchNode::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Node::GetDiskUsed(rkVersion) +
        sizeof(m_iActiveChild);
}
//----------------------------------------------------------------------------
StringTree* SwitchNode::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("active =",m_iActiveChild));

    // children
    pkTree->Append(Node::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
