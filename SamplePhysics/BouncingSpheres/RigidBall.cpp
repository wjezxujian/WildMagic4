// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "RigidBall.h"
#include "Wm4StandardMesh.h"
#include "Wm4TextureEffect.h"

//----------------------------------------------------------------------------
RigidBall::RigidBall (float fRadius)
{
    m_fRadius = fRadius;
    Moved = false;

    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetTChannels(0,2);
    m_spkMesh = StandardMesh(kAttr).Sphere(16,16,m_fRadius);

    m_spkMesh->AttachEffect(WM4_NEW TextureEffect("BallTexture"));
}
//----------------------------------------------------------------------------
float RigidBall::GetRadius () const
{ 
    return m_fRadius; 
}
//----------------------------------------------------------------------------
TriMeshPtr& RigidBall::Mesh ()
{
    return m_spkMesh;
}
//----------------------------------------------------------------------------

