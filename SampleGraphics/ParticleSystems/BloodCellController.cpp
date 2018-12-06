// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BloodCellController.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BloodCellController,ParticleController);
WM4_IMPLEMENT_STREAM(BloodCellController);
WM4_IMPLEMENT_DEFAULT_STREAM(BloodCellController,ParticleController);
WM4_IMPLEMENT_DEFAULT_NAME_ID(BloodCellController,ParticleController);

//----------------------------------------------------------------------------
BloodCellController::BloodCellController ()
{
}
//----------------------------------------------------------------------------
void BloodCellController::UpdatePointMotion (float)
{
    Particles* pkParticle = StaticCast<Particles>(m_pkObject);

    int iLQuantity = pkParticle->Locations->GetQuantity();
    Vector3f* akLocation = pkParticle->Locations->GetData();
    float* afSize = pkParticle->Sizes->GetData();
    for (int i = 0; i < iLQuantity; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            akLocation[i][j] += 0.01f*Mathf::SymmetricRandom();
            if (akLocation[i][j] > 1.0f)
            {
                akLocation[i][j] = 1.0f;
            }
            else if (akLocation[i][j] < -1.0f)
            {
                akLocation[i][j] = -1.0f;
            }
        }

        afSize[i] *= (1.0f + 0.01f*Mathf::SymmetricRandom());
        if (afSize[i] > 0.25f)
        {
            afSize[i] = 0.25f;
        }
    }

    pkParticle->VBuffer->Release();
}
//----------------------------------------------------------------------------
