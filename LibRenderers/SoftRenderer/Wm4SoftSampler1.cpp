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
#include "Wm4SoftSampler1.h"
using namespace Wm4;

WM4_IMPLEMENT_INITIALIZE(SoftSampler1);

//----------------------------------------------------------------------------
void SoftSampler1::Initialize ()
{
    ms_aoCreator[SamplerInformation::SAMPLER_1D] = &SoftSampler1::Create1;
}
//----------------------------------------------------------------------------
SoftSampler* SoftSampler1::Create1 (const Texture* pkTexture)
{
    return WM4_NEW SoftSampler1(pkTexture);
}
//----------------------------------------------------------------------------
SoftSampler1::SoftSampler1 (const Texture* pkTexture)
    :
    SoftSampler(pkTexture)
{
    const Image* pkImage = m_pkTexture->GetImage();
    assert(m_pkTexture->GetImage()->GetDimension() == 1);
    m_akCurrImage = m_aakImage[0];
    m_iCurrXBound = pkImage->GetBound(0);

    Texture::FilterType eFType = m_pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST || eFType == Texture::LINEAR)
    {
        m_iLevels = 1;
        m_aiXBound = WM4_NEW int[1];
        m_aiXBound[0] = m_iCurrXBound;
    }
    else
    {
        CreateMipmaps();
    }
}
//----------------------------------------------------------------------------
SoftSampler1::~SoftSampler1 ()
{
    WM4_DELETE[] m_aiXBound;
}
//----------------------------------------------------------------------------
void SoftSampler1::Recreate (const ColorRGBA* akCImage)
{
    SoftSampler::Recreate(akCImage);

    const Image* pkImage = m_pkTexture->GetImage();
    m_akCurrImage = m_aakImage[0];
    m_iCurrXBound = pkImage->GetBound(0);

    Texture::FilterType eFType = m_pkTexture->GetFilterType();
    if (eFType != Texture::NEAREST && eFType != Texture::LINEAR)
    {
        RecreateMipmaps();
    }
}
//----------------------------------------------------------------------------
void SoftSampler1::ComputeMipmapParameters (const int aiX[3],
    const int aiY[3], const float* aafVertex[3], const Attributes& rkAttr)
{
    Texture::FilterType eFType = m_pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST || eFType == Texture::LINEAR)
    {
        m_akCurrImage = m_aakImage[0];
        m_iCurrXBound = m_aiXBound[0];
        return;
    }

    SoftSampler::ComputeMipmapParameters(aiX,aiY,aafVertex,rkAttr);

    int iUnit = m_pkTexture->GetSamplerInformation()->GetTextureUnit();
    int iOffset = rkAttr.GetTOffset(iUnit);
    float fU0 = aafVertex[0][iOffset];
    float fU1 = aafVertex[1][iOffset];
    float fU2 = aafVertex[2][iOffset];
    m_fA = m_aiXBound[0]*(m_fAMul0*fU0 + m_fAMul1*fU1 + m_fAMul2*fU2);
    m_fB = m_aiXBound[0]*(m_fBMul0*fU0 + m_fBMul1*fU1 + m_fBMul2*fU2);
    m_fC = m_aiXBound[0]*(m_fCMul0*fU0 + m_fCMul1*fU1 + m_fCMul2*fU2);
    m_fAEmBD = m_fA*m_fE - m_fB*m_fD;
    m_fAFmCD = m_fA*m_fF - m_fC*m_fD;
    m_fBFmCE = m_fB*m_fF - m_fC*m_fE;
}
//----------------------------------------------------------------------------
void SoftSampler1::DisallowMipmapping ()
{
    m_bAllowMipmapping = false;
    m_akCurrImage = m_aakImage[0];
    m_iCurrXBound = m_aiXBound[0];
}
//----------------------------------------------------------------------------
void SoftSampler1::CurrentPixel (int iX, int iY)
{
    float fDenom = m_fD*iX + m_fE*iY + m_fF;
    float fInvDenomSqr = 1.0f/(fDenom*fDenom);
    float fDuDx = (+m_fAEmBD*iY + m_fAFmCD)*fInvDenomSqr;
    float fDuDy = (-m_fAEmBD*iX + m_fBFmCE)*fInvDenomSqr;
    float fArg = fDuDx*fDuDx + fDuDy*fDuDy;
    if (fArg > 1.0f)
    {
        m_fCurrLevel = 0.5f*Mathf::Log2(fArg);
    }
    else
    {
        m_fCurrLevel = 0.0f;
    }

    ClampLevels();

    Texture::FilterType eFType = m_pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST_NEAREST
    ||  eFType == Texture::LINEAR_NEAREST)
    {
        m_akCurrImage = m_aakImage[m_iLevel0];
        m_iCurrXBound = m_aiXBound[m_iLevel0];
    }
    else
    {
        m_iXBound0 = m_aiXBound[m_iLevel0];
        m_iXBound1 = m_aiXBound[m_iLevel1];
    }
}
//----------------------------------------------------------------------------
void SoftSampler1::CreateMipmaps ()
{
    const Image* pkImage = m_pkTexture->GetImage();
    int iLXB = (int)Log2OfPowerOfTwo((unsigned int)pkImage->GetBound(0));
    m_iLevels = iLXB + 1;
    m_aiXBound = WM4_NEW int[m_iLevels];
    m_aiXBound[0] = pkImage->GetBound(0);
    RecreateMipmaps();
}
//----------------------------------------------------------------------------
void SoftSampler1::RecreateMipmaps ()
{
    int iXBD2 = (m_aiXBound[0] >> 1);
    for (int i = 1; i < m_iLevels; i++)
    {
        RecreateMipmap1(i,iXBD2);
        iXBD2 >>= 1;
    }
}
//----------------------------------------------------------------------------
ColorRGBA SoftSampler1::operator() (const float* afCoord)
{
    float fXIm;
    ColorRGBA kColor;

    Texture::FilterType eFType = m_pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST || eFType == Texture::NEAREST_NEAREST)
    {
        fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
        kColor = GetNearestColor(fXIm);
        return kColor;
    }

    if (eFType == Texture::LINEAR || eFType == Texture::LINEAR_NEAREST)
    {
        fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
        kColor = GetLinearColor(fXIm);
        return kColor;
    }

    if (m_bAllowMipmapping)
    {
        ColorRGBA kC0, kC1;

        if (eFType == Texture::NEAREST_LINEAR)
        {
            m_akCurrImage = m_akImage0;
            m_iCurrXBound = m_iXBound0;
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kC0 = GetNearestColor(fXIm);
            m_akCurrImage = m_akImage1;
            m_iCurrXBound = m_iXBound1;
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kC1 = GetNearestColor(fXIm);
            kColor = kC0 + m_fDL*(kC1 - kC0);
            return kColor;
        }

        if (eFType == Texture::LINEAR_LINEAR)
        {
            m_akCurrImage = m_akImage0;
            m_iCurrXBound = m_iXBound0;
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kC0 = GetLinearColor(fXIm);
            m_akCurrImage = m_akImage1;
            m_iCurrXBound = m_iXBound1;
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kC1 = GetLinearColor(fXIm);
            kColor = kC0 + m_fDL*(kC1 - kC0);
            return kColor;
        }
    }
    else
    {
        if (eFType == Texture::NEAREST_LINEAR)
        {
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kColor = GetNearestColor(fXIm);
            return kColor;
        }

        if (eFType == Texture::LINEAR_LINEAR)
        {
            fXIm = GetImageCoordinate(0,afCoord[0],m_iCurrXBound);
            kColor = GetLinearColor(fXIm);
            return kColor;
        }
    }

    assert(false);
    return ColorRGBA::BLACK;
}
//----------------------------------------------------------------------------
ColorRGBA SoftSampler1::GetNearestColor (float fXIm) const
{
    int iX = (int)(fXIm + 0.5f);
    return m_akCurrImage[iX];
}
//----------------------------------------------------------------------------
ColorRGBA SoftSampler1::GetLinearColor (float fXIm) const
{
    float fX0 = Mathf::Floor(fXIm);
    float fX1 = Mathf::Ceil(fXIm);
    float fDX = fXIm - fX0;
    int iX0 = (int)fX0;
    int iX1 = (int)fX1;

    if (m_pkTexture->GetWrapType(0) == Texture::REPEAT)
    {
        if (iX0 < 0)
        {
            iX0 = m_iCurrXBound - 1;
        }
        if (iX1 >= m_iCurrXBound)
        {
            iX1 = 0;
        }
    }

    const ColorRGBA& rkBorder = m_pkTexture->GetBorderColor();
    ColorRGBA kC0 = (iX0 >= 0 ? m_akCurrImage[iX0] : rkBorder);
    ColorRGBA kC1 = (iX1 < m_iCurrXBound ? m_akCurrImage[iX1] : rkBorder);
    ColorRGBA kC = kC0 + fDX*(kC1 - kC0);
    return kC;
}
//----------------------------------------------------------------------------
