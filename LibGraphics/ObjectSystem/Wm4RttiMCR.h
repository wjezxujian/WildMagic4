// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RTTIMCR_H
#define WM4RTTIMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_RTTI \
public: \
    static const Rtti TYPE; \
    virtual const Rtti& GetType () const { return TYPE; }
//----------------------------------------------------------------------------
#define WM4_DECLARE_TEMPLATE_RTTI \
public: \
    WM4_GRAPHICS_ITEM static const Rtti TYPE; \
    virtual const Rtti& GetType () const { return TYPE; }
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_RTTI(nsname,classname,baseclassname) \
    const Rtti classname::TYPE(#nsname"."#classname,&baseclassname::TYPE)
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_TEMPLATE_RTTI(nsname,classname,baseclassname) \
    template <> \
    const Rtti classname::TYPE(#nsname"."#classname,&baseclassname::TYPE)
//----------------------------------------------------------------------------

#endif
