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
inline Vector3f& DlodNode::ModelCenter ()
{
    return m_kModelLodCenter;
}
//----------------------------------------------------------------------------
inline const Vector3f& DlodNode::GetModelCenter () const
{
    return m_kModelLodCenter;
}
//----------------------------------------------------------------------------
inline const Vector3f& DlodNode::GetWorldCenter () const
{
    return m_kWorldLodCenter;
}
//----------------------------------------------------------------------------
inline float DlodNode::GetModelMinDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kModelMinDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetModelMaxDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kModelMaxDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetWorldMinDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kWorldMinDist[i];
}
//----------------------------------------------------------------------------
inline float DlodNode::GetWorldMaxDistance (int i) const
{
    assert(0 <= i && i < GetQuantity());
    return m_kWorldMaxDist[i];
}
//----------------------------------------------------------------------------
