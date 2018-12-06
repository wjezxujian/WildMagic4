// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DX9FRAMEBUFFER_H
#define WM4DX9FRAMEBUFFER_H

#include "Wm4Dx9RendererLIB.h"
#include "Wm4Dx9Renderer.h"
#include "Wm4Dx9Utility.h"
#include "Wm4Main.h"
#include "Wm4FrameBuffer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM Dx9FrameBuffer : public FrameBuffer
{
    WM4_DECLARE_INITIALIZE;

public:
    Dx9FrameBuffer (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    virtual ~Dx9FrameBuffer ();

    bool InitializeBuffer ();
    void TerminateBuffer ();

    virtual void Enable ();
    virtual void Disable ();
    virtual void CopyToTexture (bool bFillImage);

protected:
    IDirect3DTexture9* m_pkTargetID;
    ID3DXRenderToSurface* m_pkRenderToTexture;
    IDirect3DSurface9* m_pkTextureSurface;
    IDirect3DSurface9* m_pkSaveTextureSurface;
    IDirect3DSurface9* m_pkDepthStencilSurface;
    IDirect3DSurface9* m_pkSaveDepthStencilSurface;

    IDirect3DTexture9* m_pkCopyTexture;
    IDirect3DSurface9* m_pkCopySurface;

    // factory functions
    static FrameBuffer* Create (FormatType eFormat, DepthType eDepth,
        StencilType eStencil, BufferingType eBuffering,
        MultisamplingType eMultisampling, Renderer* pkRenderer,
        Texture* pkTarget);

    static void Destroy (FrameBuffer* pkBuffer);
};

WM4_REGISTER_INITIALIZE(Dx9FrameBuffer);

}

#endif
