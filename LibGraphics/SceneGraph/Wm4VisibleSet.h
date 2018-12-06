// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VISIBLESET_H
#define WM4VISIBLESET_H

#include "Wm4GraphicsLIB.h"
#include "Wm4VisibleObject.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VisibleSet
{
public:
    VisibleSet (int iMaxQuantity = 0, int iGrowBy = 0);
    virtual ~VisibleSet ();

    int GetQuantity () const;
    VisibleObject* GetVisible ();
    VisibleObject& GetVisible (int i);

    // Creates a VisibleObject from the input and appends it to the end of the
    // VisibleObject array.
    void Insert (Spatial* pkObject, Effect* pkGlobalEffect);
    void Clear ();
    void Resize (int iMaxQuantity, int iGrowBy);

private:
    enum
    {
        VS_DEFAULT_MAX_QUANTITY = 32,
        VS_DEFAULT_GROWBY = 32,
    };

    int m_iMaxQuantity, m_iGrowBy, m_iQuantity;
    VisibleObject* m_akVisible;
};

#include "Wm4VisibleSet.inl"

}

#endif
