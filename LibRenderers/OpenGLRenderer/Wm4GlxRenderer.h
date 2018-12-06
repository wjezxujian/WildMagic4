// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GLXRENDERER_H
#define WM4GLXRENDERER_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4OpenGLRenderer.h"
#include "GTglxExtensions.h"

namespace Wm4
{

class WM4_RENDERER_ITEM GlxRenderer : public OpenGLRenderer
{
public:
    // construction and destruction
    GlxRenderer (Display* pkDisplay, FrameBuffer::FormatType eFormat,
        FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling, int iWidth,
        int iHeight);

    virtual void ToggleFullscreen ();
    virtual void DisplayBackBuffer ();
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic) { return -1; }
    virtual void UnloadFont (int iFontID) { /**/ }

    Display* GetDisplay () { return m_pkDisplay; }
    XVisualInfo* GetVisual () { return m_pkVisual; }
    Window GetWindow () { return m_ulWindow; }
    GLXContext GetContext () { return m_kContext; }

private:
    // window parameters
    Display* m_pkDisplay;
    XVisualInfo* m_pkVisual;
    Window m_ulWindow;
    GLXContext m_kContext;

    // fullscreen/window support
    int m_iSaveWidth, m_iSaveHeight;

    bool m_bIsConstructed;

// internal use
public:
    // For the application layer and pbuffers.
    void FinishConstruction (Window ulWindow);
    bool IsConstructed () const { return m_bIsConstructed; }
};

}

#endif
