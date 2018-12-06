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
#include "Wm4CullState.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,CullState,GlobalState);
WM4_IMPLEMENT_STREAM(CullState);
WM4_IMPLEMENT_DEFAULT_NAME_ID(CullState,GlobalState);
WM4_IMPLEMENT_INITIALIZE(CullState);
WM4_IMPLEMENT_TERMINATE(CullState);

const char* CullState::ms_aacFrontMode[FT_QUANTITY] =
{
    "FT_CCW",
    "FT_CW"
};

const char* CullState::ms_aacCullMode[CT_QUANTITY] =
{
    "CT_FRONT",
    "CT_BACK"
};

//----------------------------------------------------------------------------
void CullState::Initialize ()
{
    Default[CULL] = WM4_NEW CullState;
}
//----------------------------------------------------------------------------
void CullState::Terminate ()
{
    Default[CULL] = 0;
}
//----------------------------------------------------------------------------
CullState::CullState ()
{
    Enabled = true;
    FrontFace = FT_CCW;
    CullFace = CT_BACK;
}
//----------------------------------------------------------------------------
CullState::~CullState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void CullState::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    GlobalState::Load(rkStream,pkLink);

    // native data
    int iTmp;
    rkStream.Read(Enabled);
    rkStream.Read(iTmp);
    FrontFace = (FrontMode)iTmp;
    rkStream.Read(iTmp);
    CullFace = (CullMode)iTmp;

    WM4_END_DEBUG_STREAM_LOAD(CullState);
}
//----------------------------------------------------------------------------
void CullState::Link (Stream& rkStream, Stream::Link* pkLink)
{
    GlobalState::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool CullState::Register (Stream& rkStream) const
{
    return GlobalState::Register(rkStream);
}
//----------------------------------------------------------------------------
void CullState::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    GlobalState::Save(rkStream);

    // native data
    rkStream.Write(Enabled);
    rkStream.Write((int)FrontFace);
    rkStream.Write((int)CullFace);

    WM4_END_DEBUG_STREAM_SAVE(CullState);
}
//----------------------------------------------------------------------------
int CullState::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return GlobalState::GetDiskUsed(rkVersion) +
        sizeof(char) + // Enabled
        sizeof(int) + // FrontFace
        sizeof(int); // CullFace
}
//----------------------------------------------------------------------------
StringTree* CullState::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("enabled =",Enabled));
    pkTree->Append(Format("front face = ",ms_aacFrontMode[FrontFace]));
    pkTree->Append(Format("cull face = ",ms_aacCullMode[CullFace]));

    // children
    pkTree->Append(GlobalState::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
