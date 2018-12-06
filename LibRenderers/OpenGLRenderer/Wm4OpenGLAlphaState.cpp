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

GLenum OpenGLRenderer::ms_aeAlphaSrcBlend[AlphaState::SBF_QUANTITY] =
{
    GL_ZERO,
    GL_ONE,
    GL_DST_COLOR,
    GL_ONE_MINUS_DST_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
    GL_SRC_ALPHA_SATURATE,
    GL_CONSTANT_COLOR,
    GL_ONE_MINUS_CONSTANT_COLOR,
    GL_CONSTANT_ALPHA,
    GL_ONE_MINUS_CONSTANT_ALPHA
};

GLenum OpenGLRenderer::ms_aeAlphaDstBlend[AlphaState::DBF_QUANTITY] =
{
    GL_ZERO,
    GL_ONE,
    GL_SRC_COLOR,
    GL_ONE_MINUS_SRC_COLOR,
    GL_SRC_ALPHA,
    GL_ONE_MINUS_SRC_ALPHA,
    GL_DST_ALPHA,
    GL_ONE_MINUS_DST_ALPHA,
    GL_CONSTANT_COLOR,
    GL_ONE_MINUS_CONSTANT_COLOR,
    GL_CONSTANT_ALPHA,
    GL_ONE_MINUS_CONSTANT_ALPHA
};

GLenum OpenGLRenderer::ms_aeAlphaTest[AlphaState::TF_QUANTITY] =
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
void OpenGLRenderer::SetAlphaState (AlphaState* pkState)
{
    Renderer::SetAlphaState(pkState);

    if (pkState->BlendEnabled)
    {
        glEnable(GL_BLEND);
        glBlendFunc(ms_aeAlphaSrcBlend[pkState->SrcBlend],
            ms_aeAlphaDstBlend[pkState->DstBlend]);
    }
    else
    {
        glDisable(GL_BLEND);
    }

    if (pkState->TestEnabled)
    {
        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(ms_aeAlphaTest[pkState->Test],pkState->Reference);
    }
    else
    {
        glDisable(GL_ALPHA_TEST);
    }

    glBlendColor(pkState->ConstantColor.R(),pkState->ConstantColor.G(),
        pkState->ConstantColor.G(),pkState->ConstantColor.A());
}
//----------------------------------------------------------------------------
