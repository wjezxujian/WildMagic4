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
#include "Wm4Program.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Program,Object);
WM4_IMPLEMENT_STREAM(Program);
WM4_IMPLEMENT_DEFAULT_STREAM(Program,Object);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Program,Object);

const std::string Program::ms_kFloatStr("float");
const std::string Program::ms_kFloat2Str("float2");
const std::string Program::ms_kFloat3Str("float3");
const std::string Program::ms_kFloat4Str("float4");
const std::string Program::ms_kFloat4x4Str("float4x4");
const std::string Program::ms_kSampler1DStr("sampler1D");
const std::string Program::ms_kSampler2DStr("sampler2D");
const std::string Program::ms_kSampler3DStr("sampler3D");
const std::string Program::ms_kSamplerCubeStr("samplerCUBE");
const std::string Program::ms_kSamplerProjStr("sampler2DSHADOW");
const std::string Program::ms_kPositionStr("POSITION");
const std::string Program::ms_kNormalStr("NORMAL");
const std::string Program::ms_kColorStr("COLOR");
const std::string Program::ms_kColor0Str("COLOR0");
const std::string Program::ms_kColor1Str("COLOR1");
const std::string Program::ms_kTexCoordStr("TEXCOORD");
const std::string Program::ms_kInStr("in");
const std::string Program::ms_kOutStr("in");
const std::string Program::ms_kEOL("\n");

