// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4USERCONSTANT_H
#define WM4USERCONSTANT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM UserConstant
{
public:
    // Construction and destruction.  The base register must be nonnegative.
    // The register quantity must be positive.  Each register represents four
    // floating-point values.
    UserConstant (const std::string& rkName, int iBaseRegister,
        int iRegisterQuantity);
    ~UserConstant ();

    // Member access.  The renderer will use these to pass the information to
    // the graphics API.
    const std::string& GetName () const;
    int GetBaseRegister () const;
    int GetRegisterQuantity () const;
    float* GetData () const;

    // The Shader base class provides storage for the user constants and
    // will set the float pointer to this storage when the shader program is
    // loaded.  However, Shader-derived classes may provide their own
    // storage and set the float pointer accordingly.  Such derived classes
    // are responsible for deallocating the storage if it was dynamically
    // allocated.
    void SetDataSource (float* afData);

private:
    std::string m_kName;
    int m_iBaseRegister;
    int m_iRegisterQuantity;
    float* m_afData;
};

#include "Wm4UserConstant.inl"

}

#endif
