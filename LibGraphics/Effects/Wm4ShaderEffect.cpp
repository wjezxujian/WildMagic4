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
#include "Wm4ShaderEffect.h"
#include "Wm4VertexProgramCatalog.h"
#include "Wm4PixelProgramCatalog.h"
#include "Wm4Renderer.h"
#include "Wm4Geometry.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,ShaderEffect,Effect);
WM4_IMPLEMENT_STREAM(ShaderEffect);

//----------------------------------------------------------------------------
ShaderEffect::ShaderEffect (int iPassQuantity)
{
    assert(iPassQuantity > 0);

    SetPassQuantity(iPassQuantity);
}
//----------------------------------------------------------------------------
ShaderEffect::ShaderEffect ()
{
    m_iPassQuantity = 0;
}
//----------------------------------------------------------------------------
ShaderEffect::~ShaderEffect ()
{
}
//----------------------------------------------------------------------------
void ShaderEffect::SetPassQuantity (int iPassQuantity)
{
    assert(iPassQuantity > 0);
    m_iPassQuantity = iPassQuantity;

    m_kVShader.resize(m_iPassQuantity);
    m_kPShader.resize(m_iPassQuantity);
    m_kAlphaState.resize(m_iPassQuantity);
    SetDefaultAlphaState();
}
//----------------------------------------------------------------------------
int ShaderEffect::GetPassQuantity () const
{
    return m_iPassQuantity;
}
//----------------------------------------------------------------------------
AlphaState* ShaderEffect::GetBlending (int iPass)
{
    // A derived class might want to use alpha state for selecting shader
    // programs for doing a single-pass renderering.  The class can resize
    // the alpha state array to contain more items than the number of passes.
    // Thus, the assertion here does not compare iPass to m_iPassQuantity.
    assert(0 <= iPass && iPass < (int)m_kAlphaState.size());
    return m_kAlphaState[iPass];
}
//----------------------------------------------------------------------------
void ShaderEffect::SetGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    assert(0 <= iPass && iPass < m_iPassQuantity && pkRenderer);

    // Enable all passes after the first one to blend with the previous
    // passes.
    if (!bPrimaryEffect || iPass > 0)
    {
        m_kAlphaState[iPass]->BlendEnabled = true;

        AlphaStatePtr spkSave = pkRenderer->GetAlphaState();
        pkRenderer->SetAlphaState(m_kAlphaState[iPass]);
        m_kAlphaState[iPass] = spkSave;
    }
}
//----------------------------------------------------------------------------
void ShaderEffect::RestoreGlobalState (int iPass, Renderer* pkRenderer,
    bool bPrimaryEffect)
{
    assert(0 <= iPass && iPass < m_iPassQuantity && pkRenderer);

    if (!bPrimaryEffect || iPass > 0)
    {
        AlphaStatePtr spkSave = pkRenderer->GetAlphaState();
        pkRenderer->SetAlphaState(m_kAlphaState[iPass]);
        m_kAlphaState[iPass] = spkSave;
    }
}
//----------------------------------------------------------------------------
void ShaderEffect::SetVShader (int iPass, VertexShader* pkVShader)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    m_kVShader[iPass] = pkVShader;
}
//----------------------------------------------------------------------------
VertexShader* ShaderEffect::GetVShader (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass];
}
//----------------------------------------------------------------------------
VertexProgram* ShaderEffect::GetVProgram (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetProgram();
}
//----------------------------------------------------------------------------
const std::string& ShaderEffect::GetVShaderName (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetShaderName();
}
//----------------------------------------------------------------------------
int ShaderEffect::GetVConstantQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    return pkVProgram ? pkVProgram->GetUCQuantity() : 0;
}
//----------------------------------------------------------------------------
UserConstant* ShaderEffect::GetVConstant (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    if (pkVProgram)
    {
        assert(0 <= i && i < pkVProgram->GetUCQuantity());
        return pkVProgram->GetUC(i);
    }
    return 0;
}
//----------------------------------------------------------------------------
UserConstant* ShaderEffect::GetVConstant (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    return pkVProgram ? pkVProgram->GetUC(rkName) : 0;
}
//----------------------------------------------------------------------------
int ShaderEffect::GetVTextureQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTextureQuantity();
}
//----------------------------------------------------------------------------
Texture* ShaderEffect::GetVTexture (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTexture(i);
}
//----------------------------------------------------------------------------
Texture* ShaderEffect::GetVTexture (int iPass, const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetTexture(rkName);
}
//----------------------------------------------------------------------------
void ShaderEffect::SetVImageName (int iPass, int i, const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    m_kVShader[iPass]->SetImageName(i,rkName);
}
//----------------------------------------------------------------------------
const std::string& ShaderEffect::GetVImageName (int iPass, int i) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kVShader[iPass]->GetImageName(i);
}
//----------------------------------------------------------------------------
void ShaderEffect::SetPShader (int iPass, PixelShader* pkPShader)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    m_kPShader[iPass] = pkPShader;
}
//----------------------------------------------------------------------------
PixelShader* ShaderEffect::GetPShader (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass];
}
//----------------------------------------------------------------------------
PixelProgram* ShaderEffect::GetPProgram (int iPass)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetProgram();
}
//----------------------------------------------------------------------------
const std::string& ShaderEffect::GetPShaderName (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetShaderName();
}
//----------------------------------------------------------------------------
int ShaderEffect::GetPConstantQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetUCQuantity() : 0;
}
//----------------------------------------------------------------------------
UserConstant* ShaderEffect::GetPConstant (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    if (pkPProgram)
    {
        assert(0 <= i && i < pkPProgram->GetUCQuantity());
        return pkPProgram->GetUC(i);
    }
    return 0;
}
//----------------------------------------------------------------------------
UserConstant* ShaderEffect::GetPConstant (int iPass,
    const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetUC(rkName) : 0;
}
//----------------------------------------------------------------------------
int ShaderEffect::GetPTextureQuantity (int iPass) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    return pkPProgram ? pkPProgram->GetSIQuantity() : 0;
}
//----------------------------------------------------------------------------
Texture* ShaderEffect::GetPTexture (int iPass, int i)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetTexture(i);
}
//----------------------------------------------------------------------------
Texture* ShaderEffect::GetPTexture (int iPass, const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetTexture(rkName);
}
//----------------------------------------------------------------------------
void ShaderEffect::SetPImageName (int iPass, int i, const std::string& rkName)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    m_kPShader[iPass]->SetImageName(i,rkName);
}
//----------------------------------------------------------------------------
const std::string& ShaderEffect::GetPImageName (int iPass, int i) const
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    return m_kPShader[iPass]->GetImageName(i);
}
//----------------------------------------------------------------------------
void ShaderEffect::SetDefaultAlphaState ()
{
    // Create default alpha states. The Renderer enables this on a multieffect
    // drawing operation.  The first pass uses the default alpha state
    // (SBF_SRC_ALPHA, DBF_ONE_MINUS_SRC_ALPHA).  All other passes use
    // modulation and all are enabled.  These may be overridden by your
    // application code by accessing the state via effect->GetBlending(pass).
    m_kAlphaState[0] = WM4_NEW AlphaState;
    m_kAlphaState[0]->BlendEnabled = true;
    for (int i = 1; i < (int)m_kAlphaState.size(); i++)
    {
        m_kAlphaState[i] = WM4_NEW AlphaState;
        m_kAlphaState[i]->BlendEnabled = true;
        m_kAlphaState[i]->SrcBlend = AlphaState::SBF_DST_COLOR;
        m_kAlphaState[i]->DstBlend = AlphaState::DBF_ZERO;
    }
}
//----------------------------------------------------------------------------
void ShaderEffect::LoadPrograms (int iPass, int iMaxColors, int iMaxTCoords,
    int iMaxVShaderImages, int iMaxPShaderImages)
{
    assert(0 <= iPass && iPass < m_iPassQuantity);
    assert(m_kVShader[iPass] && m_kPShader[iPass]);

    Program* pkVProgram = m_kVShader[iPass]->GetProgram();
    Program* pkPProgram = m_kPShader[iPass]->GetProgram();
    assert((pkVProgram != 0) == (pkPProgram != 0));
    (void)pkPProgram;  // avoid warning in Release build
    if (pkVProgram)
    {
        // The programs have already been loaded.
        return;
    }

    VertexProgramPtr spkVProgram = VertexProgramCatalog::GetActive()->Find(
        m_kVShader[iPass]->GetShaderName());
    assert(spkVProgram);

    PixelProgramPtr spkPProgram = PixelProgramCatalog::GetActive()->Find(
        m_kPShader[iPass]->GetShaderName());
    assert(spkPProgram);

    // Ensure that the output of the vertex program and the input of the
    // pixel program are compatible.  Each vertex program always has a clip
    // position output.  This is not relevant to the compatibility check.
    std::string kDefault("Default");
    const Attributes& rkVOAttr = spkVProgram->GetOutputAttributes();
    const Attributes& rkPIAttr = spkPProgram->GetInputAttributes();
    if (!rkVOAttr.Matches(rkPIAttr,false,true,true,true))
    {
        // The output attributes of the vertex program and the input
        // attributes of the pixel program are incompatible.  Use the default
        // shader objects.
        if (spkVProgram->GetName() != kDefault)
        {
            m_kVShader[iPass] = WM4_NEW VertexShader(kDefault);
            spkVProgram = VertexProgramCatalog::GetActive()->Find(kDefault);
            assert(spkVProgram);
        }

        if (spkPProgram->GetName() != kDefault)
        {
            m_kPShader[iPass] = WM4_NEW PixelShader(kDefault);
            spkPProgram = PixelProgramCatalog::GetActive()->Find(kDefault);
            assert(spkPProgram);
        }
    }

    // Verify the shader program does not require more resources than the
    // renderer can support.
    const Attributes& rkVIAttr = spkVProgram->GetInputAttributes();
    if (rkVIAttr.GetMaxColors()  > iMaxColors
    ||  rkVIAttr.GetMaxTCoords() > iMaxTCoords
    ||  rkVOAttr.GetMaxColors()  > iMaxColors
    ||  rkVOAttr.GetMaxTCoords() > iMaxTCoords
    ||  rkPIAttr.GetMaxColors()  > iMaxColors
    ||  rkPIAttr.GetMaxTCoords() > iMaxTCoords
    ||  spkVProgram->GetSIQuantity() > iMaxVShaderImages
    ||  spkPProgram->GetSIQuantity() > iMaxPShaderImages)
    {
        // The renderer cannot support the requested resources.
        if (spkVProgram->GetName() != kDefault)
        {
            m_kVShader[iPass] = WM4_NEW VertexShader(kDefault);
            spkVProgram = VertexProgramCatalog::GetActive()->Find(kDefault);
            assert(spkVProgram);
        }

        if (spkPProgram->GetName() != kDefault)
        {
            m_kPShader[iPass] = WM4_NEW PixelShader(kDefault);
            spkPProgram = PixelProgramCatalog::GetActive()->Find(kDefault);
            assert(spkPProgram);
        }
    }

    m_kVShader[iPass]->OnLoadProgram(spkVProgram);
    m_kPShader[iPass]->OnLoadProgram(spkPProgram);
    OnLoadPrograms(iPass,spkVProgram,spkPProgram);
}
//----------------------------------------------------------------------------
void ShaderEffect::ReleasePrograms (int iPass)
{
    OnReleasePrograms(iPass,m_kVShader[iPass]->GetProgram(),
        m_kPShader[iPass]->GetProgram());
    m_kVShader[iPass]->OnReleaseProgram();
    m_kPShader[iPass]->OnReleaseProgram();
}
//----------------------------------------------------------------------------
void ShaderEffect::OnLoadPrograms (int, Program*, Program*)
{
    // Stub for derived classes.
}
//----------------------------------------------------------------------------
void ShaderEffect::OnReleasePrograms (int, Program*, Program*)
{
    // Stub for derived classes.
}
//----------------------------------------------------------------------------
void ShaderEffect::LoadResources (Renderer* pkRenderer, Geometry* pkGeometry)
{
    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        // Load the programs to the shader objects.
        LoadPrograms(iPass,pkRenderer->GetMaxColors(),
            pkRenderer->GetMaxTCoords(),pkRenderer->GetMaxVShaderImages(),
            pkRenderer->GetMaxPShaderImages());

        // Load the programs into video memory.
        VertexProgram* pkVProgram = m_kVShader[iPass]->GetProgram();
        pkRenderer->LoadVProgram(pkVProgram);
        pkRenderer->LoadPProgram(m_kPShader[iPass]->GetProgram());

        // Load the textures into video memory.
        const int iPTQuantity = GetPTextureQuantity(iPass);
        for (int i = 0; i < iPTQuantity; i++)
        {
            pkRenderer->LoadTexture(m_kPShader[iPass]->GetTexture(i));
        }

        if (pkGeometry)
        {
            // Load the vertex buffer into video memory.
            const Attributes& rkIAttr = pkVProgram->GetInputAttributes();
            const Attributes& rkOAttr = pkVProgram->GetOutputAttributes();
            pkRenderer->LoadVBuffer(rkIAttr,rkOAttr,pkGeometry->VBuffer);
        }
    }
}
//----------------------------------------------------------------------------
void ShaderEffect::ReleaseResources (Renderer* pkRenderer, Geometry*)
{
    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        // Release the textures from video memory.
        const int iPTQuantity = GetPTextureQuantity(iPass);
        for (int i = 0; i < iPTQuantity; i++)
        {
            pkRenderer->ReleaseTexture(m_kPShader[iPass]->GetTexture(i));
        }

        // Release the programs from video memory.
        pkRenderer->ReleasePProgram(m_kVShader[iPass]->GetProgram());
        pkRenderer->ReleaseVProgram(m_kPShader[iPass]->GetProgram());

        // Release the programs from the shader objects.
        ReleasePrograms(iPass);
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* ShaderEffect::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Effect::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        if (m_kVShader[iPass])
        {
            pkFound = m_kVShader[iPass]->GetObjectByName(rkName);
            if (pkFound)
            {
                return pkFound;
            }
        }

        if (m_kPShader[iPass])
        {
            pkFound = m_kPShader[iPass]->GetObjectByName(rkName);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void ShaderEffect::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Effect::GetAllObjectsByName(rkName,rkObjects);

    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        if (m_kVShader[iPass])
        {
            m_kVShader[iPass]->GetAllObjectsByName(rkName,rkObjects);
        }

        if (m_kPShader[iPass])
        {
            m_kPShader[iPass]->GetAllObjectsByName(rkName,rkObjects);
        }
    }
}
//----------------------------------------------------------------------------
Object* ShaderEffect::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Effect::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        if (m_kVShader[iPass])
        {
            pkFound = m_kVShader[iPass]->GetObjectByID(uiID);
            if (pkFound)
            {
                return pkFound;
            }
        }

        if (m_kPShader[iPass])
        {
            pkFound = m_kPShader[iPass]->GetObjectByID(uiID);
            if (pkFound)
            {
                return pkFound;
            }
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void ShaderEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Effect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_iPassQuantity);
    m_kVShader.resize(m_iPassQuantity);
    m_kPShader.resize(m_iPassQuantity);

    // link data
    Object* pkObject;
    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        rkStream.Read(pkObject);  // m_kVShader[iPass]
        pkLink->Add(pkObject);
        rkStream.Read(pkObject);  // m_kPShader[iPass]
        pkLink->Add(pkObject);
    }

    int iQuantity;
    rkStream.Read(iQuantity);
    m_kAlphaState.resize(iQuantity);

    for (int i = 0; i < iQuantity; i++)
    {
        rkStream.Read(pkObject);  // m_kAlphaState[i]
        pkLink->Add(pkObject);
    }

    WM4_END_DEBUG_STREAM_LOAD(ShaderEffect);
}
//----------------------------------------------------------------------------
void ShaderEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Effect::Link(rkStream,pkLink);

    Object* pkLinkID;
    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        pkLinkID = pkLink->GetLinkID();
        m_kVShader[iPass] = (VertexShader*)rkStream.GetFromMap(pkLinkID);
        pkLinkID = pkLink->GetLinkID();
        m_kPShader[iPass] = (PixelShader*)rkStream.GetFromMap(pkLinkID);
    }

    int iQuantity = (int)m_kAlphaState.size();
    for (int i = 0; i < iQuantity; i++)
    {
        pkLinkID = pkLink->GetLinkID();
        m_kAlphaState[i] = (AlphaState*)rkStream.GetFromMap(pkLinkID);
    }
}
//----------------------------------------------------------------------------
bool ShaderEffect::Register (Stream& rkStream) const
{
    if (!Effect::Register(rkStream))
    {
        return false;
    }

    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        if (m_kVShader[iPass])
        {
            m_kVShader[iPass]->Register(rkStream);
        }

        if (m_kPShader[iPass])
        {
            m_kPShader[iPass]->Register(rkStream);
        }
    }

    for (int i = 0; i < (int)m_kAlphaState.size(); i++)
    {
        if (m_kAlphaState[i])
        {
            m_kAlphaState[i]->Register(rkStream);
        }
    }

    return true;
}
//----------------------------------------------------------------------------
void ShaderEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Effect::Save(rkStream);

    // native data
    rkStream.Write(m_iPassQuantity);

    // link data
    for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
    {
        rkStream.Write(m_kVShader[iPass]);
        rkStream.Write(m_kPShader[iPass]);
    }

    int iQuantity = (int)m_kAlphaState.size();
    rkStream.Write(iQuantity);
    for (int i = 0; i < iQuantity; i++)
    {
        rkStream.Write(m_kAlphaState[i]);
    }

    WM4_END_DEBUG_STREAM_SAVE(ShaderEffect);
}
//----------------------------------------------------------------------------
int ShaderEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Effect::GetDiskUsed(rkVersion) +
        sizeof(m_iPassQuantity) +
        m_iPassQuantity*sizeof(m_kVShader[0]) +
        m_iPassQuantity*sizeof(m_kPShader[0]) +
        sizeof(int) +
        ((int)m_kAlphaState.size())*sizeof(m_kAlphaState[0]);
}
//----------------------------------------------------------------------------
StringTree* ShaderEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("pass quantity =",m_iPassQuantity));

    // children
    pkTree->Append(Effect::SaveStrings());

    if (m_iPassQuantity > 0)
    {
        StringTree* pkCTree = WM4_NEW StringTree;
        pkCTree->Append(Format("shaders"));
        for (int iPass = 0; iPass < m_iPassQuantity; iPass++)
        {
            pkCTree->Append(m_kVShader[iPass]->SaveStrings());
            pkCTree->Append(m_kPShader[iPass]->SaveStrings());
        }
        pkTree->Append(pkCTree);
    }

    int iQuantity = (int)m_kAlphaState.size();
    if (iQuantity > 0)
    {
        StringTree* pkCTree = WM4_NEW StringTree;
        pkCTree->Append(Format("blending states"));
        for (int i = 0; i < iQuantity; i++)
        {
            pkCTree->Append(m_kAlphaState[i]->SaveStrings());
        }
        pkTree->Append(pkCTree);
    }

    return pkTree;
}
//----------------------------------------------------------------------------
