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
#include "Wm4WireframeState.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,WireframeState,GlobalState);
WM4_IMPLEMENT_STREAM(WireframeState);
WM4_IMPLEMENT_DEFAULT_NAME_ID(WireframeState,GlobalState);
WM4_IMPLEMENT_INITIALIZE(WireframeState);
WM4_IMPLEMENT_TERMINATE(WireframeState);

//----------------------------------------------------------------------------
void WireframeState::Initialize ()
{
    Default[WIREFRAME] = WM4_NEW WireframeState;
}
//----------------------------------------------------------------------------
void WireframeState::Terminate ()
{
    Default[WIREFRAME] = 0;
}
//----------------------------------------------------------------------------
WireframeState::WireframeState ()
{
    Enabled = false;
}
//----------------------------------------------------------------------------
WireframeState::~WireframeState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void WireframeState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Enabled);

    WM4_END_DEBUG_STREAM_LOAD(WireframeState);
}
//----------------------------------------------------------------------------
void WireframeState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool WireframeState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void WireframeState::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Enabled);

    WM4_END_DEBUG_STREAM_SAVE(WireframeState);
}
//----------------------------------------------------------------------------
int WireframeState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(char);  // Enabled
}
//----------------------------------------------------------------------------
StringTree* WireframeState::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("enabled =",Enabled));

    // children
    pkTree->Append(GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
