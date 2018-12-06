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
#include "Wm4MaterialState.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,MaterialState,GlobalState);
WM4_IMPLEMENT_STREAM(MaterialState);
WM4_IMPLEMENT_DEFAULT_NAME_ID(MaterialState,GlobalState);
WM4_IMPLEMENT_INITIALIZE(MaterialState);
WM4_IMPLEMENT_TERMINATE(MaterialState);

//----------------------------------------------------------------------------
void MaterialState::Initialize ()
{
    Default[MATERIAL] = WM4_NEW MaterialState;
}
//----------------------------------------------------------------------------
void MaterialState::Terminate ()
{
    Default[MATERIAL] = 0;
}
//----------------------------------------------------------------------------
MaterialState::MaterialState ()
    :
    Emissive(0.0f,0.0f,0.0f),
    Ambient(0.2f,0.2f,0.2f),
    Diffuse(0.8f,0.8f,0.8f),
    Specular(0.0f,0.0f,0.0f)
{
    Alpha = 1.0f;
    Shininess = 1.0f;
}
//----------------------------------------------------------------------------
MaterialState::~MaterialState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void MaterialState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Emissive);
    rkStream.Read(Ambient);
    rkStream.Read(Diffuse);
    rkStream.Read(Specular);
    rkStream.Read(Alpha);
    rkStream.Read(Shininess);

    WM4_END_DEBUG_STREAM_LOAD(MaterialState);
}
//----------------------------------------------------------------------------
void MaterialState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool MaterialState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void MaterialState::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Emissive);
    rkStream.Write(Ambient);
    rkStream.Write(Diffuse);
    rkStream.Write(Specular);
    rkStream.Write(Alpha);
    rkStream.Write(Shininess);

    WM4_END_DEBUG_STREAM_SAVE(MaterialState);
}
//----------------------------------------------------------------------------
int MaterialState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) + sizeof(Emissive) +
        sizeof(Ambient) + sizeof(Diffuse) + sizeof(Specular) + sizeof(Alpha) +
        sizeof(Shininess);
}
//----------------------------------------------------------------------------
StringTree* MaterialState::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("emissive =",Emissive));
    pkTree->Append(Format("ambient =",Ambient));
    pkTree->Append(Format("diffuse =",Diffuse));
    pkTree->Append(Format("alpha =",Alpha));
    pkTree->Append(Format("shininess =",Shininess));

    // children
    pkTree->Append(GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
