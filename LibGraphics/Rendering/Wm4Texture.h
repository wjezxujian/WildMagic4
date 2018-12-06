// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TEXTURE_H
#define WM4TEXTURE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Bindable.h"
#include "Wm4ColorRGBA.h"
#include "Wm4Image.h"
#include "Wm4SamplerInformation.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Texture : public Object, public Bindable
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    enum FilterType
    {
        NEAREST,          // nearest neighbor
        LINEAR,           // linear filtering
        NEAREST_NEAREST,  // nearest within image, nearest across images
        NEAREST_LINEAR,   // nearest within image, linear across images
        LINEAR_NEAREST,   // linear within image, nearest across images
        LINEAR_LINEAR,    // linear within image, linear across images
        MAX_FILTER_TYPES
    };

    enum WrapType
    {
        CLAMP,
        REPEAT,
        MIRRORED_REPEAT,
        CLAMP_BORDER,
        CLAMP_EDGE,
        MAX_WRAP_TYPES
    };

    enum DepthCompare
    {
        DC_NEVER,
        DC_LESS,
        DC_EQUAL,
        DC_LEQUAL,
        DC_GREATER,
        DC_NOTEQUAL,
        DC_GEQUAL,
        DC_ALWAYS,
        DC_QUANTITY
    };

    // Construction and destruction.
    Texture (Image* pkImage = 0, SamplerInformation* pkSInfo = 0,
        bool bSIOwner = false);
    Texture (Image* pkDepthImage, DepthCompare eCompare);
    virtual ~Texture ();

    // Access to texture images.
    void SetImage (Image* pkImage);
    Image* GetImage ();
    const Image* GetImage () const;

    // Access to sampler information.
    void SetSamplerInformation (SamplerInformation* pkSamplerInformation);
    SamplerInformation* GetSamplerInformation ();
    const SamplerInformation* GetSamplerInformation () const;

    // Access to filter modes.  The default is LINEAR.
    void SetFilterType (FilterType eFType);
    FilterType GetFilterType () const;

    // Access to wrap modes.  The input i to SetWrapType and GetWrapType must
    // satisfy 0 <= i < GetDimension().  The defaults are CLAMP_TO_EDGE.
    void SetWrapType (int i, WrapType eWType);
    WrapType GetWrapType (int i) const;

    // Access to the border color used for sampling outside the texture image.
    // The default is ColorRGBA(0,0,0,1).
    void SetBorderColor (const ColorRGBA& rkBorderColor);
    ColorRGBA GetBorderColor () const;

    // Support for depth textures.
    bool IsDepthTexture () const;
    void SetDepthCompare (DepthCompare eCompare);
    DepthCompare GetDepthCompare () const;

    // Support for offscreen textures.
    bool IsOffscreenTexture () const;
    void SetOffscreenTexture (bool bOffscreenTexture);

protected:
    ImagePtr m_spkImage;
    SamplerInformation* m_pkSamplerInformation;
    FilterType m_eFType;       // default = LINEAR
    WrapType m_aeWType[3];     // default = CLAMP_EDGE
    ColorRGBA m_kBorderColor;  // default = BLACK

    // Support for depth textures.  The default value is DC_QUANTITY,
    // indicating that the texture is *not* a depth texture.
    DepthCompare m_eCompare;

    // Support for offscreen textures.  The default value is 'false'.
    bool m_bOffscreenTexture;

    // If this object is the owner of m_pkSamplerInformation, the object was
    // dynamically allocated and must be deallocated during destruction.
    bool m_bSIOwner;

private:
    static const char* ms_aacFilterType[MAX_FILTER_TYPES];
    static const char* ms_aacWrapType[MAX_WRAP_TYPES];
    static const char* ms_aacDepthCompare[DC_QUANTITY];
};

WM4_REGISTER_STREAM(Texture);
typedef Pointer<Texture> TexturePtr;
#include "Wm4Texture.inl"

}

#endif
