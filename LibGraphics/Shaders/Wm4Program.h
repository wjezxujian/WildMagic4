// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PROGRAM_H
#define WM4PROGRAM_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"
#include "Wm4NumericalConstant.h"
#include "Wm4RendererConstant.h"
#include "Wm4SamplerInformation.h"
#include "Wm4UserConstant.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Program : public Object, public Bindable
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Abstract base class.
    virtual ~Program ();

    // Member read-only access.
    const std::string& GetProgramText () const;
    const Attributes& GetInputAttributes () const;
    const Attributes& GetOutputAttributes () const;

    // Access to renderer constants.
    int GetRCQuantity () const;
    RendererConstant* GetRC (int i);
    RendererConstant* GetRC (RendererConstant::Type eType);

    // Access to numerical constants.
    int GetNCQuantity () const;
    NumericalConstant* GetNC (int i);

    // Access to user constants.
    int GetUCQuantity () const;
    UserConstant* GetUC (int i);
    UserConstant* GetUC (const std::string& rkName);

    // Access to samplers.
    int GetSIQuantity () const;
    SamplerInformation* GetSI (int i);
    SamplerInformation* GetSI (const std::string& rkName);

protected:
    static bool Load (const std::string& rkFilename, char cCommentChar,
        Program* pkProgram);
    Program ();

    // The program itself, stored as a text string.
    std::string m_kProgramText;

    // The format of the input and output parameters to the shader program.
    Attributes m_kInputAttributes;
    Attributes m_kOutputAttributes;

    // The renderer constants required by the shader program.
    std::vector<RendererConstant> m_kRendererConstants;

    // The numerical constants required by the shader program.
    std::vector<NumericalConstant> m_kNumericalConstants;

    // The user constants required by the shader program.  These are set by
    // the applications as needed.
    std::vector<UserConstant> m_kUserConstants;

    // Information about the sampler units required by a shader program.
    std::vector<SamplerInformation> m_kSamplerInformation;

    // For use by the constructor for loading and parsing a shader program.
    static const std::string ms_kFloatStr;
    static const std::string ms_kFloat2Str;
    static const std::string ms_kFloat3Str;
    static const std::string ms_kFloat4Str;
    static const std::string ms_kFloat4x4Str;
    static const std::string ms_kSampler1DStr;
    static const std::string ms_kSampler2DStr;
    static const std::string ms_kSampler3DStr;
    static const std::string ms_kSamplerCubeStr;
    static const std::string ms_kSamplerProjStr;
    static const std::string ms_kPositionStr;
    static const std::string ms_kNormalStr;
    static const std::string ms_kColorStr;
    static const std::string ms_kColor0Str;
    static const std::string ms_kColor1Str;
    static const std::string ms_kTexCoordStr;
    static const std::string ms_kInStr;
    static const std::string ms_kOutStr;
    static const std::string ms_kEOL;
};

WM4_REGISTER_STREAM(Program);
typedef Pointer<Program> ProgramPtr;
#include "Wm4Program.inl"

}

#endif
