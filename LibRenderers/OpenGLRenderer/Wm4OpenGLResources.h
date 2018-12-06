// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4OPENGLRESOURCES_H
#define WM4OPENGLRESOURCES_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_RENDERER_ITEM VProgramID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM PProgramID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM TextureID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
    Texture* TextureObject;
};

class WM4_RENDERER_ITEM VBufferID : public ResourceIdentifier
{
public:
    Attributes IAttr;  // For matching inputs when doing multipass.
    Attributes OAttr;
    unsigned int ID;   // OpenGL's identifier for the resource.
};

class WM4_RENDERER_ITEM IBufferID : public ResourceIdentifier
{
public:
    unsigned int ID;   // OpenGL's identifier for the resource.
};

}

#endif
