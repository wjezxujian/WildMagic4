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
using namespace Wm4;

GLenum OpenGLRenderer::ms_aeZBufferCompare[ZBufferState::CF_QUANTITY] =
{
    GL_NEVER,
    GL_LESS,
    GL_EQUAL,
    GL_LEQUAL,
    GL_GREATER,
    GL_NOTEQUAL,
    GL_GEQUAL,
    GL_ALWAYS
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetZBufferState (ZBufferState* pkState)
{
    Renderer::SetZBufferState(pkState);

    if (pkState->Enabled)
    {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(ms_aeZBufferCompare[pkState->Compare]);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
        glDepthFunc(GL_ALWAYS);
    }

    if (pkState->Writable)
    {
        glDepthMask(GL_TRUE);
    }
    else
    {
        glDepthMask(GL_FALSE);
    }
}
//----------------------------------------------------------------------------
