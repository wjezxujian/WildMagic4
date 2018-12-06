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
#include "Wm4Dx9Resources.h"
#include "Wm4ShaderEffect.h"
using namespace Wm4;

DWORD Dx9Renderer::ms_adwTexMinFilter[Texture::MAX_FILTER_TYPES] =
{
    D3DTEXF_POINT,  // Texture::MM_NEAREST
    D3DTEXF_LINEAR, // Texture::MM_LINEAR
    D3DTEXF_POINT,  // Texture::MM_NEAREST_NEAREST
    D3DTEXF_POINT,  // Texture::MM_NEAREST_LINEAR
    D3DTEXF_LINEAR, // Texture::MM_LINEAR_NEAREST
    D3DTEXF_LINEAR, // Texture::MM_LINEAR_LINEAR
};

DWORD Dx9Renderer::ms_adwTexMipFilter[Texture::MAX_FILTER_TYPES] =
{
    D3DTEXF_NONE,   // Texture::MM_NEAREST
    D3DTEXF_NONE,   // Texture::MM_LINEAR
    D3DTEXF_POINT,  // Texture::MM_NEAREST_NEAREST
    D3DTEXF_LINEAR, // Texture::MM_NEAREST_LINEAR
    D3DTEXF_POINT,  // Texture::MM_LINEAR_NEAREST
    D3DTEXF_LINEAR, // Texture::MM_LINEAR_LINEAR
};

DWORD Dx9Renderer::ms_adwTexWrapMode[Texture::MAX_WRAP_TYPES] =
{
    D3DTADDRESS_CLAMP,      // Texture::CLAMP
    D3DTADDRESS_WRAP,       // Texture::REPEAT
    D3DTADDRESS_MIRROR,     // Texture::MIRRORED_REPEAT
    D3DTADDRESS_BORDER,     // Texture::CLAMP_BORDER
    D3DTADDRESS_CLAMP,      // Texture::CLAMP_EDGE
};

//----------------------------------------------------------------------------
void Dx9Renderer::SetVProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    ms_hResult = m_pqDevice->SetVertexShaderConstantF(iBaseRegister,afData,
        iRegisterQuantity);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::SetPProgramConstant (int eCType, int iBaseRegister,
    int iRegisterQuantity, float* afData)
{
    ms_hResult = m_pqDevice->SetPixelShaderConstantF(iBaseRegister,afData,
        iRegisterQuantity);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnEnableVProgram (ResourceIdentifier* pkID)
{
    VProgramID* pkResource = (VProgramID*)pkID;
    ms_hResult = m_pqDevice->SetVertexShader(pkResource->ID);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDisableVProgram (ResourceIdentifier*)
{
    ms_hResult = m_pqDevice->SetVertexShader(0);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnEnablePProgram (ResourceIdentifier* pkID)
{
    PProgramID* pkResource = (PProgramID*)pkID;
    ms_hResult = m_pqDevice->SetPixelShader(pkResource->ID);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDisablePProgram (ResourceIdentifier*)
{
    ms_hResult = m_pqDevice->SetPixelShader(0);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnEnableTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    Texture* pkTexture = pkResource->TextureObject;

    SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
    SamplerInformation::Type eSType = pkSI->GetType();
    int iTextureUnit = pkSI->GetTextureUnit();

    // Set the filter mode.
    Texture::FilterType eFType = pkTexture->GetFilterType();
    if (eFType == Texture::NEAREST)
    {
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_MAGFILTER,D3DTEXF_POINT);
        assert(SUCCEEDED(ms_hResult));
    }
    else
    {
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
        assert(SUCCEEDED(ms_hResult));
    }

    // Set the mipmap mode.
    ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,D3DSAMP_MINFILTER,
        ms_adwTexMinFilter[eFType]);
    assert(SUCCEEDED(ms_hResult));
    ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,D3DSAMP_MIPFILTER,
        ms_adwTexMipFilter[eFType]);
    assert(SUCCEEDED(ms_hResult));

    // Set the border color (for clamp to border).
    const ColorRGBA& rkBorderColor = pkTexture->GetBorderColor();
    ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
        D3DSAMP_BORDERCOLOR,D3DCOLOR_COLORVALUE(rkBorderColor.R(),
        rkBorderColor.G(),rkBorderColor.B(),rkBorderColor.A()));
    assert(SUCCEEDED(ms_hResult));

    switch (eSType)
    {
    case SamplerInformation::SAMPLER_1D:
    {
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSU,ms_adwTexWrapMode[pkTexture->GetWrapType(0)]);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSV,ms_adwTexWrapMode[pkTexture->GetWrapType(0)]);
        assert(SUCCEEDED(ms_hResult));
        break;
    }
    case SamplerInformation::SAMPLER_2D:
    case SamplerInformation::SAMPLER_PROJ:
    case SamplerInformation::SAMPLER_CUBE:
    {
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSU,ms_adwTexWrapMode[pkTexture->GetWrapType(0)]);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSV,ms_adwTexWrapMode[pkTexture->GetWrapType(1)]);
        assert(SUCCEEDED(ms_hResult));
        break;
    }
    case SamplerInformation::SAMPLER_3D:
    {
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSU,ms_adwTexWrapMode[pkTexture->GetWrapType(0)]);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSV,ms_adwTexWrapMode[pkTexture->GetWrapType(1)]);
        assert(SUCCEEDED(ms_hResult));
        ms_hResult = m_pqDevice->SetSamplerState(iTextureUnit,
            D3DSAMP_ADDRESSW,ms_adwTexWrapMode[pkTexture->GetWrapType(2)]);
        assert(SUCCEEDED(ms_hResult));
        break;
    }
    default:
        assert(false);
        break;
    }

    ms_hResult = m_pqDevice->SetTexture(iTextureUnit,pkResource->ID);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDisableTexture (ResourceIdentifier* pkID)
{
    TextureID* pkResource = (TextureID*)pkID;
    Texture* pkTexture = pkResource->TextureObject;

    int iTextureUnit = pkTexture->GetSamplerInformation()->GetTextureUnit();

    ms_hResult = m_pqDevice->SetTextureStageState(iTextureUnit,
        D3DTSS_COLOROP,D3DTOP_DISABLE);
    assert(SUCCEEDED(ms_hResult));

    ms_hResult = m_pqDevice->SetTexture(iTextureUnit,0);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnEnableVBuffer (ResourceIdentifier* pkID)
{
    VBufferID* pkResource = (VBufferID*)pkID;
    ms_hResult = m_pqDevice->SetStreamSource(0,pkResource->ID,0,
        pkResource->VertexSize);
    assert(SUCCEEDED(ms_hResult));
    ms_hResult = m_pqDevice->SetFVF(pkResource->Format);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDisableVBuffer (ResourceIdentifier*)
{
    // Nothing to do.
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnEnableIBuffer (ResourceIdentifier* pkID)
{
    // Bind the current index buffer.
    IBufferID* pkResource = (IBufferID*)pkID;
    ms_hResult = m_pqDevice->SetIndices(pkResource->ID);
    assert(SUCCEEDED(ms_hResult));
}
//----------------------------------------------------------------------------
void Dx9Renderer::OnDisableIBuffer (ResourceIdentifier*)
{
    // Nothing to do.
}
//----------------------------------------------------------------------------
