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
#include "Wm4IKGoal.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,IKGoal,Object);
WM4_IMPLEMENT_STREAM(IKGoal);

//----------------------------------------------------------------------------
IKGoal::IKGoal (Spatial* pkTarget, Spatial* pkEffector, float fWeight)
{
    m_spkTarget = pkTarget;
    m_spkEffector = pkEffector;
    Weight = fWeight;
}
//----------------------------------------------------------------------------
IKGoal::IKGoal ()
{
    m_spkTarget = 0;
    m_spkEffector = 0;
    Weight = 1.0f;
}
//----------------------------------------------------------------------------
Vector3f IKGoal::GetTargetPosition () const
{
    return m_spkTarget->World.GetTranslate();
}
//----------------------------------------------------------------------------
Vector3f IKGoal::GetEffectorPosition () const
{
    return m_spkEffector->World.GetTranslate();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* IKGoal::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Object::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkTarget)
    {
        pkFound = m_spkTarget->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkEffector)
    {
        pkFound = m_spkEffector->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void IKGoal::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Object::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkTarget)
    {
        m_spkTarget->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkEffector)
    {
        m_spkEffector->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* IKGoal::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Object::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkTarget)
    {
        pkFound = m_spkTarget->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkEffector)
    {
        pkFound = m_spkEffector->GetObjectByID(uiID);
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
void IKGoal::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Weight);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkTarget
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkEffector
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(IKGoal);
}
//----------------------------------------------------------------------------
void IKGoal::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkTarget = (Spatial*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkEffector = (Spatial*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool IKGoal::Register (Stream& rkStream) const
{
    if (!Object::Register(rkStream))
    {
        return false;
    }

    if (m_spkTarget)
    {
        m_spkTarget->Register(rkStream);
    }

    if (m_spkEffector)
    {
        m_spkEffector->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void IKGoal::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);

    // native data
    rkStream.Write(Weight);

    // link data
    rkStream.Write(m_spkTarget);
    rkStream.Write(m_spkEffector);

    WM4_END_DEBUG_STREAM_SAVE(IKGoal);
}
//----------------------------------------------------------------------------
int IKGoal::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion) +
        sizeof(m_spkTarget) +
        sizeof(m_spkEffector) +
        sizeof(Weight);
}
//----------------------------------------------------------------------------
StringTree* IKGoal::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("weight =",Weight));

    // children
    pkTree->Append(Object::SaveStrings());
    pkTree->Append(m_spkTarget->SaveStrings());
    pkTree->Append(m_spkEffector->SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
