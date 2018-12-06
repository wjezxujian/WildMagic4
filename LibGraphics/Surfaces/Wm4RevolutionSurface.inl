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
inline int RevolutionSurface::GetCurveSamples () const
{
    return m_iCurveSamples;
}
//----------------------------------------------------------------------------
inline int RevolutionSurface::GetRadialSamples () const
{
    return m_iRadialSamples;
}
//----------------------------------------------------------------------------
inline void RevolutionSurface::SetCurve (Curve2f* pkCurve)
{
    m_pkCurve = pkCurve;
}
//----------------------------------------------------------------------------
inline const Curve2f* RevolutionSurface::GetCurve () const
{
    return m_pkCurve;
}
//----------------------------------------------------------------------------
inline RevolutionSurface::TopologyType RevolutionSurface::GetTopology () const
{
    return m_eTopology;
}
//----------------------------------------------------------------------------
inline bool& RevolutionSurface::SampleByArcLength ()
{
    return m_bSampleByArcLength;
}
//----------------------------------------------------------------------------
inline bool RevolutionSurface::GetSampleByArcLength () const
{
    return m_bSampleByArcLength;
}
//----------------------------------------------------------------------------
