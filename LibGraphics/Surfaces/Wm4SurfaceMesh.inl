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
inline int SurfaceMesh::GetLevel () const
{
    return m_iLevel;
}
//----------------------------------------------------------------------------
inline bool SurfaceMesh::IsLocked () const
{
    return m_spkOrigVBuffer == 0;
}
//----------------------------------------------------------------------------
