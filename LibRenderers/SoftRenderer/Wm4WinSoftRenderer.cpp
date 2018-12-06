// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4SoftRendererPCH.h"
#include "Wm4WinSoftRenderer.h"
using namespace Wm4;

//----------------------------------------------------------------------------
WinSoftRenderer::WinSoftRenderer (HWND hWnd, FrameBuffer::FormatType eFormat,
    FrameBuffer::DepthType eDepth, FrameBuffer::StencilType eStencil,
    FrameBuffer::BufferingType eBuffering,
    FrameBuffer::MultisamplingType eMultisampling, int iWidth, int iHeight)
    :
    SoftRenderer(eFormat,eDepth,eStencil,eBuffering,eMultisampling,iWidth,
        iHeight,false)
{
    m_hWnd = hWnd;
    m_hWindowDC = GetDC(m_hWnd);
    m_hMemoryDC = CreateCompatibleDC(m_hWindowDC);

    // Create the back buffer (32-bit format ARGB8888).  Despite its name,
    // the structure RGBQUAD is 32-bit and has blue, red, green, and reserved
    // channels.
    const size_t uiLength = sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD*);
    char* acBitMapInfo = WM4_NEW char[uiLength];
    memset(acBitMapInfo,0,uiLength);
    BITMAPINFOHEADER& bmih = *(BITMAPINFOHEADER*)acBitMapInfo;
    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biWidth = m_iWidth;
    bmih.biHeight = -m_iHeight;
    bmih.biPlanes = 1;
    bmih.biBitCount = 32;
    bmih.biCompression = BI_RGB;
    bmih.biSizeImage = m_iWidth*m_iHeight;
    bmih.biXPelsPerMeter = 0;
    bmih.biYPelsPerMeter = 0;
    bmih.biClrUsed = 0;
    bmih.biClrImportant = 0;

    unsigned int* auiColorBuffer = 0;
    m_hBBitmap = CreateDIBSection(m_hMemoryDC,(CONST BITMAPINFO*)acBitMapInfo,
        DIB_RGB_COLORS,(void**)&auiColorBuffer,0,0);

    WM4_DELETE[] acBitMapInfo;

    SelectObject(m_hMemoryDC,m_hBBitmap);

    // Set the main colorbuffer to be the hardware-allocated one.
    m_kMain.SetColorBufferUI(auiColorBuffer);

    // Set the active framebuffer to be the main framebuffer.
    SetRenderTarget(0);
}
//----------------------------------------------------------------------------
WinSoftRenderer::~WinSoftRenderer ()
{
    DeleteObject(m_hBBitmap);
    DeleteDC(m_hMemoryDC);
    ReleaseDC(m_hWnd,m_hWindowDC);
}
//----------------------------------------------------------------------------
void WinSoftRenderer::SetBackgroundColor (const ColorRGBA& rkColor)
{
    SoftRenderer::SetBackgroundColor(rkColor);

    unsigned char ucR = (unsigned char)(255.0f*rkColor.R());
    unsigned char ucG = (unsigned char)(255.0f*rkColor.G());
    unsigned char ucB = (unsigned char)(255.0f*rkColor.B());
    unsigned char ucA = (unsigned char)(255.0f*rkColor.A());
    m_uiBackgroundColor = (ucB | (ucG << 8) | (ucR << 16) | (ucA << 24));
}
//----------------------------------------------------------------------------
void WinSoftRenderer::ClearBackBuffer ()
{
    if (m_auiColorBuffer)
    {
        unsigned int* puiColorBuffer = m_auiColorBuffer;
        ColorRGBA* pkColorBuffer = m_akColorBuffer;
        for (int i = 0; i < m_iQuantity; i++)
        {
            *puiColorBuffer++ = m_uiBackgroundColor;
            *pkColorBuffer++ = m_kBackgroundColor;
        }
    }
}
//----------------------------------------------------------------------------
void WinSoftRenderer::ClearSubBackBuffer (int iXMin, int iYMin, int iXMax,
    int iYMax)
{
    if (m_auiColorBuffer)
    {
        int iMin = iXMin + m_iWidth*iYMin;
        int iMax = iXMax + m_iWidth*iYMin;
        for (int iY = iYMin; iY < iYMax; iY++)
        {
            for (int i = iMin; i < iMax; i++)
            {
                m_auiColorBuffer[i] = m_uiBackgroundColor;
                m_akColorBuffer[i] = m_kBackgroundColor;
            }

            iMin += m_iWidth;
            iMax += m_iWidth;
        }
    }
}
//----------------------------------------------------------------------------
void WinSoftRenderer::DisplayBackBuffer ()
{
    BitBlt(m_hWindowDC,0,0,m_iWidth,m_iHeight,m_hMemoryDC,0,0,SRCCOPY);
}
//----------------------------------------------------------------------------
void WinSoftRenderer::SetColorMask (bool bAllowRed, bool bAllowGreen,
    bool bAllowBlue, bool bAllowAlpha)
{
    Renderer::SetColorMask(bAllowRed,bAllowGreen,bAllowBlue,bAllowAlpha);

    m_uiColorMask = 0;
    if (m_bAllowRed)
    {
        m_uiColorMask |= 0x00FF0000;
    }
    if (m_bAllowGreen)
    {
        m_uiColorMask |= 0x0000FF00;
    }
    if (m_bAllowBlue)
    {
        m_uiColorMask |= 0x000000FF;
    }
    if (m_bAllowAlpha)
    {
        m_uiColorMask |= 0xFF000000;
    }
}
//----------------------------------------------------------------------------
void WinSoftRenderer::SetColorBuffer (int, int, int iIndex,
    const ColorRGBA& rkColor)
{
    unsigned char ucR = (unsigned char)(255.0f*rkColor.R());
    unsigned char ucG = (unsigned char)(255.0f*rkColor.G());
    unsigned char ucB = (unsigned char)(255.0f*rkColor.B());
    unsigned char ucA = (unsigned char)(255.0f*rkColor.A());
    unsigned int uiColor = (ucB | (ucG << 8) | (ucR << 16) | (ucA << 24));

    if (m_uiColorMask == (unsigned int)~0)
    {
        m_auiColorBuffer[iIndex] = uiColor;
        m_akColorBuffer[iIndex] = rkColor;
    }
    else
    {
        m_auiColorBuffer[iIndex] =
            (m_auiColorBuffer[iIndex] & ~m_uiColorMask) |
            (uiColor & m_uiColorMask);

        ColorRGBA& rkCurrentColor = m_akColorBuffer[iIndex];
        if (m_bAllowRed)
        {
            rkCurrentColor.R() = rkColor.R();
        }
        if (m_bAllowGreen)
        {
            rkCurrentColor.G() = rkColor.G();
        }
        if (m_bAllowBlue)
        {
            rkCurrentColor.B() = rkColor.B();
        }
        if (m_bAllowAlpha)
        {
            rkCurrentColor.A() = rkColor.A();
        }
    }
}
//----------------------------------------------------------------------------
int WinSoftRenderer::LoadFont (const char* acFace, int iSize, bool bBold,
    bool bItalic)
{
    // TO DO.
    return -1;
}
//----------------------------------------------------------------------------
void WinSoftRenderer::UnloadFont (int iFontID)
{
    // TO DO.
}
//----------------------------------------------------------------------------
bool WinSoftRenderer::SelectFont (int iFontID)
{
    // TO DO.
    return false;
}
//----------------------------------------------------------------------------
void WinSoftRenderer::Draw (int iX, int iY, const ColorRGBA& rkColor,
    const char* acText)
{
    unsigned char ucR = (unsigned char)(255.0f*rkColor.R());
    unsigned char ucG = (unsigned char)(255.0f*rkColor.G());
    unsigned char ucB = (unsigned char)(255.0f*rkColor.B());
    SetTextColor(m_hMemoryDC,RGB(ucR,ucG,ucB));
    SetTextAlign(m_hMemoryDC,TA_BOTTOM);

    ucR = (unsigned char)(255.0f*m_kBackgroundColor.R());
    ucG = (unsigned char)(255.0f*m_kBackgroundColor.G());
    ucB = (unsigned char)(255.0f*m_kBackgroundColor.B());
    SetBkColor(m_hMemoryDC,RGB(ucR,ucG,ucB));
    SetBkMode(m_hMemoryDC,TRANSPARENT);

    TextOut(m_hMemoryDC,iX,iY,acText,(int)strlen(acText));
}
//----------------------------------------------------------------------------
void WinSoftRenderer::Draw (const unsigned char* aucBuffer)
{
    const int iQuantity = m_iWidth*m_iHeight;
    const unsigned char* pucBuffer = aucBuffer;
    for (int i = 0; i < iQuantity; i++)
    {
        unsigned char ucB = *pucBuffer++;
        unsigned char ucG = *pucBuffer++;
        unsigned char ucR = *pucBuffer++;
        m_auiColorBuffer[i] = (ucB | (ucG << 8) | (ucR << 16) | 0xFF000000);
    }
}
//----------------------------------------------------------------------------
