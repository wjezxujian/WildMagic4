// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CLODTERRAINVERTEX_H
#define WM4CLODTERRAINVERTEX_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ClodTerrainVertex
{
public:
    ClodTerrainVertex ();

    void SetDependent (int i, ClodTerrainVertex* pkDependent);
    ClodTerrainVertex* GetDependent (int i);
    bool GetEnabled () const;
    void Enable ();
    void Disable ();

protected:
    ClodTerrainVertex* m_akDependent[2];
    bool m_bEnabled;
};

#include "Wm4ClodTerrainVertex.inl"

}

#endif
