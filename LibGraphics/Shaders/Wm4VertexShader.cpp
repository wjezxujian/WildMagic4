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
#include "Wm4VertexShader.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,VertexShader,Shader);
WM4_IMPLEMENT_STREAM(VertexShader);
WM4_IMPLEMENT_DEFAULT_STREAM(VertexShader,Shader);
WM4_IMPLEMENT_DEFAULT_NAME_ID(VertexShader,Shader);

//----------------------------------------------------------------------------
VertexShader::VertexShader (const std::string& rkShaderName)
    :
    Shader(rkShaderName)
{
}
//----------------------------------------------------------------------------
VertexShader::VertexShader ()
{
}
//----------------------------------------------------------------------------
VertexShader::~VertexShader ()
{
}
//----------------------------------------------------------------------------
VertexProgram* VertexShader::GetProgram () const
{
    return StaticCast<VertexProgram>(m_spkProgram);
}
//----------------------------------------------------------------------------
