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
inline TriMesh* CollisionRecord::GetMesh ()
{
    return m_pkMesh;
}
//----------------------------------------------------------------------------
inline Vector3f* CollisionRecord::GetVelocity ()
{
    return m_pkVelocity;
}
//----------------------------------------------------------------------------
inline void* CollisionRecord::GetCallbackData ()
{
    return m_pvCallbackData;
}
//----------------------------------------------------------------------------
