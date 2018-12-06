// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4Dx9RendererPCH.h"
#include "Wm4Dx9Renderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::OnViewportChange ()
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

    // DirectX defines the full-sized viewport to have origin at the upper
    // left corner of the screen.  Wild Magic uses the OpenGL convention that
    // fB specifies the relative distance from the bottom of the screen.
    // DirectX needs a specification of relative distance from the top of
    // the screen, which is 1-fT.
    D3DVIEWPORT9 kViewport;
    kViewport.X = (DWORD)(fPortL*m_iWidth);
    kViewport.Y = (DWORD)((1.0f - fPortT)*m_iHeight);  // See note above.
    kViewport.Width = (DWORD)((fPortR - fPortL)*m_iWidth);
    kViewport.Height = (DWORD)((fPortT - fPortB)*m_iHeight);
    kViewport.MinZ = 0.0f;
    kViewport.MaxZ = 1.0f;

    ms_hResult = m_pqDevice->SetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDepthRangeChange ()
{
    D3DVIEWPORT9 kViewport;
    ms_hResult = m_pqDevice->GetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));

    if (m_pkCamera)
    {
        m_pkCamera->GetDepthRange(kViewport.MinZ,kViewport.MaxZ);
    }
    else
    {
        kViewport.MinZ = 0.0f;
        kViewport.MaxZ = 1.0f;
    }

    ms_hResult = m_pqDevice->SetViewport(&kViewport);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
