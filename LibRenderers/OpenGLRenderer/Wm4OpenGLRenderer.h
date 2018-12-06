// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4OPENGLRENDERER_H
#define WM4OPENGLRENDERER_H

#include "Wm4OpenGLRendererLIB.h"
#include "GTglExtensions.h"
#include "Wm4OpenGLFrameBuffer.h"
#include "Wm4Renderer.h"
#include "Wm4Geometry.h"
#include "Wm4Texture.h"

namespace Wm4
{

class BitmapFont;

class WM4_RENDERER_ITEM OpenGLRenderer : public Renderer
{
public:
    // Run-time type information.
    virtual int GetType () const { return Renderer::OPENGL; }

    // Renderer-specific information for loading shader programs.
    virtual const char* GetExtension () const { return "ogl"; }
    virtual char GetCommentCharacter () const { return '#'; }

    // Abstract base class.  The InitializeState call is made by derived
    // class constructors after an OpenGL context is created.
    virtual ~OpenGLRenderer();
    void InitializeState ();

    virtual void SetBackgroundColor (const ColorRGBA& rkColor);

    // Full window buffer operations.
    virtual void ClearBackBuffer ();
    virtual void ClearZBuffer ();
    virtual void ClearStencilBuffer ();
    virtual void ClearBuffers ();
    virtual void DisplayBackBuffer () = 0;

    // Clear the buffer in the specified subwindow.
    virtual void ClearBackBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight);
    virtual void ClearZBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight);
    virtual void ClearStencilBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight);
    virtual void ClearBuffers (int iXPos, int iYPos, int iWidth,
        int iHeight);

    // Specialized drawing functions.
    virtual bool SelectFont (int iFontID);
    virtual void UnloadFont (int iFontID);
    virtual void Draw (int iX, int iY, const ColorRGBA& rkColor,
        const char* acText);
    virtual void Draw (const unsigned char* aucBuffer);

    // Enable or disable which color channels will be written to the color
    // buffer.
    virtual void SetColorMask (bool bAllowRed, bool bAllowGreen,
        bool bAllowBlue, bool bAllowAlpha);

    // Include additional clip planes.  The input plane must be in model
    // coordinates.  It is transformed internally to camera coordinates to
    // support clipping in clip space.
    virtual void EnableUserClipPlane (int i, const Plane3f& rkPlane);
    virtual void DisableUserClipPlane (int i);

protected:
    // construction
    OpenGLRenderer (FrameBuffer::FormatType eFormat,
        FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight);

    // camera updates
    friend class OpenGLFrameBuffer;
    virtual void OnViewportChange ();
    virtual void OnDepthRangeChange ();

    // global render state management
    virtual void SetAlphaState (AlphaState* pkState);
    virtual void SetCullState (CullState* pkState);
    virtual void SetPolygonOffsetState (PolygonOffsetState* pkState);
    virtual void SetStencilState (StencilState* pkState);
    virtual void SetWireframeState (WireframeState* pkState);
    virtual void SetZBufferState (ZBufferState* pkState);

    // The entry point to drawing a geometry object.
    virtual void DrawElements ();

    // Resource loading and releasing (to/from video memory).
    virtual void OnLoadVProgram (ResourceIdentifier*& rpkID,
        VertexProgram* pkVProgram);
    virtual void OnReleaseVProgram (ResourceIdentifier* pkID);
    virtual void OnLoadPProgram (ResourceIdentifier*& rpkID,
        PixelProgram* pkPProgram);
    virtual void OnReleasePProgram (ResourceIdentifier* pkID);
    virtual void OnLoadTexture (ResourceIdentifier*& rpkID,
        Texture* pkTexture);
    virtual void OnReleaseTexture (ResourceIdentifier* pkID);
    virtual void OnLoadVBuffer (ResourceIdentifier*& rkpID,
        const Attributes& rkIAttr, const Attributes& rkOAttr,
        VertexBuffer* pkVBuffer);
    virtual void OnReleaseVBuffer (ResourceIdentifier* pkID);
    virtual void OnLoadIBuffer (ResourceIdentifier*& rpkID,
        IndexBuffer* pkIBuffer);
    virtual void OnReleaseIBuffer (ResourceIdentifier* pkID);

    // Resource enabling and disabling.
    virtual void SetVProgramConstant (int eCType, int iBaseRegister,
        int iRegisterQuantity, float* afData);
    virtual void SetPProgramConstant (int eCType, int iBaseRegister,
        int iRegisterQuantity, float* afData);
    virtual void OnEnableVProgram (ResourceIdentifier* pkID);
    virtual void OnDisableVProgram (ResourceIdentifier* pkID);
    virtual void OnEnablePProgram (ResourceIdentifier* pkID);
    virtual void OnDisablePProgram (ResourceIdentifier* pkID);
    virtual void OnEnableTexture (ResourceIdentifier* pkID);
    virtual void OnDisableTexture (ResourceIdentifier* pkID);
    virtual void OnEnableVBuffer (ResourceIdentifier* pkID);
    virtual void OnDisableVBuffer (ResourceIdentifier* pkID);
    virtual void OnEnableIBuffer (ResourceIdentifier* pkID);
    virtual void OnDisableIBuffer (ResourceIdentifier* pkID);

    // text drawing
    void DrawCharacter (const BitmapFont& rkFont, char cChar);

    // Display list base indices for fonts/characters.
    class DisplayListInfo
    {
    public:
        int Quantity;  // number of display lists, input to glGenLists
        int Start;     // start index, output from glGenLists
        int Base;      // base index for glListBase
    };
    std::vector<DisplayListInfo> m_kDLInfo;

    // Mappings from Wild Magic constants to OpenGL enumerations.
    static GLenum ms_aeObjectType[Geometry::GT_MAX_QUANTITY];
    static GLenum ms_aeAlphaSrcBlend[AlphaState::SBF_QUANTITY];
    static GLenum ms_aeAlphaDstBlend[AlphaState::DBF_QUANTITY];
    static GLenum ms_aeAlphaTest[AlphaState::TF_QUANTITY];
    static GLenum ms_aeFrontFace[CullState::FT_QUANTITY];
    static GLenum ms_aeCullFace[CullState::CT_QUANTITY];
    static GLenum ms_aeStencilCompare[StencilState::CF_QUANTITY];
    static GLenum ms_aeStencilOperation[StencilState::OT_QUANTITY];
    static GLenum ms_aeZBufferCompare[ZBufferState::CF_QUANTITY];
    static GLenum ms_aeTextureMipmap[Texture::MAX_FILTER_TYPES];
    static GLenum ms_aeDepthCompare[Texture::DC_QUANTITY];
    static GLenum ms_aeWrapMode[Texture::MAX_WRAP_TYPES];
    static GLenum ms_aeImageComponents[Image::IT_QUANTITY];
    static GLenum ms_aeImageFormats[Image::IT_QUANTITY];
    static GLenum ms_aeImageTypes[Image::IT_QUANTITY];
    static GLenum ms_aeSamplerTypes[SamplerInformation::MAX_SAMPLER_TYPES];
};

}

#endif
