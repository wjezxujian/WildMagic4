// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RENDERER_H
#define WM4RENDERER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4FrameBuffer.h"
#include "Wm4AlphaState.h"
#include "Wm4CullState.h"
#include "Wm4MaterialState.h"
#include "Wm4PolygonOffsetState.h"
#include "Wm4StencilState.h"
#include "Wm4WireframeState.h"
#include "Wm4ZBufferState.h"
#include "Wm4ColorRGB.h"
#include "Wm4ColorRGBA.h"
#include "Wm4Matrix4.h"
#include "Wm4RendererConstant.h"

namespace Wm4
{

class Attributes;
class Bindable;
class Camera;
class Effect;
class Geometry;
class IndexBuffer;
class Light;
class PixelProgram;
class ResourceIdentifier;
class ShaderEffect;
class Spatial;
class Texture;
class VertexBuffer;
class VertexProgram;
class VisibleObject;
class VisibleSet;

class WM4_GRAPHICS_ITEM Renderer
{
public:
    // Abstract API for renderers.  Each graphics API must implement this
    // layer.
    virtual ~Renderer ();

    // Run-time type information.
    enum
    {
        OPENGL,
        DIRECTX,
        SOFTWARE,
        MAX_RENDERER_TYPES
    };
    virtual int GetType () const = 0;

    // Renderer-specific information for loading shader programs.
    virtual const char* GetExtension () const = 0;
    virtual char GetCommentCharacter () const = 0;

    // camera access and support
    void SetCamera (Camera* pkCamera);
    Camera* GetCamera () const;

    // frame buffer parameters
    FrameBuffer::FormatType GetFormatType () const;
    FrameBuffer::DepthType GetDepthType () const;
    FrameBuffer::StencilType GetStencilType () const;
    FrameBuffer::BufferingType GetBufferingType () const;
    FrameBuffer::MultisamplingType GetMultisamplingType () const;

    // window parameters
    int GetWidth () const;
    int GetHeight () const;
    virtual void Resize (int iWidth, int iHeight);
    virtual void ToggleFullscreen ();

    // background color access
    virtual void SetBackgroundColor (const ColorRGBA& rkColor);
    const ColorRGBA& GetBackgroundColor () const;

    // pre- and postdraw semantics
    virtual bool BeginScene ();
    virtual void EndScene ();

    // full window buffer operations
    virtual void ClearBackBuffer () = 0;
    virtual void ClearZBuffer () = 0;
    virtual void ClearStencilBuffer () = 0;
    virtual void ClearBuffers () = 0;
    virtual void DisplayBackBuffer () = 0;

