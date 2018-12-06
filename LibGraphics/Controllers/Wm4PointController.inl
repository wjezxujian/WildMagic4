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
inline float* PointController::PointLinearSpeed ()
{
    return m_afPointLinearSpeed;
}
//----------------------------------------------------------------------------
inline float* PointController::PointAngularSpeed ()
{
    return m_afPointAngularSpeed;
}
//----------------------------------------------------------------------------
inline Vector3f* PointController::PointLinearAxis ()
{
    return m_akPointLinearAxis;
}
//----------------------------------------------------------------------------
inline Vector3f* PointController::PointAngularAxis ()
{
    return m_akPointAngularAxis;
}
//----------------------------------------------------------------------------
