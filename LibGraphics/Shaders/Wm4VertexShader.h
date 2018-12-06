// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VERTEXSHADER_H
#define WM4VERTEXSHADER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Shader.h"
#include "Wm4VertexProgram.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexShader : public Shader
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VertexShader (const std::string& rkShaderName);
    virtual ~VertexShader ();

    VertexProgram* GetProgram () const;

protected:
    VertexShader ();
};

WM4_REGISTER_STREAM(VertexShader);
typedef Pointer<VertexShader> VertexShaderPtr;

}

#endif
