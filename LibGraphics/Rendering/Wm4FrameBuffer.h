// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4FRAMEBUFFER_H
#define WM4FRAMEBUFFER_H

#include "Wm4GraphicsLIB.h"

namespace Wm4
{

class Renderer;
class Texture;

class WM4_GRAPHICS_ITEM FrameBuffer
{
public:
    enum FormatType
    {
        FT_FORMAT_NONE,
        FT_FORMAT_RGB,
        FT_FORMAT_RGBA,
        FT_FORMAT_DEPTH
    };

    enum DepthType
    {
        DT_DEPTH_NONE,
        DT_DEPTH_16,
        DT_DEPTH_24,
        DT_DEPTH_32
    };

    enum StencilType
    {
        ST_STENCIL_NONE,
        ST_STENCIL_8
    };

    enum BufferingType
    {
        BT_BUFFERED_SINGLE,
        BT_BUFFERED_DOUBLE
    };

    enum MultisamplingType
    {
        MT_SAMPLING_NONE,
        MT_SAMPLING_2,
        MT_SAMPLING_4
    };

    // Abstract base class.  The FrameBuffer::Create and FrameBuffer::Destroy
    // functions form a factory.  The input pkTarget must be a SAMPLER_2D
    // target.  The frame buffer is 2D and has width and height of the target
    // texture.
    static FrameBuffer* Create (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    static void Destroy (FrameBuffer* pkBuffer);

    FrameBuffer (FormatType eFormat, DepthType eDepth, StencilType eStencil,
        BufferingType eBuffering, MultisamplingType eSampling,
        Renderer* pkRenderer, Texture* pkTarget);

    virtual ~FrameBuffer ();

    // Member access.
    FormatType GetFormatType () const;
    DepthType GetDepthType () const;
    StencilType GetStencilType () const;
    BufferingType GetBufferingType () const;
    MultisamplingType GetMultisamplingType () const;
    Renderer* GetRenderer ();
    Texture* GetTarget ();

    virtual void Enable () = 0;
    virtual void Disable () = 0;

    // Copy the data from the frame buffer object to the texture object.
    // If you want the Image object filled with the values, set the input
    // to 'true'.
    virtual void CopyToTexture (bool bFillImage) = 0;

protected:
    FormatType m_eFormat;
    DepthType m_eDepth;
    StencilType m_eStencil;
    BufferingType m_eBuffering;
    MultisamplingType m_eMultisampling;
    Renderer* m_pkRenderer;
    Texture* m_pkTarget;

    // The frame buffer factory.  Each derived class implements a Creator and
    // a Destroyer and assigns the function pointers to the static data
    // members declared here.
    typedef FrameBuffer* (*Creator)(FormatType, DepthType, StencilType,
        BufferingType, MultisamplingType, Renderer*, Texture*);
    typedef void (*Destroyer)(FrameBuffer*);
    static Creator ms_aoCreate[];
    static Destroyer ms_aoDestroy[];
};

#include "Wm4FrameBuffer.inl"

}

#endif
