// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline const std::string& Program::GetProgramText () const
{
    return m_kProgramText;
}
//----------------------------------------------------------------------------
inline const Attributes& Program::GetInputAttributes () const
{
    return m_kInputAttributes;
}
//----------------------------------------------------------------------------
inline const Attributes& Program::GetOutputAttributes () const
{
    return m_kOutputAttributes;
}
//----------------------------------------------------------------------------
inline int Program::GetRCQuantity () const
{
    return (int)m_kRendererConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetNCQuantity () const
{
    return (int)m_kNumericalConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetUCQuantity () const
{
    return (int)m_kUserConstants.size();
}
//----------------------------------------------------------------------------
inline int Program::GetSIQuantity () const
{
    return (int)m_kSamplerInformation.size();
}
//----------------------------------------------------------------------------
