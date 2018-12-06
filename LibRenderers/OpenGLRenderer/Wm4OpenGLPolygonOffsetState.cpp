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

//----------------------------------------------------------------------------
void OpenGLRenderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    Renderer::SetPolygonOffsetState(pkState);

    if (pkState->FillEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_FILL);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_FILL);
    }

    if (pkState->LineEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_LINE);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_LINE);
    }

    if (pkState->PointEnabled)
    {
        glEnable(GL_POLYGON_OFFSET_POINT);
    }
    else
    {
        glDisable(GL_POLYGON_OFFSET_POINT);
    }

    glPolygonOffset(pkState->Scale,pkState->Bias);
}
//----------------------------------------------------------------------------
