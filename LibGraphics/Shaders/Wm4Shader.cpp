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
#include "Wm4Shader.h"
#include "Wm4ImageCatalog.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Shader,Object);
WM4_IMPLEMENT_ABSTRACT_STREAM(Shader);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Shader,Object);

//----------------------------------------------------------------------------
Shader::Shader ()
{
}
//----------------------------------------------------------------------------
Shader::Shader (const std::string& rkShaderName)
    :
    m_kShaderName(rkShaderName)
{
}
//----------------------------------------------------------------------------
Shader::~Shader ()
{
}
//----------------------------------------------------------------------------
void Shader::SetTextureQuantity (int iQuantity)
{
    m_kTextures.clear();
    m_kTextures.resize(iQuantity);
    for (int i = 0; i < iQuantity; i++)
    {
        m_kTextures[i] = WM4_NEW Texture;
    }

    m_kImageNames.clear();
    m_kImageNames.resize(iQuantity);
}
//----------------------------------------------------------------------------
Texture* Shader::GetTexture (int i)
{
    if (0 <= i && i < (int)m_kTextures.size())
    {
        return m_kTextures[i];
    }
    return 0;
}
//----------------------------------------------------------------------------
Texture* Shader::GetTexture (const std::string& rkName)
{
    if (m_spkProgram)
    {
        for (int i = 0; i < (int)m_kTextures.size(); i++)
        {
            Texture* pkTexture = m_kTextures[i];
            SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
            if (pkSI->GetName() == rkName)
            {
                return pkTexture;
            }
        }
    }
    return 0;
}
//----------------------------------------------------------------------------
const Texture* Shader::GetTexture (int i) const
{
    if (0 <= i && i < (int)m_kTextures.size())
    {
        return m_kTextures[i];
    }
    return 0;
}
//----------------------------------------------------------------------------
const Texture* Shader::GetTexture (const std::string& rkName) const
{
    if (m_spkProgram)
    {
        for (int i = 0; i < (int)m_kTextures.size(); i++)
        {
            Texture* pkTexture = m_kTextures[i];
            SamplerInformation* pkSI = pkTexture->GetSamplerInformation();
            if (pkSI->GetName() == rkName)
            {
                return pkTexture;
            }
        }
    }
    return 0;
}
//----------------------------------------------------------------------------
void Shader::SetImageName (int i, const std::string& rkName)
{
    int iQuantity = (int)m_kImageNames.size();
    if (i >= iQuantity)
    {
        m_kImageNames.resize(i+1);
    }

    m_kImageNames[i] = rkName;
}
//----------------------------------------------------------------------------
const std::string& Shader::GetImageName (int i) const
{
    assert(0 <= i && i < (int)m_kImageNames.size());
    return m_kImageNames[i];
}
//----------------------------------------------------------------------------
void Shader::OnLoadProgram (Program* pkProgram)
{
    assert(!m_spkProgram && pkProgram);
    m_spkProgram = pkProgram;

    // The data sources must be set for the user constants.  Determine how
    // many float channels are needed for the storage.
    int iUCQuantity = m_spkProgram->GetUCQuantity();
    int i, iChannels;
    UserConstant* pkUC;
    for (i = 0, iChannels = 0; i < iUCQuantity; i++)
    {
        pkUC = m_spkProgram->GetUC(i);
        assert(pkUC);
        iChannels += 4*pkUC->GetRegisterQuantity();
    }
    m_kUserData.resize(iChannels);

    // Set the data sources for the user constants.
    for (i = 0, iChannels = 0; i < iUCQuantity; i++)
    {
        pkUC = m_spkProgram->GetUC(i);
        assert(pkUC);
        pkUC->SetDataSource(&m_kUserData[iChannels]);
        iChannels += 4*pkUC->GetRegisterQuantity();
    }

    // Load the images into the textures.  If the image is already in
    // system memory (in the image catalog), it is ready to be used.  If
    // it is not in system memory, an attempt is made to load it from
    // disk storage.  If the image file does not exist on disk, a default
    // magenta image is used.
    int iSIQuantity = m_spkProgram->GetSIQuantity();
    m_kImageNames.resize(iSIQuantity);
    m_kTextures.resize(iSIQuantity);
    for (i = 0; i < iSIQuantity; i++)
    {
        Image* pkImage = ImageCatalog::GetActive()->Find(m_kImageNames[i]);
        assert(pkImage);
        if (!m_kTextures[i])
        {
            m_kTextures[i] = WM4_NEW Texture;
        }
        m_kTextures[i]->SetImage(pkImage);
        m_kTextures[i]->SetSamplerInformation(m_spkProgram->GetSI(i));
    }
}
//----------------------------------------------------------------------------
void Shader::OnReleaseProgram ()
{
    // Destroy the program.  The texture images, if any, will be destroyed
    // by the shader destructor.  If the shader has the last reference to
    // an image, that image will be deleted from the image catalog
    // automatically.
    m_spkProgram = 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Shader::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_kShaderName);

    int iQuantity;
    rkStream.Read(iQuantity);
    m_kImageNames.resize(iQuantity);
    int i;
    for (i = 0; i < iQuantity; i++)
    {
        rkStream.Read(m_kImageNames[i]);
    }

    // link data
    rkStream.Read(iQuantity);
    m_kTextures.resize(iQuantity);
    for (i = 0; i < iQuantity; i++)
    {
        Object* pkObject;
        rkStream.Read(pkObject);  // m_kTextures[i]
        pkLink->Add(pkObject);
    }

    // The data members m_spkProgram and m_kUserData are both set during
    // resource loading at program runtime.

    WM4_END_DEBUG_STREAM_LOAD(Shader);
}
//----------------------------------------------------------------------------
void Shader::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);

    for (int i = 0; i < (int)m_kTextures.size(); i++)
    {
        Object* pkLinkID = pkLink->GetLinkID();
        m_kTextures[i] = (Texture*)rkStream.GetFromMap(pkLinkID);
    }
}
//----------------------------------------------------------------------------
bool Shader::Register (Stream& rkStream) const
{
    if (!Object::Register(rkStream))
    {
        return false;
    }

    for (int i = 0; i < (int)m_kTextures.size(); i++)
    {
        if (m_kTextures[i])
        {
            m_kTextures[i]->Register(rkStream);
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void Shader::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);

    // native data
    rkStream.Write(m_kShaderName);

    int iQuantity = (int)m_kImageNames.size();
    rkStream.Write(iQuantity);
    int i;
    for (i = 0; i < iQuantity; i++)
    {
        rkStream.Write(m_kImageNames[i]);
    }

    // link data
    iQuantity = (int)m_kTextures.size();
    rkStream.Write(iQuantity);
    for (i = 0; i < iQuantity; i++)
    {
        rkStream.Write(m_kTextures[i]);
    }

    // The data members m_spkProgram and m_kUserData are both set during
    // resource loading at program runtime.

    WM4_END_DEBUG_STREAM_SAVE(Shader);
}
//----------------------------------------------------------------------------
int Shader::GetDiskUsed (const StreamVersion& rkVersion) const
{
    int iSize = Object::GetDiskUsed(rkVersion) +
        sizeof(int) + (int)m_kShaderName.length();

    int iQuantity = (int)m_kImageNames.size();
    iSize += sizeof(int);
    int i;
    for (i = 0; i < iQuantity; i++)
    {
        iSize += sizeof(int) + (int)m_kImageNames[i].length();
    }

    iQuantity = (int)m_kTextures.size();
    iSize += sizeof(int) + iQuantity*sizeof(m_kTextures[0]);

    return iSize;
}
//----------------------------------------------------------------------------
StringTree* Shader::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("shader name =",m_kShaderName.c_str()));

    const size_t uiTitleSize = 16;
    char acTitle[uiTitleSize];
    int i;
    for (i = 0; i < (int)m_kImageNames.size(); i++)
    {
        System::Sprintf(acTitle,uiTitleSize,"image[%d] =",i);
        pkTree->Append(Format(acTitle,m_kImageNames[i].c_str()));
    }

    // children
    pkTree->Append(Object::SaveStrings());

    for (i = 0; i < (int)m_kTextures.size(); i++)
    {
        pkTree->Append(m_kTextures[i]->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
