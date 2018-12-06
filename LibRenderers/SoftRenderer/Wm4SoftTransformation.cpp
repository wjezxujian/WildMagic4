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
#include "Wm4SoftRenderer.h"
#include "Wm4Camera.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::OnViewportChange ()
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

    float fHalfWidth = 0.5f*m_iWidth;
    float fHalfHeight = 0.5f*m_iHeight;
    m_fXCoeff0 = fHalfWidth*(fPortR + fPortL);
    m_fXCoeff1 = fHalfWidth*(fPortR - fPortL);
    m_fYCoeff0 = fHalfHeight*(2.0f - fPortT - fPortB);
    m_fYCoeff1 = fHalfHeight*(fPortB - fPortT);
}
//----------------------------------------------------------------------------
void SoftRenderer::OnDepthRangeChange ()
{
    if (m_pkCamera)
    {
        m_pkCamera->GetDepthRange(m_fMinDepth,m_fMaxDepth);
        if (m_fMinDepth < 0.0f)
        {
            m_fMinDepth = 0.0f;
        }
        else if (m_fMinDepth > 1.0f)
        {
            m_fMinDepth = 1.0f;
        }

        if (m_fMaxDepth < 0.0f)
        {
            m_fMaxDepth = 0.0f;
        }
        else if (m_fMaxDepth > 1.0f)
        {
            m_fMaxDepth = 1.0f;
        }
    }
    else
    {
        m_fMinDepth = 0.0f;
        m_fMaxDepth = 1.0f;
    }

    m_fRangeDepth = m_fMaxDepth - m_fMinDepth;
}
//----------------------------------------------------------------------------
