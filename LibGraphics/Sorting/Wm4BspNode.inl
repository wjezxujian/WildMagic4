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
inline Plane3f& BspNode::ModelPlane ()
{
    return m_kModelPlane;
}
//----------------------------------------------------------------------------
inline const Plane3f& BspNode::GetModelPlane () const
{
    return m_kModelPlane;
}
//----------------------------------------------------------------------------
inline const Plane3f& BspNode::GetWorldPlane () const
{
    return m_kWorldPlane;
}
//----------------------------------------------------------------------------
