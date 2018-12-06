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
#include "Wm4Polyline.h"
using namespace Wm4;

//----------------------------------------------------------------------------
void Dx9Renderer::DrawElements ()
{
    // Get the correct active and primitive quantities.
    int iPQuantity, iAQuantity;
    switch (m_pkGeometry->Type)
    {
    case Geometry::GT_TRIMESH:
        iAQuantity = m_pkGeometry->VBuffer->GetVertexQuantity();
        iPQuantity = m_pkGeometry->IBuffer->GetIndexQuantity()/3;
        break;
    case Geometry::GT_POLYLINE_OPEN:
        iAQuantity = StaticCast<Polyline>(m_pkGeometry)->GetActiveQuantity();
        iPQuantity = iAQuantity;
        break;
    case Geometry::GT_POLYLINE_CLOSED:
        iAQuantity = StaticCast<Polyline>(m_pkGeometry)->GetActiveQuantity();
        iPQuantity = iAQuantity + 1;
        break;
    case Geometry::GT_POLYLINE_SEGMENTS:
        iAQuantity = StaticCast<Polyline>(m_pkGeometry)->GetActiveQuantity();
        iPQuantity = iAQuantity / 2;
        break;
    case Geometry::GT_POLYPOINT:
        iAQuantity = StaticCast<Polyline>(m_pkGeometry)->GetActiveQuantity();
        iPQuantity = iAQuantity;
        break;
    default:
        assert(false);
        iAQuantity = 0;
        iPQuantity = 0;
        break;
    }

    ms_hResult = m_pqDevice->DrawIndexedPrimitive(
        ms_aeObjectType[m_pkGeometry->Type],0,0,iAQuantity,0,iPQuantity);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
