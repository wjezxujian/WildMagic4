// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4XSOFTRENDERER_H
#define WM4XSOFTRENDERER_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftRenderer.h"

namespace Wm4
{

class WM4_RENDERER_ITEM XSoftRenderer : public SoftRenderer
{
public:
    XSoftRenderer (Display* pkDisplay, unsigned long ulWindow,
        FrameBuffer::FormatType eFormat, FrameBuffer::DepthType eDepth,
        FrameBuffer::StencilType eStencil,
        FrameBuffer::BufferingType eBuffering,
        FrameBuffer::MultisamplingType eMultisampling,
        int iWidth, int iHeight);

    virtual ~XSoftRenderer ();

    // background color access
    virtual void SetBackgroundColor (const ColorRGBA& rkColor);

    // back buffer handling
    virtual void ClearBackBuffer ();
    virtual void DisplayBackBuffer ();

    // text drawing
    virtual int LoadFont (const char* acFace, int iSize, bool bBold,
        bool bItalic);
    virtual void UnloadFont (int iFontID);
    virtual bool SelectFont (int iFontID);
    virtual void Draw (int iX, int iY, const ColorRGBA& rkColor,
        const char* acText);

    // 2D drawing
    virtual void Draw (const unsigned char* aucBuffer);

    // Enable or disable which color channels will be written to the color
    // buffer.
    virtual void SetColorMask (bool bAllowRed, bool bAllowGreen,
        bool bAllowBlue, bool bAllowAlpha);

    Display* GetDisplay () { return m_pkDisplay; }
    Window GetWindow () { return m_ulWindow; }
    GC GetContext () { return m_pkContext; }

private:
    virtual void ClearSubBackBuffer (int iXMin, int iYMin, int iXMax,
        int iYMax);

    virtual void SetColorBuffer (int iX, int iY, int iIndex,
        const ColorRGBA& rkColor);

    Display* m_pkDisplay;
    Window m_ulWindow;
    GC m_pkContext;
    Pixmap m_kPixmap;
};

}

#endif
