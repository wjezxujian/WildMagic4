// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4OpenGLRendererPCH.h"
#include "Wm4OpenGLRenderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
OpenGLRenderer::OpenGLRenderer (FrameBuffer::FormatType eFormat,
    FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
    FrameBuffer::BufferingType eBuffering,
    FrameBuffer::MultisamplingType eMultisampling, int iWidth, int iHeight)
    :
    Renderer(eFormat,eDepth,eStencil,eBuffering,eMultisampling,iWidth,iHeight)
{
}
//----------------------------------------------------------------------------
OpenGLRenderer::~OpenGLRenderer ()
{
}
//----------------------------------------------------------------------------
void OpenGLRenderer::InitializeState ()
{
    // vertices always exist
    glEnableClientState(GL_VERTEX_ARRAY);

    // colors disabled, current color is WHITE
    glDisableClientState(GL_COLOR_ARRAY);
    glColor4fv((const float*)ColorRGBA::WHITE);

    // normals disabled
    glDisableClientState(GL_NORMAL_ARRAY);

    // Query for capabilities.

    // Get the number of supported texture images for vertex program.
    m_iMaxVShaderImages = 0;
    glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,&m_iMaxVShaderImages);

    // Get the number of supported texture units for pixel programs.
    m_iMaxPShaderImages = 0;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS,&m_iMaxPShaderImages);

    // TO DO.  The OpenGL shading language has separate concepts of "texture
    // image units" and "texture coordinate sets".  The values iMaxTextures
    // and iMaxTCoords can be different.  Replace m_iMaxTextures with
    // m_iMaxTextureImageUnits and add m_iMaxTCoords.  Anytime shader programs
    // are loaded, the number of texture coordinate inputs/outputs and the
    // number of samplers need to be compared with what the hardware can
    // support.
    m_iMaxTCoords = 0;
    glGetIntegerv(GL_MAX_TEXTURE_COORDS,&m_iMaxTCoords);

    // OpenGL supports a primary and a secondary color
    m_iMaxColors = 2;

    // Set up light model.  TO DO:  Do we need the OpenGL calls for a
    // shader-based engine?
    GLint iMaxLights;
    glGetIntegerv(GL_MAX_LIGHTS,&iMaxLights);
    assert(iMaxLights > 0);
    m_iMaxLights = (int)iMaxLights;
    m_aspkLight = WM4_NEW ObjectPtr[m_iMaxLights];
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,(const float*)ColorRGBA::BLACK);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_FALSE);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
    glDisable(GL_LIGHTING);

    // get stencil buffer size
    GLint iBits = 0;
    glGetIntegerv(GL_STENCIL_BITS,&iBits);
    m_iMaxStencilIndices = (iBits > 0 ? (1 << iBits) : 0);

    GLint iMaxUseClipPlanes = 0;
    glGetIntegerv(GL_MAX_CLIP_PLANES,&iMaxUseClipPlanes);
    m_iMaxUserClipPlanes = (int)iMaxUseClipPlanes;

    // Disable drawing of lines as sequences of dashes.
    glDisable(GL_LINE_STIPPLE);

    // Initialize global render state to default settings.
    SetGlobalState(GlobalState::Default);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::SetBackgroundColor (const ColorRGBA& rkColor)
{
    Renderer::SetBackgroundColor(rkColor);
    glClearColor(rkColor[0],rkColor[1],rkColor[2],rkColor[3]);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearBackBuffer ()
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,m_iWidth,m_iHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearZBuffer ()
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,m_iWidth,m_iHeight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearStencilBuffer ()
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,m_iWidth,m_iHeight);
    glStencilMask(~0);
    glClear(GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearBuffers ()
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(0,0,m_iWidth,m_iHeight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glStencilMask(~0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearBackBuffer (int iXPos, int iYPos, int iWidth,
    int iHeight)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(iXPos,iYPos,iWidth,iHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearZBuffer (int iXPos, int iYPos, int iWidth,
    int iHeight)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(iXPos,iYPos,iWidth,iHeight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearStencilBuffer (int iXPos, int iYPos, int iWidth,
    int iHeight)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(iXPos,iYPos,iWidth,iHeight);
    glStencilMask(~0);
    glClear(GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::ClearBuffers (int iXPos, int iYPos, int iWidth,
    int iHeight)
{
    glEnable(GL_SCISSOR_TEST);
    glScissor(iXPos,iYPos,iWidth,iHeight);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glStencilMask(~0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::SetColorMask (bool bAllowRed, bool bAllowGreen,
    bool bAllowBlue, bool bAllowAlpha)
{
    Renderer::SetColorMask(bAllowRed,bAllowGreen,bAllowBlue,bAllowAlpha);

    glColorMask((GLboolean)bAllowRed,(GLboolean)bAllowGreen,
        (GLboolean)bAllowBlue,(GLboolean)bAllowAlpha);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::EnableUserClipPlane (int i, const Plane3f& rkPlane)
{
    GLdouble adPlane[4] =
    {
        (double)rkPlane.Normal.X(),
        (double)rkPlane.Normal.Y(),
        (double)rkPlane.Normal.Z(),
        (double)-rkPlane.Constant
    };
    glClipPlane(GL_CLIP_PLANE0 + i,adPlane);
    glEnable(GL_CLIP_PLANE0 + i);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::DisableUserClipPlane (int i)
{
    glDisable(GL_CLIP_PLANE0 + i);
}
//----------------------------------------------------------------------------
