// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SHADEREFFECT_H
#define WM4SHADEREFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Effect.h"
#include "Wm4VertexShader.h"
#include "Wm4PixelShader.h"

namespace Wm4
{

class Renderer;

class WM4_GRAPHICS_ITEM ShaderEffect : public Effect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    ShaderEffect (int iPassQuantity);
    virtual ~ShaderEffect ();

    // The shader effect is a manager of the vertex and pixel shaders.  It
    // reimplements the user-relevant interfaces for the managed objects as a
    // convenience to avoid long expressions involving pointer dereferencing.

    // The number of vertex/pixel shader pairs.  The Set* call reallocates the
    // vertex shader, pixel shader, and alpha state arrays.
    void SetPassQuantity (int iPassQuantity);
    int GetPassQuantity () const;

    // Blending modes for multipass effects.  Mode i specifies how the pixel
    // colors from pass i-1 and pass i are blended.  For a single effect
    // attached to a Geometry object, blending mode 0 is irrelevant in that
    // the source mode is equivalent to SBF_ONE and the destination mode is
    // equivalent to SDF_ZERO; that is, the frame buffer values are replaced
    // with the pixel values from the shader.  If multiple effects are
    // attached to a Geometry object, blending mode 0 specifies how the
    // current effect is blended with the frame buffer.
    AlphaState* GetBlending (int iPass);

    // Set any global state needed by the pass and restore it later.  The
    // base class enables and disables blending as needed for multipass
    // and multieffect drawing.
    virtual void SetGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);
    virtual void RestoreGlobalState (int iPass, Renderer* pkRenderer,
        bool bPrimaryEffect);

    // vertex shader interfaces
    void SetVShader (int iPass, VertexShader* pkVShader);
    VertexShader* GetVShader (int iPass);
    VertexProgram* GetVProgram (int iPass);
    const std::string& GetVShaderName (int iPass) const;
    int GetVConstantQuantity (int iPass) const;
    UserConstant* GetVConstant (int iPass, int i);
    UserConstant* GetVConstant (int iPass, const std::string& rkName);
    int GetVTextureQuantity (int iPass) const;
    Texture* GetVTexture (int iPass, int i);
    Texture* GetVTexture (int iPass, const std::string& rkName);
    void SetVImageName (int iPass, int i, const std::string& rkName);
    const std::string& GetVImageName (int iPass, int i) const;

    // pixel shader interfaces
    void SetPShader (int iPass, PixelShader* pkPShader);
    PixelShader* GetPShader (int iPass);
    PixelProgram* GetPProgram (int iPass);
    const std::string& GetPShaderName (int iPass) const;
    int GetPConstantQuantity (int iPass) const;
    UserConstant* GetPConstant (int iPass, int i);
    UserConstant* GetPConstant (int iPass, const std::string& rkName);
    int GetPTextureQuantity (int iPass) const;
    Texture* GetPTexture (int iPass, int i);
    Texture* GetPTexture (int iPass, const std::string& rkName);
    void SetPImageName (int iPass, int i, const std::string& rkName);
    const std::string& GetPImageName (int iPass, int i) const;

    // The functions are called by Renderer::LoadResources and
    // Renderer::ReleaseResources for Geometry and Effect objects.
    virtual void LoadResources (Renderer* pkRenderer, Geometry* pkGeometry);
    virtual void ReleaseResources (Renderer* pkRenderer,
        Geometry* pkGeometry);

protected:
    // streaming support
    ShaderEffect ();

    void SetDefaultAlphaState ();

    int m_iPassQuantity;
    std::vector<VertexShaderPtr> m_kVShader;
    std::vector<PixelShaderPtr> m_kPShader;
    std::vector<AlphaStatePtr> m_kAlphaState;

// internal use
public:
    // The renderers call this to load the shader programs from disk.  If
    // a program load fails, the shader object is replaced by the default
    // shader object.  Conditions for failure:
    // (1) The shader program file is not found.
    // (2) The output of the vertex program and the input of the pixel
    //     program are not compatible.
    // (3) The shader program requires more color parameters than supported
    //     by the renderer.
    // (4) The pixel program requires more texture iamge units than supported
    //     by the renderer.
    // (5) The shader program requires more texture coordinate sets than
    //     supported by the renderer.
    void LoadPrograms (int iPass, int iMaxColors, int iMaxTCoords,
        int iMaxVShaderImages, int iMaxPShaderImages);

    void ReleasePrograms (int iPass);

    // This function is called in LoadPrograms once the shader programs are
    // created.  It gives the ShaderEffect-derived classes a chance to do
    // any additional work to hook up the effect with the low-level objects.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // This function is called in ReleasePrograms once the shader programs
    // are ready to be released.  It gives the ShaderEffect-derived classes
    // a chance to do any additional work to unhook the low-level objects
    // from the effect.
    virtual void OnReleasePrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);
};

WM4_REGISTER_STREAM(ShaderEffect);
typedef Pointer<ShaderEffect> ShaderEffectPtr;

}

#endif
