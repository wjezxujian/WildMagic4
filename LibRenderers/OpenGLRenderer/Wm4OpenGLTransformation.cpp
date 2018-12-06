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
void OpenGLRenderer::OnViewportChange ()
{
    float fPortL, fPortR, fPortT, fPortB;
    if (m_pkCamera)
    {
        // 3D applications use cameras.
        m_pkCamera->GetViewport(fPortL,fPortR,fPortT,fPortB);
    }
    else
    {
        // 2D applications do not use cameras.
        fPortL = 0.0f;
        fPortR = 1.0f;
        fPortT = 1.0f;
        fPortB = 0.0f;
    }

    // OpenGL defines the full-sized viewport to have origin at the lower
    // left corner of the screen.  The fB value specifies the relative
    // distance from the bottom of the screen.  Wild Magic also uses this
    // convention, but DirectX does not (in which case iY is computed
    // differently for DirectX).
    GLint iX = (GLint)(fPortL*m_iWidth);
    GLint iY = (GLint)(fPortB*m_iHeight);  // See note above.
    GLsizei iW = (GLsizei)((fPortR - fPortL)*m_iWidth);
    GLsizei iH = (GLsizei)((fPortT - fPortB)*m_iHeight);
    glViewport(iX,iY,iW,iH);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDepthRangeChange ()
{
    if (m_pkCamera)
    {
        float fPortN, fPortF;
        m_pkCamera->GetDepthRange(fPortN,fPortF);
        glDepthRange((GLclampd)fPortN,(GLclampd)fPortF);
    }
    else
    {
        glDepthRange(0.0,1.0);
    }
}
//----------------------------------------------------------------------------
