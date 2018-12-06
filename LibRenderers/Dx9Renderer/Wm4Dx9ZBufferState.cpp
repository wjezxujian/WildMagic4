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

DWORD Dx9Renderer::ms_adwZBufferCompare[ZBufferState::CF_QUANTITY] = 
{
    D3DCMP_NEVER,           // ZBufferState::CF_NEVER
    D3DCMP_LESS,            // ZBufferState::CF_LESS
    D3DCMP_EQUAL,           // ZBufferState::CF_EQUAL
    D3DCMP_LESSEQUAL,       // ZBufferState::CF_LEQUAL
    D3DCMP_GREATER,         // ZBufferState::CF_GREATER
    D3DCMP_NOTEQUAL,        // ZBufferState::CF_NOTEQUAL
    D3DCMP_GREATEREQUAL,    // ZBufferState::CF_GEQUAL
    D3DCMP_ALWAYS,          // ZBufferState::CF_ALWAYS
};

//----------------------------------------------------------------------------
void Dx9Renderer::SetZBufferState (ZBufferState* pkState)
{
    Renderer::SetZBufferState(pkState);

    if (pkState->Enabled)
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_ZFUNC,
            ms_adwZBufferCompare[pkState->Compare]);
        assert(SUCCEEDED(ms_hResult));
    }
    else
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_ZFUNC,D3DCMP_ALWAYS);
        assert(SUCCEEDED(ms_hResult));
    }

    if (pkState->Writable)
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_ZWRITEENABLE,TRUE);
        assert(SUCCEEDED(ms_hResult));
    }
    else
    {
        ms_hResult = m_pqDevice->SetRenderState(D3DRS_ZWRITEENABLE,FALSE);
        assert(SUCCEEDED(ms_hResult));
    }
}
//----------------------------------------------------------------------------
