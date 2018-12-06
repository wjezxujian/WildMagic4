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

GLenum OpenGLRenderer::ms_aeStencilCompare[StencilState::CF_QUANTITY] =
{
    GL_NEVER,     // StencilState::CF_NEVER
    GL_LESS,      // StencilState::CF_LESS
    GL_EQUAL,     // StencilState::CF_EQUAL
    GL_LEQUAL,    // StencilState::CF_LEQUAL
    GL_GREATER,   // StencilState::CF_GREATER
    GL_NOTEQUAL,  // StencilState::CF_NOTEQUAL
    GL_GEQUAL,    // StencilState::CF_GEQUAL
    GL_ALWAYS     // StencilState::CF_ALWAYS
};

GLenum OpenGLRenderer::ms_aeStencilOperation[StencilState::OT_QUANTITY] =
{
    GL_KEEP,      // StencilState::OT_KEEP
    GL_ZERO,      // StencilState::OT_ZERO
    GL_REPLACE,   // StencilState::OT_REPLACE
    GL_INCR,      // StencilState::OT_INCREMENT
    GL_DECR,      // StencilState::OT_DECREMENT
    GL_INVERT     // StencilState::OT_INVERT
};

//----------------------------------------------------------------------------
void OpenGLRenderer::SetStencilState (StencilState* pkState)
{
    Renderer::SetStencilState(pkState);

    if (pkState->Enabled)
    {
        glEnable(GL_STENCIL_TEST);

        glStencilFunc(ms_aeStencilCompare[pkState->Compare],
            (GLint)pkState->Reference,pkState->Mask);

        glStencilMask(pkState->WriteMask);

        glStencilOp(ms_aeStencilOperation[pkState->OnFail],
            ms_aeStencilOperation[pkState->OnZFail],
            ms_aeStencilOperation[pkState->OnZPass]);
    }
    else
    {
        glDisable(GL_STENCIL_TEST);
    }
}
//----------------------------------------------------------------------------
