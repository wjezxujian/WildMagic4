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

DWORD Dx9Renderer::ms_adwCullType[CullState::FT_QUANTITY] = 
{
    D3DCULL_CCW,  // CullState::FT_CCW (front CCW -> cull backface CCW in DX)
    D3DCULL_CW,   // CullState::FT_CW  (front CW -> cull backface CW in DX)
};

//----------------------------------------------------------------------------
void Dx9Renderer::SetCullState (CullState* pkState)
{
    Renderer::SetCullState(pkState);

    if (pkState->Enabled)
    {
        if (m_bReverseCullFace)
        {
            if (ms_adwCullType[pkState->CullFace] == D3DCULL_CW)
            {
                ms_hResult = m_pqDevice->SetRenderState(D3DRS_CULLMODE,
                    D3DCULL_CCW);
                assert(SUCCEEDED(ms_hResult));
            }
            else
            {
                ms_hResult = m_pqDevice->SetRenderState(D3DRS_CULLMODE,
                    D3DCULL_CW);
                assert(SUCCEEDED(ms_hResult));
            }
        } 
        else
        {
            ms_hResult = m_pqDevice->SetRenderState(D3DRS_CULLMODE,
                ms_adwCullType[pkState->CullFace]);
            assert(SUCCEEDED(ms_hResult));
        }
    }
    else
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);
        assert(SUCCEEDED(ms_hResult));
    }
}
//----------------------------------------------------------------------------
