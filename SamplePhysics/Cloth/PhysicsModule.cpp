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
PhysicsModule::PhysicsModule (int iRows, int iCols, float fStep,
    const Vector3f& rkGravity, const Vector3f& rkWind, float fViscosity,
    float fAmplitude)
    :
    MassSpringSurface3f(iRows,iCols,fStep),
    m_kGravity(rkGravity),
    m_kWind(rkWind)
{
    m_fViscosity = fViscosity;
    m_kDirection = m_kGravity.UnitCross(m_kWind);
    m_fAmplitude = fAmplitude;

    m_afPhase = WM4_NEW float[m_iNumParticles];
    for (int iRow = 0; iRow < m_iRows; iRow++)
    {
        for (int iCol = 0; iCol < m_iCols; iCol++)
        {
            m_afPhase[GetIndex(iRow,iCol)] = Mathf::UnitRandom()*Mathf::PI;
        }
    }
}
//----------------------------------------------------------------------------
PhysicsModule::~PhysicsModule ()
{
    WM4_DELETE[] m_afPhase;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float fTime,
    const Vector3f*, const Vector3f* akVelocity)
{
    // acceleration due to gravity, wind, and viscosity
    Vector3f kAcceleration = m_kGravity + m_kWind -
        m_fViscosity*akVelocity[i];

    // sinusoidal perturbation
    float fAmplitude = m_fAmplitude*Mathf::Sin(2.0f*fTime+m_afPhase[i]);
    kAcceleration += fAmplitude*m_kDirection;

    return kAcceleration;
}
//----------------------------------------------------------------------------

