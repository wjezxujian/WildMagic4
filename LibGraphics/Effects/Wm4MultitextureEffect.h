// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MULTITEXTUREEFFECT_H
#define WM4MULTITEXTUREEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM MultitextureEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    MultitextureEffect (int iTextureQuantity);
    virtual ~MultitextureEffect ();

    // Selection of the textures to be used by the effect.  The first call
    // should be SetTextureQuantity for the desired number of textures.  For
    // each texture, specify its image with SetImageName.  Texture 0 is
    // used as is (replace mode).  Texture i is blended with texture i-1 (for
    // i > 0) according to the modes specified by alpha state i to
    // produce the current colors.  After setting all the image names and all
    // the blending modes, call Configure() to activate the correct shader
    // program for the current set of textures.
    void SetTextureQuantity (int iTextureQuantity);
    int GetTextureQuantity () const;
    void SetImageName (int i, const std::string& rkImageName);
    const std::string& GetImageName (int i) const;
    void Configure ();

protected:
    // streaming support
    MultitextureEffect ();

    int m_iTextureQuantity;
    std::string* m_akImageName;
};

WM4_REGISTER_STREAM(MultitextureEffect);
typedef Pointer<MultitextureEffect> MultitextureEffectPtr;

}

#endif
