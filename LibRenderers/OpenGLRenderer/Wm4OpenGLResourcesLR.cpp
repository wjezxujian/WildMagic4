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

GLenum OpenGLRenderer::ms_aeTextureMipmap[Texture::MAX_FILTER_TYPES] =
{
    GL_NEAREST,
    GL_LINEAR,
    GL_NEAREST_MIPMAP_NEAREST,
    GL_NEAREST_MIPMAP_LINEAR,
    GL_LINEAR_MIPMAP_NEAREST,
    GL_LINEAR_MIPMAP_LINEAR
};

GLenum OpenGLRenderer::ms_aeWrapMode[Texture::MAX_WRAP_TYPES] =
{
    GL_CLAMP,
    GL_REPEAT,
    GL_MIRRORED_REPEAT,
    GL_CLAMP_TO_BORDER,
    GL_CLAMP_TO_EDGE
};

GLenum OpenGLRenderer::ms_aeImageComponents[Image::IT_QUANTITY] =
{
    GL_RGB8,               // Image::IT_RGB888
    GL_RGBA8,              // Image::IT_RGBA8888
    GL_DEPTH_COMPONENT16,  // Image::IT_DEPTH16
    GL_DEPTH_COMPONENT24,  // Image::IT_DEPTH24
    GL_DEPTH_COMPONENT32,  // Image::IT_DEPTH32
    GL_RGB8,               // Image::IT_CUBE_RGB888
    GL_RGBA8,              // Image::IT_CUBE_RGBA8888

    // TO DO.  Not yet tested.
    GL_RGB32F_ARB,         // Image::IT_RGB32
    GL_RGBA32F_ARB         // Image::IT_RGBA32
};

GLenum OpenGLRenderer::ms_aeImageFormats[Image::IT_QUANTITY] =
{
    GL_RGB,              // Image::IT_RGB888
    GL_RGBA,             // Image::IT_RGBA8888
    GL_DEPTH_COMPONENT,  // Image::IT_DEPTH16
    GL_DEPTH_COMPONENT,  // Image::IT_DEPTH24
    GL_DEPTH_COMPONENT,  // Image::IT_DEPTH32
    GL_RGB,              // Image::IT_CUBE_RGB888
    GL_RGBA,             // Image::IT_CUBE_RGBA8888

    // TO DO.  Not yet tested.
    GL_RGB,              // Image::IT_RGB32
    GL_RGBA              // Image::IT_RGBA32
};

GLenum OpenGLRenderer::ms_aeImageTypes[Image::IT_QUANTITY] =
{
    GL_UNSIGNED_BYTE,    // Image::IT_RGB888
    GL_UNSIGNED_BYTE,    // Image::IT_RGBA8888
    GL_FLOAT,            // Image::IT_DEPTH16
    GL_FLOAT,            // Image::IT_DEPTH24
    GL_DEPTH_COMPONENT,  // Image::IT_DEPTH32
    GL_UNSIGNED_BYTE,    // Image::IT_CUBE_RGB888
    GL_UNSIGNED_BYTE,    // Image::IT_CUBE_RGBA8888

    // TO DO.  Not yet tested.
    GL_FLOAT,            // Image::IT_RGB32
    GL_FLOAT             // Image::IT_RGBA32
};

GLenum OpenGLRenderer::ms_aeSamplerTypes[
    SamplerInformation::MAX_SAMPLER_TYPES] =
{
    GL_TEXTURE_1D,        // SamplerInformation::SAMPLER_1D
    GL_TEXTURE_2D,        // SamplerInformation::SAMPLER_2D
    GL_TEXTURE_3D,        // SamplerInformation::SAMPLER_3D
    GL_TEXTURE_CUBE_MAP,  // SamplerInformation::SAMPLER_CUBE
    GL_TEXTURE_2D,        // SamplerInformation::SAMPLER_PROJ
};