    // clear the buffer in the specified subwindow
    virtual void ClearBackBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight) = 0;
    virtual void ClearZBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight) = 0;
    virtual void ClearStencilBuffer (int iXPos, int iYPos, int iWidth,
        int iHeight) = 0;
    virtual void ClearBuffers (int iXPos, int iYPos, int iWidth,
        int iHeight) = 0;

    // object drawing
    void DrawScene (VisibleSet& rkVisibleSet);
    void Draw (Geometry* pkGeometry);

    // text drawing
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic) = 0;
    virtual void UnloadFont (int iFontID) = 0;
    virtual bool SelectFont (int iFontID) = 0;
    virtual void Draw (int iX, int iY, const ColorRGBA& rkColor,
        const char* acText) = 0;

    // 2D drawing
    virtual void Draw (const unsigned char* aucBuffer) = 0;

    // Resource limits.
    int GetMaxLights () const;
    int GetMaxColors () const;
    int GetMaxTCoords () const;
    int GetMaxVShaderImages () const;
    int GetMaxPShaderImages () const;
    int GetMaxStencilIndices () const;
    int GetMaxUserClipPlanes () const;

    // Global render state management.
    virtual void SetAlphaState (AlphaState* pkState);
    virtual void SetCullState (CullState* pkState);
    virtual void SetMaterialState (MaterialState* pkState);
    virtual void SetPolygonOffsetState (PolygonOffsetState* pkState);
    virtual void SetStencilState (StencilState* pkState);
    virtual void SetWireframeState (WireframeState* pkState);
    virtual void SetZBufferState (ZBufferState* pkState);
    AlphaState* GetAlphaState ();
    CullState* GetCullState ();
    MaterialState* GetMaterialState ();
    PolygonOffsetState* GetPolygonOffsetState ();
    StencilState* GetStencilState ();
    WireframeState* GetWireframeState ();
    ZBufferState* GetZBufferState ();
    void SetReverseCullFace (bool bReverseCullFace);
    bool GetReverseCullFace () const;

    // Function pointer types for binding and unbinding resources.
    typedef void (Renderer::*ReleaseFunction)(Bindable*);

    // Resource loading and releasing.
    void LoadAllResources (Spatial* pkScene);
    void ReleaseAllResources (Spatial* pkScene);
    void LoadResources (Geometry* pkGeometry);
    void ReleaseResources (Geometry* pkGeometry);
    void LoadResources (Effect* pkEffect);
    void ReleaseResources (Effect* pkEffect);
    void LoadVProgram (VertexProgram* pkVProgram);
    void ReleaseVProgram (Bindable* pkVProgram);
    void LoadPProgram (PixelProgram* pkPProgram);
    void ReleasePProgram (Bindable* pkPProgram);
    void LoadTexture (Texture* pkTexture);
    void ReleaseTexture (Bindable* pkTexture);
    void LoadVBuffer (const Attributes& rkIAttr, const Attributes& rkOAttr,
        VertexBuffer* pkVBuffer);
    void ReleaseVBuffer (Bindable* pkVBuffer);
    void LoadIBuffer (IndexBuffer* pkIBuffer);
    void ReleaseIBuffer (Bindable* pkIBuffer);

    // Resource enabling and disabling.
    enum  // ConstantType
    {
        CT_RENDERER,
        CT_NUMERICAL,
        CT_USER
    };
    virtual void SetVProgramConstant (int eCType, int iBaseRegister,
        int iRegisterQuantity, float* afData) = 0;
    virtual void SetPProgramConstant (int eCType, int iBaseRegister,
        int iRegisterQuantity, float* afData) = 0;

    void EnableVProgram (VertexProgram* pkVProgram);
    void DisableVProgram (VertexProgram* pkVProgram);
    void EnablePProgram (PixelProgram* pkPProgram);
    void DisablePProgram (PixelProgram* pkPProgram);
    void EnableTexture (Texture* pkTexture);
    void DisableTexture (Texture* pkTexture);
    ResourceIdentifier* EnableVBuffer (const Attributes& rkIAttr,
        const Attributes& rkOAttr);
    void DisableVBuffer (ResourceIdentifier* pkID);
    void EnableIBuffer ();
    void DisableIBuffer ();

    // For use by effects with lights.
    void SetLight (int i, Light* pkLight);
    Light* GetLight (int i);

    // For use by effects with projectors.
    void SetProjector (Camera* pkProjector);
    Camera* GetProjector ();

    // Enable or disable which color channels will be written to the color
    // buffer.
    virtual void SetColorMask (bool bAllowRed, bool bAllowGreen,
        bool bAllowBlue, bool bAllowAlpha);
    virtual void GetColorMask (bool& rbAllowRed, bool& rbAllowGreen,
        bool& rbAllowBlue, bool& rbAllowAlpha);

    // Include additional clip planes.  The input plane must be in model
    // coordinates.  It is transformed internally to camera coordinates to
    // support clipping in clip space.
    virtual void EnableUserClipPlane (int i, const Plane3f& rkPlane) = 0;
    virtual void DisableUserClipPlane (int i) = 0;

    // The input transformation is applied to world-space vertices before
    // the view matrix is applied.
    void SetPostWorldTransformation (const Matrix4f& rkMatrix);
    void RestorePostWorldTransformation ();

