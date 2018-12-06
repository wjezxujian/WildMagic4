// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SORTEDCUBE_H
#define SORTEDCUBE_H

#include "Wm4Node.h"
#include "Wm4Camera.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class SortedCube : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SortedCube (Camera* pkCamera,
        const std::string& rkXpImage, const std::string& rkXmImage,
        const std::string& rkYpImage, const std::string& rkYmImage,
        const std::string& rkZpImage, const std::string& rkZmImage);

    virtual ~SortedCube ();

    void SetCamera (Camera* pkCamera);

protected:
    SortedCube ();

    void SortFaces ();
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull = false);

    CameraPtr m_spkCamera;

    // 0 = face xp
    // 1 = face xm
    // 2 = face yp
    // 3 = face ym
    // 4 = face zp
    // 5 = face zm
    TriMeshPtr m_aspkFace[6];

    // bit 0 = face xp
    // bit 1 = face xm
    // bit 2 = face yp
    // bit 3 = face ym
    // bit 4 = face zp
    // bit 5 = face zm
    int m_iBackFacing;
};

WM4_REGISTER_STREAM(SortedCube);
typedef Pointer<SortedCube> SortedCubePtr;

}

#endif
