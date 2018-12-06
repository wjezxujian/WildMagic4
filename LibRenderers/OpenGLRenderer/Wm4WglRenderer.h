// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4WGLRENDERER_H
#define WM4WGLRENDERER_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4OpenGLRenderer.h"
#include "GTwglExtensions.h"

namespace Wm4
{

class WM4_RENDERER_ITEM WglRenderer : public OpenGLRenderer
{
public:
    // Construction and destruction.  The first time the constructor is
    // called by the application layer, the input pixel format is ignored.
    // If multisampling is requested and supported, the renderer and window
    // must be destroyed, and then recreated with a pixel format for
    // multisampling.  See Wm4WglApplication.cpp for the procedure for doing
    // this.
    WglRenderer (HWND hWnd, FrameBuffer::FormatType eFormat,
        FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight, int iPixelFormat = 0);

    virtual ~WglRenderer ();

    virtual void ToggleFullscreen ();
    virtual void DisplayBackBuffer ();
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic);

    // window parameters
    HWND GetWindow () { return m_hWnd; }
    HDC GetDC () { return m_hWindowDC; }
    HGLRC GetRC () { return m_hWindowRC; }

protected:
    // window parameters
    HWND m_hWnd;
    HDC m_hWindowDC;
    HGLRC m_hWindowRC;
    HGDIOBJ m_hOldFont;

    // fullscreen/window support
    int m_iSaveWidth, m_iSaveHeight;
};

}

#endif
