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
#include "Wm4OpenGLResources.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void OpenGLRenderer::SetVProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    if (eCType != Renderer::CT_NUMERICAL)
    {
        for (int j = 0; j < iRegisterQuantity; j++)
        {
            glProgramLocalParameter4fvARB(GL_VERTEX_PROGRAM_ARB,
                (GLuint)iBaseRegister,afData);
            iBaseRegister++;
            afData += 4;
        }
    }
}
//----------------------------------------------------------------------------
void OpenGLRenderer::SetPProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    if (eCType != Renderer::CT_NUMERICAL)
    {
        for (int j = 0; j < iRegisterQuantity; j++)
        {
            glProgramLocalParameter4fvARB(GL_FRAGMENT_PROGRAM_ARB,
                (GLuint)iBaseRegister,afData);
            iBaseRegister++;
            afData += 4;
        }
    }
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnEnableVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    glEnable(GL_VERTEX_PROGRAM_ARB);
    glBindProgramARB(GL_VERTEX_PROGRAM_ARB,pkResource->ID);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDisableVProgram (ResourceIdentifier*)
{
    glDisable(GL_VERTEX_PROGRAM_ARB);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnEnablePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB,pkResource->ID);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDisablePProgram (ResourceIdentifier*)
{
    glDisable(GL_FRAGMENT_PROGRAM_ARB);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnEnableTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    Texture* pkTexture = pkResource->TextureObject;

    SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
    SamplerInformation::Type eSType = pkSI->GetType();
    int iTextureUnit = pkSI->GetTextureUnit();
    int eTarget = ms_aeSamplerTypes[eSType];

    glClientActiveTexture(GL_TEXTURE0 + iTextureUnit);
    glActiveTexture(GL_TEXTURE0 + iTextureUnit);
    glBindTexture(eTarget,pkResource->ID);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDisableTexture (ResourceIdentifier*)
{
    // Nothing to do.
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnEnableVBuffer (ResourceIdentifier* pkID)
{
    // Bind the current vertex buffer.
    VBufferID* pkResource = (VBufferID*)pkID;
    glBindBuffer(GL_ARRAY_BUFFER,pkResource->ID);

    const Attributes& rkRAttr = pkResource->IAttr;
    GLsizei iSize = (GLsizei)(sizeof(float)*rkRAttr.GetChannelQuantity());
    const float* afData = 0;

    if (rkRAttr.HasPosition())
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(rkRAttr.GetPChannels(),GL_FLOAT,iSize,
            afData + rkRAttr.GetPOffset());
    }

    if (rkRAttr.HasNormal())
    {
        // OpenGL appears not to allow you to specify the number of
        // components for the normal vectors.  Thus, rkAttr.GetNChannels()
        // should be 3.
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT,iSize,
            afData + rkRAttr.GetNOffset());
    }

    if (rkRAttr.HasColor(0))
    {
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(rkRAttr.GetCChannels(0),GL_FLOAT,iSize,
            afData + rkRAttr.GetCOffset(0));
    }

    if (rkRAttr.HasColor(1))
    {
        glEnableClientState(GL_SECONDARY_COLOR_ARRAY);
        glSecondaryColorPointer(rkRAttr.GetCChannels(1),GL_FLOAT,iSize,
            afData + rkRAttr.GetCOffset(1));
    }

    for (int iUnit = 0; iUnit < rkRAttr.GetMaxTCoords(); iUnit++)
    {
        if (rkRAttr.HasTCoord(iUnit))
        {
            glClientActiveTexture(GL_TEXTURE0 + iUnit);
            glActiveTexture(GL_TEXTURE0 + iUnit);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY); 
            glTexCoordPointer(rkRAttr.GetTChannels(iUnit),GL_FLOAT,iSize,
                afData + rkRAttr.GetTOffset(iUnit));
        }
    }
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDisableVBuffer (ResourceIdentifier* pkID)
{
    VBufferID* pkResource = (VBufferID*)pkID;
    const Attributes& rkRAttr = pkResource->IAttr;

    // Unbind the current vertex buffer.
    glBindBuffer(GL_ARRAY_BUFFER,0);

    if (rkRAttr.HasPosition())
    {
        glDisableClientState(GL_VERTEX_ARRAY);
    }

    if (rkRAttr.HasNormal())
    {
        glDisableClientState(GL_NORMAL_ARRAY);
    }

    if (rkRAttr.HasColor(0))
    {
        glDisableClientState(GL_COLOR_ARRAY);
    }

    if (rkRAttr.HasColor(1))
    {
        glDisableClientState(GL_SECONDARY_COLOR_ARRAY);
    }

    for (int iUnit = 0; iUnit < rkRAttr.GetMaxTCoords(); iUnit++)
    {
        if (rkRAttr.HasTCoord(iUnit))
        {
            glClientActiveTexture(GL_TEXTURE0 + iUnit);
            glActiveTexture(GL_TEXTURE0 + iUnit);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        }
    }
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnEnableIBuffer (ResourceIdentifier* pkID)
{
    // Bind the current index buffer.
    IBufferID* pkResource = (IBufferID*)pkID;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,pkResource->ID);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnDisableIBuffer (ResourceIdentifier*)
{
    // Unbind the current index buffer.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
//----------------------------------------------------------------------------
