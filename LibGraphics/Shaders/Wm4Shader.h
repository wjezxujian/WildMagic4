// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SHADER_H
#define WM4SHADER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Program.h"
#include "Wm4Texture.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Shader : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Abstract base class.
    virtual ~Shader ();

    // The name of the shader object.  The program object has a name that
    // contains the shader name as a substring, but adds additional text
    // as needed (the path to a shader on disk, the identifying information
    // for a procedurally generated shader).
    const std::string& GetShaderName () const;

    // Access to textures and image names.
    void SetTextureQuantity (int iQuantity);
    int GetTextureQuantity () const;
    Texture* GetTexture (int i);
    Texture* GetTexture (const std::string& rkName);
    const Texture* GetTexture (int i) const;
    const Texture* GetTexture (const std::string& rkName) const;
    void SetImageName (int i, const std::string& rkName);
    const std::string& GetImageName (int i) const;

protected:
    // Support for streaming.
    Shader ();

    // The constructor called by the derived classes VertexShader and
    // PixelShader.
    Shader (const std::string& rkShaderName);

protected:
    // The shader name, which contributes to a uniquely identifying string
    // for a shader program.
    std::string m_kShaderName;

    // The shader program, which is dependent on graphics API.
    ProgramPtr m_spkProgram;

    // The user-defined data are specific to each shader object.  The Program
    // object knows only the name, which register to assign the value to, and
    // how many registers to use.  The storage provided here is for the
    // convenience of Shader-derived classes.  However, a derived class may
    // provide alternate storage by calling UserConstant::SetDataSource for
    // each user constant of interest.
    std::vector<float> m_kUserData;

    // The names of images used by an instance of a shader program.  The
    // Texture objects store the actual images and the samplers that are
    // used to sample the images.
    std::vector<std::string> m_kImageNames;
    std::vector<TexturePtr> m_kTextures;

// internal use
public:
    void OnLoadProgram (Program* pkProgram);
    void OnReleaseProgram ();
};

WM4_REGISTER_STREAM(Shader);
typedef Pointer<Shader> ShaderPtr;
#include "Wm4Shader.inl"

}

#endif
