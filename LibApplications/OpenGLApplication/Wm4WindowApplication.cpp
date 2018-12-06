// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4ApplicationPCH.h"
#include "Wm4WindowApplication.h"
using namespace Wm4;

//----------------------------------------------------------------------------
WindowApplication::WindowApplication (const char* acWindowTitle,
    int iXPosition, int iYPosition, int iWidth, int iHeight,
    const ColorRGBA& rkBackgroundColor)
    :
    m_acWindowTitle(acWindowTitle),
    m_iXPosition(iXPosition),
    m_iYPosition(iYPosition),
    m_iWidth(iWidth),
    m_iHeight(iHeight),
    m_kBackgroundColor(rkBackgroundColor)
{
    m_iWindowID = 0;
    m_pkRenderer = 0;

    // Default buffer parameters.  These may be overridden by the derived
    // class constructor.  Current hardware seems to pack a 24-bit depth
    // buffer and 8-bit stencil buffer into a 32-bit buffer, so I suggest
    // not overriding these.  Perhaps the only one you should is the
    // multisampling value.
    m_eFormat = FrameBuffer::FT_FORMAT_RGBA;
    m_eDepth = FrameBuffer::DT_DEPTH_24;
    m_eStencil = FrameBuffer::ST_STENCIL_8;
    m_eBuffering = FrameBuffer::BT_BUFFERED_DOUBLE;
    m_eMultisampling = FrameBuffer::MT_SAMPLING_NONE;
}
//----------------------------------------------------------------------------
WindowApplication::~WindowApplication ()
{
}
//----------------------------------------------------------------------------
int WindowApplication::Run (int iQuantity, char** apcArgument)
{
    WindowApplication* pkTheApp = (WindowApplication*)TheApplication;
    return pkTheApp->Main(iQuantity,apcArgument);
}
//----------------------------------------------------------------------------
bool WindowApplication::OnInitialize ()
{
    m_pkRenderer->SetBackgroundColor(m_kBackgroundColor);

    // Notify the catalogs that the renderer has been created.
    assert(VertexProgramCatalog::GetActive());
    VertexProgramCatalog::GetActive()->SetInformation(
        m_pkRenderer->GetExtension(),m_pkRenderer->GetCommentCharacter());

    assert(PixelProgramCatalog::GetActive());
    PixelProgramCatalog::GetActive()->SetInformation(
        m_pkRenderer->GetExtension(),m_pkRenderer->GetCommentCharacter());

    return true;
}
//----------------------------------------------------------------------------
void WindowApplication::OnTerminate ()
{
    // Notify the catalogs that the renderer is going away, so it is okay to
    // delete the default programs.
    assert(VertexProgramCatalog::GetActive());
    VertexProgramCatalog::GetActive()->SetInformation("",0);

    assert(PixelProgramCatalog::GetActive());
    PixelProgramCatalog::GetActive()->SetInformation("",0);

    WM4_DELETE m_pkRenderer;
    m_pkRenderer = 0;
}
//----------------------------------------------------------------------------
void WindowApplication::OnMove (int iX, int iY)
{
    m_iXPosition = iX;
    m_iYPosition = iY;
}
//----------------------------------------------------------------------------
void WindowApplication::OnResize (int iWidth, int iHeight)
{
    if (iWidth > 0 && iHeight > 0)
    {
        if (m_pkRenderer)
        {
            m_pkRenderer->Resize(iWidth,iHeight);
        }

        m_iWidth = iWidth;
        m_iHeight = iHeight;
    }
}
//----------------------------------------------------------------------------
