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
Sphere3<Real>::Sphere3 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real>::Sphere3 (const Vector3<Real>& rkCenter, Real fRadius)
    :
    Center(rkCenter),
    Radius(fRadius)
{
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real>::Sphere3 (const Sphere3& rkSphere)
    :
    Center(rkSphere.Center),
    Radius(rkSphere.Radius)
{
}
//----------------------------------------------------------------------------
template <class Real>
Sphere3<Real>& Sphere3<Real>::operator= (const Sphere3& rkSphere)
{
    Center = rkSphere.Center;
    Radius = rkSphere.Radius;
    return *this;
}
//----------------------------------------------------------------------------
