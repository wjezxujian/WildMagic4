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
#include "Wm4OpenGLResources.h"
#include "Wm4OpenGLFrameBuffer.h"
using namespace Wm4;

WM4_IMPLEMENT_INITIALIZE(OpenGLFrameBuffer);

//----------------------------------------------------------------------------
void OpenGLFrameBuffer::Initialize ()
{
    ms_aoCreate[Renderer::OPENGL] = &OpenGLFrameBuffer::Create;
    ms_aoDestroy[Renderer::OPENGL] = &OpenGLFrameBuffer::Destroy;
}
//----------------------------------------------------------------------------
FrameBuffer* OpenGLFrameBuffer::Create (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
{
    // Check for required extensions.
    if (!GTExistsGlExtFrameBufferObject)
    {
        return 0;
    }

    if (pkRenderer && pkTarget)
    {
        OpenGLFrameBuffer* pkBuffer = WM4_NEW OpenGLFrameBuffer(eFormat,
            eDepth,eStencil,eBuffering,eMultisampling,pkRenderer,pkTarget);

        if (pkBuffer->InitializeBuffer())
        {
            return pkBuffer;
        }

        WM4_DELETE pkBuffer;
    }
    return 0;
}
//----------------------------------------------------------------------------
void OpenGLFrameBuffer::Destroy (FrameBuffer* pkBuffer)
{
    ((OpenGLFrameBuffer*)pkBuffer)->TerminateBuffer();
    WM4_DELETE pkBuffer;
}
//----------------------------------------------------------------------------
OpenGLFrameBuffer::OpenGLFrameBuffer (FormatType eFormat, DepthType eDepth,
    StencilType eStencil, BufferingType eBuffering,
    MultisamplingType eMultisampling, Renderer* pkRenderer, Texture* pkTarget)
    :
    FrameBuffer(eFormat,eDepth,eStencil,eBuffering,eMultisampling,pkRenderer,
        pkTarget)
{
}
//----------------------------------------------------------------------------
OpenGLFrameBuffer::~OpenGLFrameBuffer ()
{
}
//----------------------------------------------------------------------------
bool OpenGLFrameBuffer::InitializeBuffer ()
{
    Image* pkImage = m_pkTarget->GetImage();
    if (pkImage->IsCubeImage())
    {
        // TO DO.  Cube map images not supported yet, but they should be.
        return false;
    }

    ResourceIdentifier* pkID = m_pkTarget->GetIdentifier(m_pkRenderer);
    assert(pkID);
    TextureID* pkResource = (TextureID*)pkID;
    m_uiTargetID = pkResource->ID;
    glBindTexture(GL_TEXTURE_2D,m_uiTargetID);

    glGenFramebuffersEXT(1,&m_uiFrameBufferID);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,m_uiFrameBufferID);
    if (!m_pkTarget->IsDepthTexture())
    {
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT,GL_COLOR_ATTACHMENT0_EXT,
            GL_TEXTURE_2D,m_uiTargetID,0);
    }
    else
    {
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT,GL_DEPTH_ATTACHMENT_EXT,
            GL_TEXTURE_2D,m_uiTargetID,0);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
    }

    GLenum uiStatus = glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);
    int iStopHere;
    switch (uiStatus)
    {
    case GL_FRAMEBUFFER_COMPLETE_EXT:
        iStopHere = 0;
        glBindTexture(GL_TEXTURE_2D,0);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,0);
        return true;
    case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT:
        iStopHere = 1;
        break;
    case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT:
        iStopHere = 2;
        break;
    case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT:
        iStopHere = 3;
        break;
    case GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT:
        iStopHere = 4;
        break;
    case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT:
        iStopHere = 5;
        break;
    case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT:
        iStopHere = 6;
        break;
    case GL_FRAMEBUFFER_UNSUPPORTED_EXT:
        iStopHere = 7;
        break;
    }
    assert(false);
    return false;
}
//----------------------------------------------------------------------------
void OpenGLFrameBuffer::TerminateBuffer ()
{
    glDeleteFramebuffersEXT(1,&m_uiFrameBufferID);
    if (m_pkTarget->IsDepthTexture())
    {
        glDeleteRenderbuffersEXT(1,&m_uiDepthBufferID);
    }
}
//----------------------------------------------------------------------------
void OpenGLFrameBuffer::Enable ()
{
    glBindTexture(GL_TEXTURE_2D,0);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,m_uiFrameBufferID);

    OpenGLRenderer* pkRenderer = (OpenGLRenderer*)m_pkRenderer;
    Image* pkImage = m_pkTarget->GetImage();
    glViewport(0,0,pkImage->GetBound(0),pkImage->GetBound(1));
    pkRenderer->OnFrustumChange();
    pkRenderer->OnFrameChange();
}
//----------------------------------------------------------------------------
void OpenGLFrameBuffer::Disable ()
{
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,0);
    glBindTexture(GL_TEXTURE_2D,m_uiTargetID);

    OpenGLRenderer* pkRenderer = (OpenGLRenderer*)m_pkRenderer;
    pkRenderer->OnViewportChange();
    pkRenderer->OnFrustumChange();
    pkRenderer->OnFrameChange();
}
//----------------------------------------------------------------------------
void OpenGLFrameBuffer::CopyToTexture (bool bFillImage)
{
    // TO DO.  Only the software renderer actually does something when
    // bFillImage is 'false'.  If that is not necessary, then CopyToTexture
    // should have no parameters and should be called only when you want to
    // copy the VRAM copy into system memory.

    if (bFillImage)
    {
        Image* pkImage = m_pkTarget->GetImage();
        unsigned char* aucData = pkImage->GetData();
        int iBound0 = pkImage->GetBound(0);
        int iBound1 = pkImage->GetBound(1);

        switch (m_eFormat)
        {
        case FT_FORMAT_RGB:
            glReadPixels(0,0,iBound0,iBound1,GL_RGB,GL_UNSIGNED_BYTE,aucData);
            break;

        case FT_FORMAT_RGBA:
            glReadPixels(0,0,iBound0,iBound1,GL_RGBA,GL_UNSIGNED_BYTE,
                aucData);
            break;

        case FT_FORMAT_DEPTH:
            glReadPixels(0,0,iBound0,iBound1,GL_DEPTH_COMPONENT,GL_FLOAT,
                aucData);
            break;

        default:
            assert(false);
            break;
        }
    }
}
//----------------------------------------------------------------------------