GLenum OpenGLRenderer::ms_aeDepthCompare[Texture::DC_QUANTITY] =
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
void OpenGLRenderer::OnLoadVProgram (ResourceIdentifier*& rpkID,
    VertexProgram* pkVProgram)
{
    // Generate binding information and compile the program.
    VProgramID* pkResource = WM4_NEW VProgramID;
    rpkID = pkResource;

    const char* acProgramText = pkVProgram->GetProgramText().c_str();
    int iProgramLength = (int)strlen(acProgramText);

    glEnable(GL_VERTEX_PROGRAM_ARB);
    glGenProgramsARB(1,&pkResource->ID);
    glBindProgramARB(GL_VERTEX_PROGRAM_ARB,pkResource->ID);
    glProgramStringARB(GL_VERTEX_PROGRAM_ARB,GL_PROGRAM_FORMAT_ASCII_ARB,
        iProgramLength,acProgramText);
    glDisable(GL_VERTEX_PROGRAM_ARB);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnReleaseVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    glDeleteProgramsARB(1,&pkResource->ID);
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnLoadPProgram (ResourceIdentifier*& rpkID,
    PixelProgram* pkPProgram)
{
    // Generate binding information and compile the shader.
    PProgramID* pkResource = WM4_NEW PProgramID;
    rpkID = pkResource;

    const char* acProgramText = pkPProgram->GetProgramText().c_str();
    int iProgramLength = (int)strlen(acProgramText);

    glEnable(GL_FRAGMENT_PROGRAM_ARB);
    glGenProgramsARB(1,&pkResource->ID);
    glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB,pkResource->ID);
    glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB,GL_PROGRAM_FORMAT_ASCII_ARB,
        iProgramLength,acProgramText);
    glDisable(GL_FRAGMENT_PROGRAM_ARB);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnReleasePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    glDeleteProgramsARB(1,&pkResource->ID);
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnLoadTexture (ResourceIdentifier*& rpkID,
    Texture* pkTexture)
{
    // Activate the texture unit in hardware that will manage this texture.
    TextureID* pkResource = WM4_NEW TextureID;
    pkResource->TextureObject = pkTexture;
    rpkID = pkResource;

    SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
    SamplerInformation::Type eSType = pkSI->GetType();
    int eTarget = ms_aeSamplerTypes[eSType];

    // Get the texture image and its information.
    const Image* pkImage = pkTexture->GetImage();
    assert(pkImage);
    unsigned char* aucData = pkImage->GetData();
    int iComponent = ms_aeImageComponents[pkImage->GetFormat()];
    int eFormat = ms_aeImageFormats[pkImage->GetFormat()];
    int eIType = ms_aeImageTypes[pkImage->GetFormat()];

    // Generate the name and binding information.
    glGenTextures((GLsizei)1,&pkResource->ID);
    glBindTexture(eTarget,pkResource->ID);

    // Set the filter mode.
    Texture::FilterType eFType = pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST)
    {
        glTexParameteri(eTarget,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    }
    else
    {
        // TO DO.  Support anisotropic filtering.  To query for the maximum
        // allowed anisotropy, use
        //   float fMax;
        //   glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT,&fMax);
        // To enable filtering, use
        //   glTexParameterf(eTarget,GL_TEXTURE_MAX_ANISOTROPY_EXT,fValue);
        // where 1 <= fValue <= fMax.

        glTexParameteri(eTarget,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }

    // Set the mipmap mode.
    glTexParameteri(eTarget,GL_TEXTURE_MIN_FILTER,
        ms_aeTextureMipmap[eFType]);

    // Set the border color (for clamp to border).
    glTexParameterfv(eTarget,GL_TEXTURE_BORDER_COLOR,
        (const float*)pkTexture->GetBorderColor());

    // Copy the image data from system memory to video memory.
    bool bNoMip =
        (eFType == Texture::NEAREST || eFType == Texture::LINEAR);

    bool bDepth = pkTexture->IsDepthTexture();

    switch (eSType)
    {
    case SamplerInformation::SAMPLER_1D:
        if (bNoMip)
        {
            glTexImage1D(eTarget,0,iComponent,pkImage->GetBound(0),0,
                eFormat,eIType,aucData);
        }
        else
        {
            gluBuild1DMipmaps(eTarget,iComponent,pkImage->GetBound(0),
                eFormat,eIType,aucData);
        }
        glTexParameteri(eTarget,GL_TEXTURE_WRAP_S,
            ms_aeWrapMode[pkTexture->GetWrapType(0)]);
        break;

    case SamplerInformation::SAMPLER_2D:
    case SamplerInformation::SAMPLER_PROJ:
        if (!bDepth)
        {
            if (bNoMip)
            {
                glTexImage2D(eTarget,0,iComponent,pkImage->GetBound(0),
                    pkImage->GetBound(1),0,eFormat,eIType,aucData);
            }
            else
            {
                gluBuild2DMipmaps(eTarget,iComponent,pkImage->GetBound(0),
                    pkImage->GetBound(1),eFormat,eIType,aucData);
            }
        }
        else
        {
            glTexImage2D(eTarget,0,iComponent,pkImage->GetBound(0),
                pkImage->GetBound(1),0,eFormat,eIType,0);

            // set up depth comparison
            glTexParameteri(eTarget,GL_TEXTURE_COMPARE_MODE,
                GL_COMPARE_R_TO_TEXTURE);
            glTexParameteri(eTarget,GL_TEXTURE_COMPARE_FUNC,
                ms_aeDepthCompare[pkTexture->GetDepthCompare()]);
        }

        glTexParameteri(eTarget,GL_TEXTURE_WRAP_S,
            ms_aeWrapMode[pkTexture->GetWrapType(0)]);
        glTexParameteri(eTarget,GL_TEXTURE_WRAP_T,
            ms_aeWrapMode[pkTexture->GetWrapType(1)]);
        break;

    case SamplerInformation::SAMPLER_3D:
        // TO DO.  Microsoft's GLU library does not implement the function
        // gluBuild3DMipmaps.  DirectX9 SDK does not support automatic
        // generation of mipmaps for volume textures.  For now, do not
        // support mipmaps of 3D textures.  However, manually generated
        // mipmaps can be added later.  The LibGraphics Sampler classes
        // already implement this for software rendering.
        glTexImage3D(eTarget,0,iComponent,pkImage->GetBound(0),
            pkImage->GetBound(1),pkImage->GetBound(2),0,eFormat,eIType,
            aucData);

        glTexParameteri(eTarget,GL_TEXTURE_WRAP_S,
            ms_aeWrapMode[pkTexture->GetWrapType(0)]);
        glTexParameteri(eTarget,GL_TEXTURE_WRAP_T,
            ms_aeWrapMode[pkTexture->GetWrapType(1)]);
        glTexParameteri(eTarget,GL_TEXTURE_WRAP_R,
            ms_aeWrapMode[pkTexture->GetWrapType(2)]);
        break;

    case SamplerInformation::SAMPLER_CUBE:
    {
        // A cube map image has 6 subimages (+x,-x,+y,-y,+z,-z).
        assert(pkImage->IsCubeImage());
        int i, iIncrement = pkImage->GetBytesPerPixel() *
            pkImage->GetQuantity();

        if (bNoMip)
        {
            for (i = 0; i < 6; i++, aucData += iIncrement)
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,
                    iComponent,pkImage->GetBound(0),pkImage->GetBound(1),
                    0,eFormat,eIType,aucData);
            }
        }
        else
        {
            for (i = 0; i < 6; i++, aucData += iIncrement)
            {
                gluBuild2DMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,
                    iComponent,pkImage->GetBound(0),pkImage->GetBound(1),
                    eFormat,eIType,aucData);
            }
        }
        break;
    }
    default:
        assert(false);
        break;
    }
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnReleaseTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    glDeleteTextures((GLsizei)1,(GLuint*)&pkResource->ID);
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnLoadVBuffer (ResourceIdentifier*& rpkID,
    const Attributes& rkIAttr, const Attributes& rkOAttr,
    VertexBuffer* pkVBuffer)
{
    VBufferID* pkResource = WM4_NEW VBufferID;
    rpkID = pkResource;
    pkResource->IAttr = rkIAttr;
    pkResource->OAttr = rkOAttr;

    int iChannels;
    float* afCompatible = 0;  // allocated by BuildCompatibleArray
    pkVBuffer->BuildCompatibleArray(rkIAttr,false,iChannels,afCompatible);

    // Generate the name and binding information.
    glGenBuffers(1,&pkResource->ID);
    glBindBuffer(GL_ARRAY_BUFFER,pkResource->ID);

    // Copy the vertex buffer data from system memory to video memory.
    glBufferData(GL_ARRAY_BUFFER,iChannels*sizeof(float),afCompatible,
        GL_STATIC_DRAW);

    WM4_DELETE[] afCompatible;
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnReleaseVBuffer (ResourceIdentifier* pkID)
{
    VBufferID* pkResource = (VBufferID*)pkID;
    glDeleteBuffers(1,&pkResource->ID);
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnLoadIBuffer (ResourceIdentifier*& rpkID,
    IndexBuffer* pkIBuffer)
{
    IBufferID* pkResource = WM4_NEW IBufferID;
    rpkID = pkResource;

    glGenBuffers(1,&pkResource->ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,pkResource->ID);

    // Copy the index buffer data from system memory to video memory.
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        pkIBuffer->GetIndexQuantity()*sizeof(int),pkIBuffer->GetData(),
        GL_STATIC_DRAW);
}
//----------------------------------------------------------------------------
void OpenGLRenderer::OnReleaseIBuffer (ResourceIdentifier* pkID)
{
    IBufferID* pkResource = (IBufferID*)pkID;
    glDeleteBuffers(1,&pkResource->ID);
    WM4_DELETE pkResource;
}
//----------------------------------------------------------------------------
