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
PhysicsModule::PhysicsModule (int iNumParticles, float fStep,
    const Vector3f& rkGravity, const Vector3f& rkWind,
    float fWindChangeAmplitude, float fViscosity)
    :
    MassSpringCurve3f(iNumParticles,fStep),
    m_kGravity(rkGravity),
    m_kWind(rkWind)
{
    m_fWindChangeAmplitude = fWindChangeAmplitude;
    m_fViscosity = fViscosity;
    m_bEnableWind = false;
    m_bEnableWindChange = false;
}
//----------------------------------------------------------------------------
bool& PhysicsModule::EnableWind ()
{
    return m_bEnableWind;
}
//----------------------------------------------------------------------------
bool& PhysicsModule::EnableWindChange ()
{
    return m_bEnableWindChange;
}
//----------------------------------------------------------------------------
Vector3f PhysicsModule::ExternalAcceleration (int i, float, const Vector3f*,
    const Vector3f* akVelocity)
{
    // acceleration due to gravity
    Vector3f kAcceleration = m_kGravity;

    // acceleration due to wind
    if (m_bEnableWind)
    {
        if (m_bEnableWindChange)
        {
            // generate random direction close to last one
            Vector3f kU, kV, kW = m_kWind;
            float fLength = kW.Normalize();
            Vector3f::GenerateOrthonormalBasis(kU,kV,kW,true);
            float fUDelta = m_fWindChangeAmplitude*Mathf::SymmetricRandom();
            float fVDelta = m_fWindChangeAmplitude*Mathf::SymmetricRandom();
            kW += fUDelta*kU + fVDelta*kV;
            kW.Normalize();
            m_kWind = fLength*kW;
        }
        kAcceleration += m_kWind;
    }

    // Add in a friction term.  Otherwise the system tends to be "stiff"
    // (in the numerical stability sense) and leads to oscillatory behavior.
    kAcceleration -= m_fViscosity*akVelocity[i];

    return kAcceleration;
}
//----------------------------------------------------------------------------

