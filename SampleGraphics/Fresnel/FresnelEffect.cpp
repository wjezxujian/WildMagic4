// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "FresnelEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,FresnelEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(FresnelEffect);
WM4_IMPLEMENT_DEFAULT_STREAM(FresnelEffect,ShaderEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(FresnelEffect,ShaderEffect);

//----------------------------------------------------------------------------
FresnelEffect::FresnelEffect ()
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Fresnel");
    m_kPShader[0] = WM4_NEW PixelShader("Fresnel");
}
//----------------------------------------------------------------------------
FresnelEffect::~FresnelEffect ()
{
}
//----------------------------------------------------------------------------
