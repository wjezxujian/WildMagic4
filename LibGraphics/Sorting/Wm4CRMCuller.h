// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CRMCULLER_H
#define WM4CRMCULLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Culler.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM CRMCuller : public Culler
{
public:
    CRMCuller (int iMaxQuantity = 0, int iGrowBy = 0,
        const Camera* pkCamera = 0);
    virtual ~CRMCuller ();

    // Two portals leading into the room can be visible to the camera.  The
    // Culler would store visible objects twice.  CRMCuller maintains a list
    // of unique objects.
    virtual void Insert (Spatial* pkObject, Effect* pkGlobalEffect);

protected:
    THashSet<Spatial*> m_kUnique;
};

}

#endif
