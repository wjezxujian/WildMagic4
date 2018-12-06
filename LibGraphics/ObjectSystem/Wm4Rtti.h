// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RTTI_H
#define WM4RTTI_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"
#include "Wm4RttiMCR.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Rtti
{
public:
    // The name must be unique among all objects in the system.  In the Wm4
    // namespace, a class Foo should use "Wm4.Foo".  If an application has
    // another namespace, SomeName, then the name should be "SomeName.Foo".
    Rtti (const char* acName, const Rtti* pkBaseType);
    ~Rtti ();

    const char* GetName () const;
    int GetDiskUsed () const;

    bool IsExactly (const Rtti& rkType) const;
    bool IsDerived (const Rtti& rkType) const;

private:
    const char* m_acName;
    const Rtti* m_pkBaseType;
};

#include "Wm4Rtti.inl"

}

#endif
