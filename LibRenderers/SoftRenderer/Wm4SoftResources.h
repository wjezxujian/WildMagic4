// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTRESOURCES_H
#define WM4SOFTRESOURCES_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftRenderer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    SoftRenderer::VProgram ID;
    Attributes OAttr;
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    SoftRenderer::PProgram ID;
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;  // For tcoord information during mipmapping.
    int VQuantity;
    float* IVertex;
    int Channels;
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    int IQuantity;
    const int* Index;
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    SoftSampler* ID;
    Texture* TextureObject;
};

}

#endif