protected:
    // abstract base class
    Renderer (FrameBuffer::FormatType eFormat, FrameBuffer::DepthType eDepth,
        FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight);

    // Support for camera access and transformation setting.
    friend class Camera;
    void OnFrameChange ();
    void OnFrustumChange ();
    virtual void OnViewportChange () = 0;
    virtual void OnDepthRangeChange () = 0;

    // global render state management
    void SetGlobalState (GlobalStatePtr aspkState[]);
    void RestoreGlobalState (GlobalStatePtr aspkState[]);

    // Set or restore the model-to-world transformation.
    void SetWorldTransformation ();
    void RestoreWorldTransformation ();

    // The main entry point to drawing in the derived-class renderers.
    virtual void DrawElements () = 0;

    // Resource loading and releasing (to/from video memory).
    virtual void OnLoadVProgram (ResourceIdentifier*& rpkID,
        VertexProgram* pkVProgram) = 0;
    virtual void OnReleaseVProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnLoadPProgram (ResourceIdentifier*& rpkID,
        PixelProgram* pkPProgram) = 0;
    virtual void OnReleasePProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnLoadTexture (ResourceIdentifier*& rpkID,
        Texture* pkTexture) = 0;
    virtual void OnReleaseTexture (ResourceIdentifier* pkID) = 0;
    virtual void OnLoadVBuffer (ResourceIdentifier*& rkpID,
        const Attributes& rkIAttr, const Attributes& rkOAttr,
        VertexBuffer* pkVBuffer) = 0;
    virtual void OnReleaseVBuffer (ResourceIdentifier* pkID) = 0;
    virtual void OnLoadIBuffer (ResourceIdentifier*& rpkID,
        IndexBuffer* pkIBuffer) = 0;
    virtual void OnReleaseIBuffer (ResourceIdentifier* pkID) = 0;

    virtual void OnEnableVProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnDisableVProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnEnablePProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnDisablePProgram (ResourceIdentifier* pkID) = 0;
    virtual void OnEnableTexture (ResourceIdentifier* pkID) = 0;
    virtual void OnDisableTexture (ResourceIdentifier* pkID) = 0;
    virtual void OnEnableVBuffer (ResourceIdentifier* pkID) = 0;
    virtual void OnDisableVBuffer (ResourceIdentifier* pkID) = 0;
    virtual void OnEnableIBuffer (ResourceIdentifier* pkID) = 0;
    virtual void OnDisableIBuffer (ResourceIdentifier* pkID) = 0;

    // The operations are
    //   0 = matrix
    //   1 = transpose of matrix
    //   2 = inverse of matrix
    //   3 = inverse-transpose of matrix
    void GetTransform (const Matrix4f& rkMat, int iOperation, float* afData);
    void SetConstantWMatrix (int iOperation, float* afData);
    void SetConstantVMatrix (int iOperation, float* afData);
    void SetConstantPMatrix (int iOperation, float* afData);
    void SetConstantWVMatrix (int iOperation, float* afData);
    void SetConstantVPMatrix (int iOperation, float* afData);
    void SetConstantWVPMatrix (int iOperation, float* afData);

    // These functions do not use the option parameter, but the parameter is
    // included to allow for a class-static array of function pointers to
    // handle all shader constants.
    void SetConstantMaterialEmissive (int, float* afData);
    void SetConstantMaterialAmbient (int, float* afData);
    void SetConstantMaterialDiffuse (int, float* afData);
    void SetConstantMaterialSpecular (int, float* afData);
    void SetConstantCameraModelPosition (int, float* afData);
    void SetConstantCameraModelDirection (int, float* afData);
    void SetConstantCameraModelUp (int, float* afData);
    void SetConstantCameraModelRight (int, float* afData);
    void SetConstantCameraWorldPosition (int, float* afData);
    void SetConstantCameraWorldDirection (int, float* afData);
    void SetConstantCameraWorldUp (int, float* afData);
    void SetConstantCameraWorldRight (int, float* afData);
    void SetConstantProjectorModelPosition (int, float* afData);
    void SetConstantProjectorModelDirection (int, float* afData);
    void SetConstantProjectorModelUp (int, float* afData);
    void SetConstantProjectorModelRight (int, float* afData);
    void SetConstantProjectorWorldPosition (int, float* afData);
    void SetConstantProjectorWorldDirection (int, float* afData);
    void SetConstantProjectorWorldUp (int, float* afData);
    void SetConstantProjectorWorldRight (int, float* afData);
    void SetConstantProjectorMatrix (int, float* afData);

    // These functions set the light state.  The index iLight is between 0
    // and 7 (eight lights are currently supported).
    void SetConstantLightModelPosition (int iLight, float* afData);
    void SetConstantLightModelDirection (int iLight, float* afData);
    void SetConstantLightWorldPosition (int iLight, float* afData);
    void SetConstantLightWorldDirection (int iLight, float* afData);
    void SetConstantLightAmbient (int iLight, float* afData);
    void SetConstantLightDiffuse (int iLight, float* afData);
    void SetConstantLightSpecular (int iLight, float* afData);
    void SetConstantLightSpotCutoff (int iLight, float* afData);
    void SetConstantLightAttenuation (int iLight, float* afData);

    enum { SC_QUANTITY = 36 };
    typedef void (Renderer::*SetConstantFunction)(int,float*);
    static SetConstantFunction ms_aoSCFunction[SC_QUANTITY];
    void SetRendererConstant (RendererConstant::Type eRCType, float* afData);

    // Object drawing.
    void ApplyEffect (ShaderEffect* pkEffect, bool& rbPrimaryEffect);

