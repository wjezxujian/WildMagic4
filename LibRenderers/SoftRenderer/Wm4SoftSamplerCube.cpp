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
#include "Wm4SoftSamplerCube.h"
using namespace Wm4;

WM4_IMPLEMENT_INITIALIZE(SoftSamplerCube);

//----------------------------------------------------------------------------
void SoftSamplerCube::Initialize ()
{
    ms_aoCreator[SamplerInformation::SAMPLER_CUBE] =
        &SoftSamplerCube::CreateCube;
}
//----------------------------------------------------------------------------
SoftSampler* SoftSamplerCube::CreateCube (const Texture* pkTexture)
{
    return WM4_NEW SoftSamplerCube(pkTexture);
}
//----------------------------------------------------------------------------
SoftSamplerCube::SoftSamplerCube (const Texture* pkTexture)
    :
    SoftSampler(pkTexture)
{
    const Image* pkImage = m_pkTexture->GetImage();
    assert(pkImage->GetFormat() == Image::IT_CUBE_RGB888);

    // The cube sampler creates six Image objects, six managing TextureN
    // objects, and six SoftSampler2 objects.
    unsigned char* pucData = pkImage->GetData();
    int iByteQuantity = 3*pkImage->GetQuantity();

    const size_t uiNumberSize = 4;
    char acNumber[uiNumberSize];

    for (int i = 0; i < 6; i++, pucData += iByteQuantity)
    {
        unsigned char* aucFaceData = WM4_NEW unsigned char[iByteQuantity];
        System::Memcpy(aucFaceData,iByteQuantity,pucData,iByteQuantity);

        System::Sprintf(acNumber,uiNumberSize,"%d",i);
        std::string kFaceName = std::string(pkImage->GetName()) +
            std::string("_face") + std::string(acNumber);

        Image* pkFace = WM4_NEW Image(Image::IT_RGB888,pkImage->GetBound(0),
            pkImage->GetBound(1),aucFaceData,kFaceName.c_str());

        m_apkTexture[i] = WM4_NEW Texture(pkFace,
            (SamplerInformation*)pkTexture->GetSamplerInformation());

        m_apkTexture[i]->SetFilterType(pkTexture->GetFilterType());
        m_apkSampler[i] = WM4_NEW SoftSampler2(m_apkTexture[i]);
    }
}
//----------------------------------------------------------------------------
SoftSamplerCube::~SoftSamplerCube ()
{
    for (int i = 0; i < 6; i++)
    {
        WM4_DELETE m_apkTexture[i];
        WM4_DELETE m_apkSampler[i];
    }
}
//----------------------------------------------------------------------------
void SoftSamplerCube::Recreate (const ColorRGBA* akCImage)
{
    for (int i = 0; i < 6; i++)
    {
        m_apkSampler[i]->Recreate(akCImage);
    }
}
//----------------------------------------------------------------------------
void SoftSamplerCube::ComputeMipmapParameters (const int aiX[3],
    const int aiY[3], const float* aafVertex[3], const Attributes& rkAttr)
{
    for (int i = 0; i < 6; i++)
    {
        m_apkSampler[i]->ComputeMipmapParameters(aiX,aiY,aafVertex,rkAttr);
    }
}
//----------------------------------------------------------------------------
void SoftSamplerCube::DisallowMipmapping ()
{
    for (int i = 0; i < 6; i++)
    {
        m_apkSampler[i]->DisallowMipmapping();
    }
}
//----------------------------------------------------------------------------
void SoftSamplerCube::CurrentPixel (int iX, int iY)
{
    for (int i = 0; i < 6; i++)
    {
        m_apkSampler[i]->CurrentPixel(iX,iY);
    }
}
//----------------------------------------------------------------------------
ColorRGBA SoftSamplerCube::operator() (const float* afCoord)
{
    float fX = afCoord[0], fY = afCoord[1], fZ = afCoord[2];
    float fXA = Mathf::FAbs(fX), fYA = Mathf::FAbs(fY), fZA = Mathf::FAbs(fZ);

    float fMax = fXA;
    int iFace = (fX > 0.0f ? 0 : 1);
    if (fYA > fMax)
    {
        fMax = fYA;
        iFace = (fY > 0.0f ? 2 : 3);
    }
    if (fZA > fMax)
    {
        fMax = fZA;
        iFace = (fZ > 0.0f ? 4 : 5);
    }

    float fInvMax = 1.0f/fMax;

    float afFaceCoord[2];
    switch (iFace)
    {
    case 0:  // +x face, left-handed planar coordinates (-z,-y)
        fY *= fInvMax;
        fZ *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f - fZ);
        afFaceCoord[1] = 0.5f*(1.0f - fY);
        break;
    case 1:  // -x face, left-handed planar coordinates (z,-y)
        fY *= fInvMax;
        fZ *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f + fZ);
        afFaceCoord[1] = 0.5f*(1.0f - fY);
        break;
    case 2:  // +y face, left-handed planar coordinates (x,z)
        fX *= fInvMax;
        fZ *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f + fX);
        afFaceCoord[1] = 0.5f*(1.0f + fZ);
        break;
    case 3:  // -y face, left-handed planar coordinates (x,-z)
        fX *= fInvMax;
        fZ *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f + fX);
        afFaceCoord[1] = 0.5f*(1.0f - fZ);
        break;
    case 4:  // +z face, left-handed planar coordinates (x,-y)
        fX *= fInvMax;
        fY *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f + fX);
        afFaceCoord[1] = 0.5f*(1.0f - fY);
        break;
    case 5:  // -z face, left-handed planar coordinates (-x,-y)
        fX *= fInvMax;
        fY *= fInvMax;
        afFaceCoord[0] = 0.5f*(1.0f - fX);
        afFaceCoord[1] = 0.5f*(1.0f - fY);
        break;
    default:
        assert(false);
        break;
    }

    return (*m_apkSampler[iFace])(afFaceCoord);
}
//----------------------------------------------------------------------------
