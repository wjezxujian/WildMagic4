// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4SamplerInformation.h"
using namespace Wm4;

//----------------------------------------------------------------------------
SamplerInformation::SamplerInformation (const std::string& rkName, Type eType,
    int iTextureUnit)
    :
    m_kName(rkName)
{
    m_eType = eType;
    m_iTextureUnit = iTextureUnit;

    switch (m_eType)
    {
    case SAMPLER_1D:
        m_iDimension = 1;
        break;
    case SAMPLER_2D:
        m_iDimension = 2;
        break;
    case SAMPLER_3D:
        m_iDimension = 3;
        break;
    case SAMPLER_CUBE:
        m_iDimension = 2;
        break;
    case SAMPLER_PROJ:
        m_iDimension = 2;
        break;
    default:
        assert(false);
        m_iDimension = 0;
        break;
    }
}
//----------------------------------------------------------------------------
SamplerInformation::~SamplerInformation ()
{
}
//----------------------------------------------------------------------------
