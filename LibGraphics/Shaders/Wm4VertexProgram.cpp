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
#include "Wm4VertexProgram.h"
#include "Wm4VertexProgramCatalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,VertexProgram,Program);
WM4_IMPLEMENT_STREAM(VertexProgram);
WM4_IMPLEMENT_DEFAULT_STREAM(VertexProgram,Program);
WM4_IMPLEMENT_DEFAULT_NAME_ID(VertexProgram,Program);

//----------------------------------------------------------------------------
VertexProgram* VertexProgram::Load (const std::string& rkProgramName,
    const std::string& rkRendererType, char cCommentPrefix)
{
    std::string kFilename = std::string("v_") + rkProgramName +
        std::string(".") + rkRendererType + std::string(".wmsp");

    VertexProgram* pkProgram = WM4_NEW VertexProgram;
    bool bLoaded = Program::Load(kFilename,cCommentPrefix,pkProgram);
    if (!bLoaded)
    {
        WM4_DELETE pkProgram;
        return 0;
    }

    pkProgram->SetName(rkProgramName.c_str());
    VertexProgramCatalog::GetActive()->Insert(pkProgram);
    return pkProgram;
}
//----------------------------------------------------------------------------
VertexProgram::VertexProgram ()
{
}
//----------------------------------------------------------------------------
VertexProgram::~VertexProgram ()
{
    VertexProgramCatalog::GetActive()->Remove(this);
}
//----------------------------------------------------------------------------
