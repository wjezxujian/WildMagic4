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
inline double PhysicsModule::GetTime () const
{
    return m_dTime;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetDeltaTime () const
{
    return m_dDeltaTime;
}
//----------------------------------------------------------------------------
inline const Wm4::Vector2d& PhysicsModule::GetPosition () const
{
    return m_kPosition;
}
//----------------------------------------------------------------------------
inline const Wm4::Vector2d& PhysicsModule::GetVelocity () const
{
    return m_kVelocity;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetFrequency () const
{
    return m_dFrequency;
}
//----------------------------------------------------------------------------
