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
inline void Culler::SetCamera (const Camera* pkCamera)
{
    m_pkCamera = pkCamera;
}
//----------------------------------------------------------------------------
inline const Camera* Culler::GetCamera () const
{
    return m_pkCamera;
}
//----------------------------------------------------------------------------
inline const float* Culler::GetFrustum () const
{
    return m_afFrustum;
}
//----------------------------------------------------------------------------
inline VisibleSet& Culler::GetVisibleSet ()
{
    return m_kVisible;
}
//----------------------------------------------------------------------------
inline void Culler::Insert (Spatial* pkObject, Effect* pkGlobalEffect)
{
    m_kVisible.Insert(pkObject,pkGlobalEffect);
}
//----------------------------------------------------------------------------
inline int Culler::GetPlaneQuantity () const
{
    return m_iPlaneQuantity;
}
//----------------------------------------------------------------------------
inline const Plane3f* Culler::GetPlanes () const
{
    return m_akPlane;
}
//----------------------------------------------------------------------------
inline void Culler::SetPlaneState (unsigned int uiPlaneState)
{
    m_uiPlaneState = uiPlaneState;
}
//----------------------------------------------------------------------------
inline unsigned int Culler::GetPlaneState () const
{
    return m_uiPlaneState;
}
//----------------------------------------------------------------------------
inline void Culler::PushPlane (const Plane3f& rkPlane)
{
    if (m_iPlaneQuantity < VS_MAX_PLANE_QUANTITY)
    {
        // The number of user-defined planes is limited.
        m_akPlane[m_iPlaneQuantity++] = rkPlane;
    }
}
//----------------------------------------------------------------------------
inline void Culler::PopPlane ()
{
    if (m_iPlaneQuantity > Camera::VF_QUANTITY)
    {
        // Frustum planes may not be removed from the stack.
        m_iPlaneQuantity--;
    }
}
//----------------------------------------------------------------------------
