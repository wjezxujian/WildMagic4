// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DX9RESOURCES_H
#define WM4DX9RESOURCES_H

#include "Wm4Dx9RendererLIB.h"
#include "Wm4Dx9Utility.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    IDirect3DVertexShader9* ID;
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    IDirect3DPixelShader9* ID;
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    IDirect3DBaseTexture9* ID;
    Texture* TextureObject;
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;
    LPDIRECT3DVERTEXBUFFER9 ID;
    int VertexSize;
    DWORD Format;
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    LPDIRECT3DINDEXBUFFER9 ID;
};

}

#endif
