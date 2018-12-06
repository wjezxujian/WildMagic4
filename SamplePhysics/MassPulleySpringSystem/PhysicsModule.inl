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
inline double PhysicsModule::GetInitialY1 () const
{
    return m_dY1;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetCurrentY1 () const
{
    return m_dY1Curr;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetCurrentY2 () const
{
    return m_dY2Curr;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetCurrentY3 () const
{
    return m_dY3Curr;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetAngle () const
{
    return (m_dY1 - m_dY1Curr)/Radius;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetCableFraction1 () const
{
    return (m_dY1Curr - m_dY3Curr)/WireLength;
}
//----------------------------------------------------------------------------
inline double PhysicsModule::GetCableFraction2 () const
{
    return (m_dY2Curr - m_dY3Curr)/WireLength;
}
//----------------------------------------------------------------------------

