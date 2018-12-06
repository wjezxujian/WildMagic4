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
#include "Wm4StreamVersion.h"
using namespace Wm4;

const int StreamVersion::MAJOR = 3;
const int StreamVersion::MINOR = 2;
const char StreamVersion::LABEL[] = "Wild Magic Object File 3.02";
const int StreamVersion::LENGTH = 28;
const StreamVersion StreamVersion::CURRENT(MAJOR,MINOR);

//----------------------------------------------------------------------------
StreamVersion::StreamVersion (int iMajor, int iMinor)
{
    m_iMajor = iMajor;
    m_iMinor = iMinor;
}
//----------------------------------------------------------------------------
StreamVersion::StreamVersion (const char* acString)
{
    m_iMajor = -1;
    m_iMinor = -1;

    if (acString
    &&  strlen(acString) >= LENGTH-1
    &&  acString[LENGTH-1] == 0
    &&  strncmp(acString,LABEL,LENGTH-5) == 0)  // 5 = strlen(" 3.xx")
    {
        // The version string is "x.yy".
        const char* acVersion = acString + LENGTH - 5;
        m_iMajor = (int)(acVersion[0]-'0');
        m_iMinor = 10*(int)(acVersion[2]-'0') + (int)(acVersion[3]-'0');
    }
}
//----------------------------------------------------------------------------
bool StreamVersion::IsValid () const
{
    return m_iMajor == StreamVersion::MAJOR
        && 0 <= m_iMinor && m_iMinor < 100;
}
//----------------------------------------------------------------------------
int StreamVersion::GetMajor () const
{
    return m_iMajor;
}
//----------------------------------------------------------------------------
int StreamVersion::GetMinor () const
{
    return m_iMinor;
}
//----------------------------------------------------------------------------
int StreamVersion::GetCombined () const
{
    return 100*m_iMajor + m_iMinor;
}
//----------------------------------------------------------------------------
bool StreamVersion::operator== (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() == rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator!= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() != rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator< (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() < rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator<= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() <= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator> (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() > rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
bool StreamVersion::operator>= (const StreamVersion& rkVersion) const
{
    assert(IsValid() && rkVersion.IsValid());
    return GetCombined() >= rkVersion.GetCombined();
}
//----------------------------------------------------------------------------
