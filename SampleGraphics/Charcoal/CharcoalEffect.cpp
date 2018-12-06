// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "CharcoalEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,CharcoalEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(CharcoalEffect);

//----------------------------------------------------------------------------
CharcoalEffect::CharcoalEffect (const char* acPaperName,
    float fAmbientIntensity, float fContrastExponent, float fSmudgeFactor,
    float fPaperFactor, Light* pkLight0, Light* pkLight1)
    :
    ShaderEffect(1),
    m_spkLight0(pkLight0),
    m_spkLight1(pkLight1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Charcoal");
    m_kPShader[0] = WM4_NEW PixelShader("Charcoal");

    m_kPShader[0]->SetTextureQuantity(3);
    m_kPShader[0]->SetImageName(0,"Contrast");
    m_kPShader[0]->SetImageName(1,"Random");
    m_kPShader[0]->SetImageName(2,acPaperName);

    m_afAmbientContrast[0] = fAmbientIntensity;
    m_afAmbientContrast[1] = fContrastExponent;
    m_afSmudgePaper[0] = fSmudgeFactor;
    m_afSmudgePaper[1] = fPaperFactor;

    GenerateContrastImage();
    GenerateRandomImage();
}
//----------------------------------------------------------------------------
CharcoalEffect::CharcoalEffect ()
{
}
//----------------------------------------------------------------------------
CharcoalEffect::~CharcoalEffect ()
{
}
//----------------------------------------------------------------------------
void CharcoalEffect::SetGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    ShaderEffect::SetGlobalState(iPass,pkRenderer,bPrimaryEffect);
    pkRenderer->SetLight(0,m_spkLight0);
    pkRenderer->SetLight(1,m_spkLight1);
}
//----------------------------------------------------------------------------
void CharcoalEffect::RestoreGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    ShaderEffect::RestoreGlobalState(iPass,pkRenderer,bPrimaryEffect);
    pkRenderer->SetLight(0,0);
    pkRenderer->SetLight(1,0);
}
//----------------------------------------------------------------------------
void CharcoalEffect::GenerateContrastImage ()
{
    int iWidth = 512, iHeight = 512, iQuantity = 4*iWidth*iHeight;
    unsigned char* aucData = WM4_NEW unsigned char[iQuantity];
    m_spkContrastImage = WM4_NEW Image(Image::IT_RGBA8888,iWidth,iHeight,
        aucData,"Contrast");

    // Create a white image.
    memset(aucData,-1,iQuantity*sizeof(unsigned char));

    // Add black speckles to the image randomly.
    float fContrastExponent = GetContrastExponent();
    float fNoiseDensity = 0.5f;
    int iNumNoiseTexels = (int)(fNoiseDensity*iQuantity);
    for (int i = 0 ; i < iNumNoiseTexels ; i++)
    {
        // Generate x and y texture coordinates randomly between 0 and 1.
        float fX = Mathf::UnitRandom();
        float fY = Mathf::UnitRandom();
        fY = Mathf::Pow(fY,fContrastExponent);
        int iX = (int)(fX*(iWidth - 1.0));
        int iY = (int)(fY*(iHeight - 1.0));
        unsigned char* aucColor = &aucData[4*(iX+iWidth*iY)];
        aucColor[0] = 0;
        aucColor[1] = 0;
        aucColor[2] = 0;
    }
}
//----------------------------------------------------------------------------
void CharcoalEffect::GenerateRandomImage ()
{
    int iWidth = 512, iHeight = 512, iQuantity = 4*iWidth*iHeight;
    unsigned char* aucData = WM4_NEW unsigned char[iQuantity];
    for (int i = 0 ; i < iQuantity; i++)
    {
        aucData[i] = (unsigned char)Mathf::IntervalRandom(0.0f,256.0f);
    }

    m_spkRandomImage = WM4_NEW Image(Image::IT_RGBA8888,iWidth,iHeight,
        aucData,"Random");
}
//----------------------------------------------------------------------------
void CharcoalEffect::OnLoadPrograms (int, Program* pkVProgram,
    Program* pkPProgram)
{
    // vertex program processing
    pkVProgram->GetUC("Constants")->SetDataSource(m_afAmbientContrast);

    // pixel program processing
    pkPProgram->GetUC("Constants")->SetDataSource(m_afSmudgePaper);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* CharcoalEffect::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = ShaderEffect::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkContrastImage)
    {
        pkFound = m_spkContrastImage->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkRandomImage)
    {
        pkFound = m_spkRandomImage->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkLight0)
    {
        pkFound = m_spkLight0->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkLight1)
    {
        pkFound = m_spkLight1->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void CharcoalEffect::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    ShaderEffect::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkContrastImage)
    {
        m_spkContrastImage->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkRandomImage)
    {
        m_spkRandomImage->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkLight0)
    {
        m_spkLight0->GetAllObjectsByName(rkName,rkObjects);
    }

    if (m_spkLight1)
    {
        m_spkLight1->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* CharcoalEffect::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = ShaderEffect::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkContrastImage)
    {
        pkFound = m_spkContrastImage->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkRandomImage)
    {
        pkFound = m_spkRandomImage->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkLight0)
    {
        pkFound = m_spkLight0->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    if (m_spkLight1)
    {
        pkFound = m_spkLight1->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void CharcoalEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afAmbientContrast[0]);
    rkStream.Read(m_afAmbientContrast[1]);
    rkStream.Read(m_afSmudgePaper[0]);
    rkStream.Read(m_afSmudgePaper[1]);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkContrastImage
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkRandomImage
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkLight0
    pkLink->Add(pkObject);
    rkStream.Read(pkObject);  // m_spkLight1
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(CharcoalEffect);
}
//----------------------------------------------------------------------------
void CharcoalEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkContrastImage = (Image*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkRandomImage = (Image*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkLight0 = (Light*)rkStream.GetFromMap(pkLinkID);
    pkLinkID = pkLink->GetLinkID();
    m_spkLight1 = (Light*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool CharcoalEffect::Register (Stream& rkStream) const
{
    if (!ShaderEffect::Register(rkStream))
    {
        return false;
    }

    if (m_spkContrastImage)
    {
        m_spkContrastImage->Register(rkStream);
    }

    if (m_spkRandomImage)
    {
        m_spkRandomImage->Register(rkStream);
    }

    if (m_spkLight0)
    {
        m_spkLight0->Register(rkStream);
    }

    if (m_spkLight1)
    {
        m_spkLight1->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void CharcoalEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(m_afAmbientContrast[0]);
    rkStream.Write(m_afAmbientContrast[1]);
    rkStream.Write(m_afSmudgePaper[0]);
    rkStream.Write(m_afSmudgePaper[1]);

    // link data
    rkStream.Write(m_spkContrastImage);
    rkStream.Write(m_spkRandomImage);
    rkStream.Write(m_spkLight0);
    rkStream.Write(m_spkLight1);

    WM4_END_DEBUG_STREAM_SAVE(CharcoalEffect);
}
//----------------------------------------------------------------------------
int CharcoalEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_afAmbientContrast[0]) +
        sizeof(m_afAmbientContrast[1]) +
        sizeof(m_afSmudgePaper[0]) +
        sizeof(m_afSmudgePaper[1]) +
        sizeof(m_spkContrastImage) +
        sizeof(m_spkRandomImage) +
        sizeof(m_spkLight0) +
        sizeof(m_spkLight1);
}
//----------------------------------------------------------------------------
StringTree* CharcoalEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("ambient intensity =",m_afAmbientContrast[0]));
    pkTree->Append(Format("contrast exponent =",m_afAmbientContrast[1]));
    pkTree->Append(Format("smudge factor =",m_afSmudgePaper[0]));
    pkTree->Append(Format("paper factor =",m_afSmudgePaper[1]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    if (m_spkContrastImage)
    {
        pkTree->Append(m_spkContrastImage->SaveStrings());
    }

    if (m_spkRandomImage)
    {
        pkTree->Append(m_spkRandomImage->SaveStrings());
    }

    if (m_spkLight0)
    {
        pkTree->Append(m_spkLight0->SaveStrings());
    }

    if (m_spkLight1)
    {
        pkTree->Append(m_spkLight1->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
