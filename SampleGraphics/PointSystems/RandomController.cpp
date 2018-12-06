// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "RandomController.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,RandomController,PointController);
WM4_IMPLEMENT_STREAM(RandomController);
WM4_IMPLEMENT_DEFAULT_STREAM(RandomController,PointController);
WM4_IMPLEMENT_DEFAULT_NAME_ID(RandomController,PointController);

//----------------------------------------------------------------------------
RandomController::RandomController ()
{
}
//----------------------------------------------------------------------------
void RandomController::UpdatePointMotion (float)
{
    Polypoint* pkPoints = StaticCast<Polypoint>(m_pkObject);

    VertexBuffer* pkVB = pkPoints->VBuffer;
    int iVQuantity = pkVB->GetVertexQuantity();
    for (int i = 0; i < iVQuantity; i++)
    {
        float* afPos = pkVB->PositionTuple(i);
        for (int j = 0; j < 3; j++)
        {
            afPos[j] += 0.01f*Mathf::SymmetricRandom();
            if (afPos[j] > 1.0f)
            {
                afPos[j] = 1.0f;
            }
            else if (afPos[j] < -1.0f)
            {
                afPos[j] = -1.0f;
            }
        }
    }

    pkVB->Release();
}
//----------------------------------------------------------------------------
