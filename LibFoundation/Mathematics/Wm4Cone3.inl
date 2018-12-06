// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <class Real>
Cone3<Real>::Cone3 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Cone3<Real>::Cone3 (const Vector3<Real>& rkVertex,
    const Vector3<Real>& rkAxis, Real fAngle)
    :
    Vertex(rkVertex),
    Axis(rkAxis)
{
    CosAngle = Math<Real>::Cos(fAngle);
    SinAngle = Math<Real>::Sin(fAngle);
}
//----------------------------------------------------------------------------
template <class Real>
Cone3<Real>::Cone3 (const Vector3<Real>& rkVertex,
    const Vector3<Real>& rkAxis, Real fCosAngle, Real fSinAngle)
    :
    Vertex(rkVertex),
    Axis(rkAxis)
{
    CosAngle = fCosAngle;
    SinAngle = fSinAngle;
}
//----------------------------------------------------------------------------
