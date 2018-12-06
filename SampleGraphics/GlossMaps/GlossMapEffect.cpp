// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "GlossMapEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,GlossMapEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(GlossMapEffect);

//----------------------------------------------------------------------------
GlossMapEffect::GlossMapEffect (const std::string& rkBaseName,
    Light* pkLight)
    :
    ShaderEffect(1),
    m_spkLight(pkLight)
{
    m_kVShader[0] = WM4_NEW VertexShader("GlossMap");
    m_kPShader[0] = WM4_NEW PixelShader("GlossMap");

    m_kPShader[0]->SetTextureQuantity(1);
    m_kPShader[0]->SetImageName(0,rkBaseName);
}
//----------------------------------------------------------------------------
GlossMapEffect::GlossMapEffect ()
{
}
//----------------------------------------------------------------------------
GlossMapEffect::~GlossMapEffect ()
{
}
//----------------------------------------------------------------------------
void GlossMapEffect::SetGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    ShaderEffect::SetGlobalState(iPass,pkRenderer,bPrimaryEffect);
    pkRenderer->SetLight(0,m_spkLight);
}
//----------------------------------------------------------------------------
void GlossMapEffect::RestoreGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    ShaderEffect::RestoreGlobalState(iPass,pkRenderer,bPrimaryEffect);
    pkRenderer->SetLight(0,0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* GlossMapEffect::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = ShaderEffect::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkLight)
    {
        pkFound = m_spkLight->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void GlossMapEffect::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    ShaderEffect::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkLight)
    {
        m_spkLight->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* GlossMapEffect::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = ShaderEffect::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkLight)
    {
        pkFound = m_spkLight->GetObjectByID(uiID);
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
void GlossMapEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkLight
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(GlossMapEffect);
}
//----------------------------------------------------------------------------
void GlossMapEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkLight = (Light*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool GlossMapEffect::Register (Stream& rkStream) const
{
    if (!ShaderEffect::Register(rkStream))
    {
        return false;
    }

    if (m_spkLight)
    {
        m_spkLight->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void GlossMapEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // link data
    rkStream.Write(m_spkLight);

    WM4_END_DEBUG_STREAM_SAVE(GlossMapEffect);
}
//----------------------------------------------------------------------------
int GlossMapEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_spkLight);
}
//----------------------------------------------------------------------------
StringTree* GlossMapEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    if (m_spkLight)
    {
        pkTree->Append(m_spkLight->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
