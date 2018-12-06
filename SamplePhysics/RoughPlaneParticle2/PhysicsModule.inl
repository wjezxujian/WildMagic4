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
inline double PhysicsModule::GetX () const
{
    return m_adState[0];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetXDot () const
{
    return m_adState[1];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetY () const
{
    return m_adState[2];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetYDot () const
{
    return m_adState[3];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetTheta () const
{
    return m_adState[4];
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetThetaDot () const
{
    return m_adState[5];
}
//----------------------------------------------------------------------------

