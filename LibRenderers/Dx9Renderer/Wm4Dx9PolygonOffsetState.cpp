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
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    // The LineEnabled and PointEnabled members are ignored by the DX9
    // renderer since DX9 does not support polygon offset for those
    // primitives.

    Renderer::SetPolygonOffsetState(pkState);

    if (pkState->FillEnabled)
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS,
            *((DWORD*)&pkState->Scale));
        assert(SUCCEEDED(ms_hResult));

        // TO DO.  The renderer currently always creates a 24-bit depth
        // buffer.  If the precision changes, the adjustment to depth bias
        // must depend on the bits of precision.  The divisor is 2^n for n
        // bits of precision.
        float fBias = pkState->Bias/16777216.0f;
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_DEPTHBIAS,
            *((DWORD*)&fBias));
        assert(SUCCEEDED(ms_hResult));
    }
    else
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS,0);
        assert(SUCCEEDED(ms_hResult));

        ms_hResult = m_pqDevice->SetRenderState(D3DRS_DEPTHBIAS,0);
        assert(SUCCEEDED(ms_hResult));
    }
}
//----------------------------------------------------------------------------
