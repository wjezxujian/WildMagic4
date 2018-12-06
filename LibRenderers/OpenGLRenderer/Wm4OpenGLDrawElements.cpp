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

GLenum OpenGLRenderer::ms_aeObjectType[Geometry::GT_MAX_QUANTITY] =
{
    GL_POINTS,      // GT_POLYPOINT
    GL_LINES,       // GT_POLYLINE_SEGMENTS
    GL_LINE_STRIP,  // GT_POLYLINE_OPEN
    GL_LINE_LOOP,   // GT_POLYLINE_CLOSED
    GL_TRIANGLES    // GT_TRIMESH
};

//----------------------------------------------------------------------------
void OpenGLRenderer::DrawElements ()
{
    IndexBuffer* pkIBuffer = m_pkGeometry->IBuffer;
    assert(pkIBuffer);
    GLenum eType = ms_aeObjectType[m_pkGeometry->Type];
    glDrawElements(eType,pkIBuffer->GetIndexQuantity(),GL_UNSIGNED_INT,0);
}
//----------------------------------------------------------------------------
