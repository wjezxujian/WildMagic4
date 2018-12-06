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
#include "Wm4PixelShader.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,PixelShader,Shader);
WM4_IMPLEMENT_STREAM(PixelShader);
WM4_IMPLEMENT_DEFAULT_STREAM(PixelShader,Shader);
WM4_IMPLEMENT_DEFAULT_NAME_ID(PixelShader,Shader);

//----------------------------------------------------------------------------
PixelShader::PixelShader (const std::string& rkShaderName)
    :
    Shader(rkShaderName)
{
}
//----------------------------------------------------------------------------
PixelShader::PixelShader ()
{
}
//----------------------------------------------------------------------------
PixelShader::~PixelShader ()
{
}
//----------------------------------------------------------------------------
PixelProgram* PixelShader::GetProgram () const
{
    return StaticCast<PixelProgram>(m_spkProgram);
}
//----------------------------------------------------------------------------