// data members
protected:
    // Resource limits.  The values are set by the Renderer-derived objects.
    int m_iMaxLights;
    int m_iMaxColors;
    int m_iMaxTCoords;
    int m_iMaxVShaderImages;
    int m_iMaxPShaderImages;
    int m_iMaxStencilIndices;
    int m_iMaxUserClipPlanes;

    // Parameters for the drawing window and frame buffer.
    FrameBuffer::FormatType m_eFormat;
    FrameBuffer::DepthType m_eDepth;
    FrameBuffer::StencilType m_eStencil;
    FrameBuffer::BufferingType m_eBuffering;
    FrameBuffer::MultisamplingType m_eMultisampling;
    int m_iWidth, m_iHeight;
    ColorRGBA m_kBackgroundColor;
    bool m_bAllowRed, m_bAllowGreen, m_bAllowBlue, m_bAllowAlpha;

    // The camera for establishing the view frustum.
    Camera* m_pkCamera;

    // Global render states.
    GlobalStatePtr m_aspkState[GlobalState::MAX_STATE_TYPE];

    // Light storage for lookup by the shader-constant-setting functions.
    // The Renderer-derived classes must allocate this array during
    // construction, creating m_iMaxLights elements.  The Renderer class
    // deallocates the array during destruction.
    ObjectPtr* m_aspkLight;

    // The projector for various effects such as projected textures and
    // shadow maps.
    Camera* m_pkProjector;

    // Current Geometry object for drawing.
    Geometry* m_pkGeometry;

    // Transformations used in the geometric pipeline.  These matrices are
    // stored to support 1x4 row vectors times 4x4 matrices.
    Matrix4f m_kWorldMatrix, m_kSaveWorldMatrix;
    Matrix4f m_kViewMatrix, m_kSaveViewMatrix;
    Matrix4f m_kProjectionMatrix, m_kSaveProjectionMatrix;

    // Current font for text drawing.
    int m_iFontID;

    // Support for mirror effects (default 'false').
    bool m_bReverseCullFace;

    // Toggle for fullscreen/window mode.
    bool m_bFullscreen;
};

#include "Wm4Renderer.inl"

}

#endif
