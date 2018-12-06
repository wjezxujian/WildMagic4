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
using namespace Wm4;

//----------------------------------------------------------------------------
void SoftRenderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    // The LineEnabled and PointEnabled members are ignored by the software
    // renderer.

    Renderer::SetPolygonOffsetState(pkState);

    if (pkState->FillEnabled)
    {
        m_fPolygonOffsetScale = pkState->Scale;

        // TO DO.  The renderer currently always creates a 24-bit depth
        // buffer.  If the precision changes, the adjustment to depth bias
        // must depend on the bits of precision.  The divisor is 2^n for n
        // bits of precision.
        m_fPolygonOffsetBias = pkState->Bias/16777216.0f;
    }
    else
    {
        m_fPolygonOffsetScale = 0.0f;
        m_fPolygonOffsetBias = 0.0f;
    }
}
//----------------------------------------------------------------------------
