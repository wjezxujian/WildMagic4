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
#include "Wm4PixelProgram.h"
#include "Wm4PixelProgramCatalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,PixelProgram,Program);
WM4_IMPLEMENT_STREAM(PixelProgram);
WM4_IMPLEMENT_DEFAULT_STREAM(PixelProgram,Program);
WM4_IMPLEMENT_DEFAULT_NAME_ID(PixelProgram,Program);

//----------------------------------------------------------------------------
PixelProgram* PixelProgram::Load (const std::string& rkProgramName,
    const std::string& rkRendererType, char cCommentPrefix)
{
    std::string kFilename = std::string("p_") + rkProgramName +
        std::string(".") + rkRendererType + std::string(".wmsp");

    PixelProgram* pkProgram = WM4_NEW PixelProgram;
    bool bLoaded = Program::Load(kFilename,cCommentPrefix,pkProgram);
    if (!bLoaded)
    {
        WM4_DELETE pkProgram;
        return 0;
    }

    pkProgram->SetName(rkProgramName.c_str());
    PixelProgramCatalog::GetActive()->Insert(pkProgram);
    return pkProgram;
}
//----------------------------------------------------------------------------
PixelProgram::PixelProgram ()
{
}
//----------------------------------------------------------------------------
PixelProgram::~PixelProgram ()
{
    PixelProgramCatalog::GetActive()->Remove(this);
}
//----------------------------------------------------------------------------
