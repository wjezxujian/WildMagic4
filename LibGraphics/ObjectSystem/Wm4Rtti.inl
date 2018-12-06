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
inline const char* Rtti::GetName () const
{
    return m_acName;
}
//----------------------------------------------------------------------------
inline int Rtti::GetDiskUsed () const
{
    // The name will be written to disk as a String object.
    int iLength = (int)strlen(m_acName);
    return sizeof(iLength) + iLength*sizeof(char);
}
//----------------------------------------------------------------------------
inline bool Rtti::IsExactly (const Rtti& rkType) const
{
    return &rkType == this;
}
//----------------------------------------------------------------------------
