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
void Dx9Renderer::Draw (const unsigned char* aucBuffer)
{
    if (!aucBuffer)
    {
        return;
    }

    IDirect3DSurface9* pkBackBuffer = 0;
    ms_hResult = m_pqDevice->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,
        &pkBackBuffer);
    assert( pkBackBuffer );
    assert(SUCCEEDED(ms_hResult));
    if (FAILED(ms_hResult) || !pkBackBuffer)
    {
        return;
    }

    RECT kSrcRect = { 0, 0, m_iWidth-1, m_iHeight-1 };
    ms_hResult = D3DXLoadSurfaceFromMemory(pkBackBuffer,0,0,aucBuffer,
        D3DFMT_R8G8B8,3*m_iWidth,0,&kSrcRect,D3DX_FILTER_NONE,0);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
