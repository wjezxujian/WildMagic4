// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "PhysicsModule.h"
using namespace Wm4;

//----------------------------------------------------------------------------
PhysicsModule::PhysicsModule (int iSlices, int iRows, int iCols, float fStep,
    float fViscosity)
    :
    MassSpringVolume3f(iSlices,iRows,iCols,fStep)
{
    m_fViscosity = fViscosity;
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
}
//----------------------------------------------------------------------------
float& PhysicsModule::Viscosity ()
{
    return m_fViscosity;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float, const Vector3f*,
    const Vector3f* akVelocity)
{
    Vector3f kAcceleration = -m_fViscosity*akVelocity[i];
    return kAcceleration;
}
//----------------------------------------------------------------------------