//----------------------------------------------------------------------------
bool Program::Load (const std::string& rkFilename, char cCommentChar,
    Program* pkProgram)
{
    const char* acDecorated = System::GetPath(rkFilename.c_str(),
        System::SM_READ);
    if (!acDecorated)
    {
        return false;
    }

    std::ifstream kIStr(acDecorated);
    if (!kIStr)
    {
        return false;
    }

    std::string& rkProgramText = pkProgram->m_kProgramText;
    Attributes& rkIAttr = pkProgram->m_kInputAttributes;
    Attributes& rkOAttr = pkProgram->m_kOutputAttributes;
    std::vector<RendererConstant>& rkRCs = pkProgram->m_kRendererConstants;
    std::vector<NumericalConstant>& rkNCs = pkProgram->m_kNumericalConstants;
    std::vector<UserConstant>& rkUCs = pkProgram->m_kUserConstants;
    std::vector<SamplerInformation>& rkSIs = pkProgram->m_kSamplerInformation;

    std::string kLine, kToken, kVarType, kVarName, kVarIO, kVarSemantic;
    std::string kRegister, kData;
    std::string::size_type uiBegin, uiEnd, uiSave;
    int iNumFloats, iUnit, iBaseRegister, iRegisterQuantity;
    SamplerInformation::Type eSType;
    RendererConstant::Type eRCType;

    while (!kIStr.eof())
    {
#if defined(WM4_USING_VC6) || defined(WM4_USING_VC70)
        const int iBufferSize = 1024;
        char acBuffer[iBufferSize];
        kIStr.getline(acBuffer,iBufferSize);
        kLine = std::string(acBuffer);
#else
        getline(kIStr,kLine);

        // The *.sft.wmsp files were created on a Windows machine.  The
        // newline consists of a carriage return (13) and a line feed (10).
        // When these files are loaded on Linux machines, the newline is just
        // a line feed, which is stripped off the end of kLine.  The carriage
        // return remains, so it must also be stripped off.
        if (kLine.length() > 0 && (13 == (int)kLine[kLine.length()-1]))
        {
            kLine.resize(kLine.length()-1);
        }
#endif

        // The information needed by Program is contained in the shader
        // program comment lines.  All other lines are assumed to be needed
        // by the graphics API.
        if (kLine[0] != cCommentChar)
        {
            rkProgramText += kLine + ms_kEOL;
            continue;
        }

        uiBegin = kLine.find("var",1);
        if (uiBegin != std::string::npos)
        {
            // Skip over "var".
            uiBegin += 3;

            // Skip over white space.
            uiBegin = kLine.find_first_not_of(" ",uiBegin);
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }

            // Get the variable's data type.
            iNumFloats = 0;
            eSType = SamplerInformation::MAX_SAMPLER_TYPES;
            uiEnd = kLine.find(" ",uiBegin);
            kVarType = kLine.substr(uiBegin,uiEnd-uiBegin);
            if (kVarType == ms_kFloatStr)
            {
                iNumFloats = 1;
            }
            else if (kVarType == ms_kFloat2Str)
            {
                iNumFloats = 2;
            }
            else if (kVarType == ms_kFloat3Str)
            {
                iNumFloats = 3;
            }
            else if (kVarType == ms_kFloat4Str)
            {
                iNumFloats = 4;
            }
            else if (kVarType == ms_kFloat4x4Str)
            {
                iNumFloats = 16;
            }
            else if (kVarType == ms_kSampler1DStr)
            {
                eSType = SamplerInformation::SAMPLER_1D;
            }
            else if (kVarType == ms_kSampler2DStr)
            {
                eSType = SamplerInformation::SAMPLER_2D;
            }
            else if (kVarType == ms_kSampler3DStr)
            {
                eSType = SamplerInformation::SAMPLER_3D;
            }
            else if (kVarType == ms_kSamplerCubeStr)
            {
                eSType = SamplerInformation::SAMPLER_CUBE;
            }
            else if (kVarType == ms_kSamplerProjStr)
            {
                eSType = SamplerInformation::SAMPLER_PROJ;
            }
            else
            {
                // The data type is not supported by Wild Magic.
                assert(false);
                return false;
            }

            // Skip over white space.
            uiBegin = kLine.find_first_not_of(" ",uiEnd);
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }

            // Get the variable's name.
            uiEnd = kLine.find(" ",uiBegin);
            kVarName = kLine.substr(uiBegin,uiEnd-uiBegin);

            // Skip over white space.
            uiBegin = kLine.find_first_not_of(" ",uiEnd);
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }

            // Get sampler information (if relevant).
            if (eSType != SamplerInformation::MAX_SAMPLER_TYPES)
            {
                // Skip over "texunit".
                uiBegin = kLine.find("texunit",uiBegin);
                if (uiBegin == std::string::npos)
                {
                    assert(false);
                    return false;
                }
                uiBegin += 7;
                if (kLine[uiBegin] != ' ')
                {
                    assert(false);
                    return false;
                }

                // Get the texture unit.
                uiBegin++;
                if (!('0' <= kLine[uiBegin] && kLine[uiBegin] <= '7'))
                {
                    assert(false);
                    return false;
                }
                iUnit = (int)kLine[uiBegin] - '0';

                SamplerInformation kSU(kVarName,eSType,iUnit);
                rkSIs.push_back(kSU);
                continue;
            }

            // Get the variable's I/O status.
            uiSave = uiBegin;
            uiBegin = kLine.find("$",uiSave);
            if (uiBegin != std::string::npos)
            {
                // The variable is either an input or output variable.
                uiBegin += 2;
                uiEnd = kLine.find_first_of(".",uiBegin);
                kVarIO = kLine.substr(uiBegin,uiEnd-uiBegin);

                // Get the variable's semantic.
                uiBegin = uiEnd+1;
                uiEnd = kLine.find_first_of(" ",uiBegin);
                kVarSemantic = kLine.substr(uiBegin,uiEnd-uiBegin);

                if (kVarIO == ms_kInStr)
                {
                    if (kVarSemantic == ms_kPositionStr)
                    {
                        // Wild Magic only supplies (x,y,z) positions.
                        rkIAttr.SetPChannels(3);
                    }
                    else if (kVarSemantic == ms_kNormalStr)
                    {
                        // Wild Magic only supplies (x,y,z) normals.
                        rkIAttr.SetNChannels(3);
                    }
                    else if (kVarSemantic == ms_kColorStr
                    || kVarSemantic == ms_kColor0Str)
                    {
                        rkIAttr.SetCChannels(0,iNumFloats);
                    }
                    else if (kVarSemantic == ms_kColor1Str)
                    {
                        rkIAttr.SetCChannels(1,iNumFloats);
                    }
                    else // texture coordinate
                    {
                        if (kVarSemantic.substr(0,8) != ms_kTexCoordStr)
                        {
                            assert(false);
                            return false;
                        }
                        iUnit = (int)kVarSemantic[8] - '0';
                        rkIAttr.SetTChannels(iUnit,iNumFloats);
                    }
                }
                else  // kVarIO == std::string("out")
                {
                    if (kVarSemantic == ms_kPositionStr)
                    {
                        rkOAttr.SetPChannels(iNumFloats);
                    }
                    else if (kVarSemantic == ms_kNormalStr)
                    {
                        rkOAttr.SetNChannels(iNumFloats);
                    }
                    else if (kVarSemantic == ms_kColorStr
                    || kVarSemantic == ms_kColor0Str)
                    {
                        rkOAttr.SetCChannels(0,iNumFloats);
                    }
                    else if (kVarSemantic == ms_kColor1Str)
                    {
                        rkOAttr.SetCChannels(1,iNumFloats);
                    }
                    else // texture coordinate
                    {
                        if (kVarSemantic.substr(0,8) != ms_kTexCoordStr)
                        {
                            assert(false);
                            return false;
                        }
                        iUnit = (int)kVarSemantic[8] - '0';
                        rkOAttr.SetTChannels(iUnit,iNumFloats);
                    }
                }
            }
            else
            {
                // The variable is stored in a constant register.
                uiBegin = kLine.find("c[",uiSave);
                if (uiBegin == std::string::npos)
                {
                    assert(false);
                    return false;
                }
                uiEnd = kLine.find_first_of("]",uiBegin);
                uiBegin += 2;
                kRegister = kLine.substr(uiBegin,uiEnd-uiBegin);
                iBaseRegister = atoi(kRegister.c_str());

                iRegisterQuantity = iNumFloats/4;
                if (iRegisterQuantity == 0)
                {
                    iRegisterQuantity = 1;
                }

                // The variable is either a render state or user-defined.
                eRCType = RendererConstant::GetType(kVarName);
                if (eRCType != RendererConstant::MAX_TYPES)
                {
                    // renderer constant
                    RendererConstant kRC(eRCType,iBaseRegister,
                        iRegisterQuantity);
                    rkRCs.push_back(kRC);
                }
                else
                {
                    // user-defined constant
                    UserConstant kUC(kVarName,iBaseRegister,
                        iRegisterQuantity);
                    rkUCs.push_back(kUC);
                }
            }

            continue;
        }

        uiBegin = kLine.find("const",1);
        if (uiBegin != std::string::npos)
        {
            // A numerical constant register has been found.
            uiBegin = kLine.find("c[");
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }
            uiEnd = kLine.find_first_of("]",uiBegin);
            uiBegin += 2;
            kRegister = kLine.substr(uiBegin,uiEnd-uiBegin);
            iBaseRegister = atoi(kRegister.c_str());

            // Get the constant's data, which occurs after the equality.
            float afData[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
            uiBegin = kLine.find("=");
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }
            uiBegin++;
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }
            uiBegin = kLine.find_first_not_of(" ",uiBegin);
            if (uiBegin == std::string::npos)
            {
                assert(false);
                return false;
            }

            for (int i = 0; i < 4; i++)
            {
                uiEnd = kLine.find_first_of(" ",uiBegin);
                if (uiEnd == std::string::npos)
                {
                    kData = kLine.substr(uiBegin);
                    afData[i] = (float)atof(kData.c_str());
                    break;
                }

                kData = kLine.substr(uiBegin,uiEnd-uiBegin);
                afData[i] = (float)atof(kData.c_str());
                uiBegin = kLine.find_first_not_of(" ",uiEnd);
                if (uiBegin == std::string::npos)
                {
                    assert(false);
                    return false;
                }
            }

            NumericalConstant kNC(iBaseRegister,afData);
            rkNCs.push_back(kNC);
        }
    }

    kIStr.close();
    return true;
}
//----------------------------------------------------------------------------
Program::Program ()
{
}
//----------------------------------------------------------------------------
Program::~Program ()
{
    Release();
}
//----------------------------------------------------------------------------
RendererConstant* Program::GetRC (int i)
{
    if (0 <= i && i < (int)m_kRendererConstants.size())
    {
        return &m_kRendererConstants[i];
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
RendererConstant* Program::GetRC (RendererConstant::Type eType)
{
    for (int i = 0; i < (int)m_kRendererConstants.size(); i++)
    {
        if (eType == m_kRendererConstants[i].GetType())
        {
            return &m_kRendererConstants[i];
        }
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
NumericalConstant* Program::GetNC (int i)
{
    if (0 <= i && i < (int)m_kNumericalConstants.size())
    {
        return &m_kNumericalConstants[i];
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
UserConstant* Program::GetUC (int i)
{
    if (0 <= i && i < (int)m_kUserConstants.size())
    {
        return &m_kUserConstants[i];
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
UserConstant* Program::GetUC (const std::string& rkName)
{
    for (int i = 0; i < (int)m_kUserConstants.size(); i++)
    {
        if (rkName == m_kUserConstants[i].GetName())
        {
            return &m_kUserConstants[i];
        }
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
SamplerInformation* Program::GetSI (int i)
{
    if (0 <= i && i < (int)m_kSamplerInformation.size())
    {
        return &m_kSamplerInformation[i];
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
SamplerInformation* Program::GetSI (const std::string& rkName)
{
    for (int i = 0; i < (int)m_kSamplerInformation.size(); i++)
    {
        if (rkName == m_kSamplerInformation[i].GetName())
        {
            return &m_kSamplerInformation[i];
        }
    }

    assert(false);
    return 0;
}
//----------------------------------------------------------------------------
