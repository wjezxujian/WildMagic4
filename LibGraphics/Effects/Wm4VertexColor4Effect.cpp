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
#include "Wm4VertexColor4Effect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,VertexColor4Effect,ShaderEffect);
WM4_IMPLEMENT_STREAM(VertexColor4Effect);
WM4_IMPLEMENT_DEFAULT_STREAM(VertexColor4Effect,ShaderEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(VertexColor4Effect,ShaderEffect);

//----------------------------------------------------------------------------
VertexColor4Effect::VertexColor4Effect ()
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("VertexColor4");
    m_kPShader[0] = WM4_NEW PixelShader("PassThrough4");
}
//----------------------------------------------------------------------------
VertexColor4Effect::~VertexColor4Effect ()
{
}
//----------------------------------------------------------------------------
