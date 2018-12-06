// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4OPENGLFRAMEBUFFER_H
#define WM4OPENGLFRAMEBUFFER_H

#include "Wm4OpenGLRendererLIB.h"
#include "Wm4OpenGLRenderer.h"
#include "Wm4Main.h"
#include "Wm4FrameBuffer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM OpenGLFrameBuffer : public FrameBuffer
{
    WM4_DECLARE_INITIALIZE;

public:
    OpenGLFrameBuffer (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    virtual ~OpenGLFrameBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void CopyToTexture (bool bFillImage);

protected:
    GLuint m_uiFrameBufferID;
    GLuint m_uiDepthBufferID;
    GLuint m_uiStencilBufferID;
    GLuint m_uiTargetID;
    // TO DO.  What about buffering and multisampling?

    // factory functions
    static FrameBuffer* Create (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    static void Destroy (FrameBuffer* pkBuffer);
};

WM4_REGISTER_INITIALIZE(OpenGLFrameBuffer);

}

#endif
