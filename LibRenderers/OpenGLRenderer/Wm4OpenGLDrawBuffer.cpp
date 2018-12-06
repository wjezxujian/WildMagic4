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
void OpenGLRenderer::Draw (const unsigned char* aucBuffer)
{
    if (!aucBuffer)
    {
        return;
    }

    // disable other states that are not necessary for the buffer copy
    GLboolean bDepthTest = glIsEnabled(GL_DEPTH_TEST);
    GLboolean bLighting = glIsEnabled(GL_LIGHTING);
    GLboolean bTexture2D = glIsEnabled(GL_TEXTURE_2D);
    if (bDepthTest)
    {
        glDisable(GL_DEPTH_TEST);
    }
    if (bLighting)
    {
        glDisable(GL_LIGHTING);
    }
    if (bTexture2D)
    {
        glDisable(GL_TEXTURE_2D);
    }

    // Set raster position to window coord (0,H-1).  The hack here avoids
    // problems with invalid raster positions which would cause glDrawPixels
    // not to execute.  OpenGL uses right-handed screen coordinates, so using
    // (0,H-1) as the raster position followed by glPixelZoom(1,-1) tells
    // OpenGL to draw the screen in left-handed coordinates starting at the
    // top row of the screen and finishing at the bottom row.
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0,(double)m_iWidth,0.0,(double)m_iHeight,0.0,1.0);
    glRasterPos3f(0.0,0.0,0.0);
    GLubyte aucBitmap[1] = {0};
    glBitmap(0,0,0.0f,0.0f,0.0f,(float)m_iHeight,aucBitmap);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glPixelZoom(1.0f,-1.0f);
    glDrawPixels(m_iWidth,m_iHeight,GL_BGR,GL_UNSIGNED_BYTE,aucBuffer);
    glPixelZoom(1.0f,1.0f);

    // reenable states
    if (bDepthTest)
    {
        glEnable(GL_DEPTH_TEST);
    }
    if (bLighting)
    {
        glEnable(GL_LIGHTING);
    }
    if (bTexture2D)
    {
        glEnable(GL_TEXTURE_2D);
    }
}
//----------------------------------------------------------------------------
