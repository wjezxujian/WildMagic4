// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4IMAGE_H
#define WM4IMAGE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4ColorRGBA.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Image : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // NOTE:  Image dimensions must be a power of two.  Assert statements are
    // placed in the constructors to trap when the dimensions are not power
    // of two.

    enum FormatMode
    {
        IT_RGB888,
        IT_RGBA8888,
        IT_DEPTH16,
        IT_DEPTH24,
        IT_DEPTH32,
        IT_CUBE_RGB888,
        IT_CUBE_RGBA8888,
        IT_RGB32,
        IT_RGBA32,
        IT_QUANTITY
    };

    // The color image data is stored so that the red channel is in low
    // memory, the green channel is next, the blue channel after that, and the
    // alpha channel in high memory.  For example, the first pixel has the
    // following layout.
    //
    //   IT_RGB888:
    //     r = aucData[0];
    //     g = aucData[1];
    //     b = aucData[2];
    //
    //   IT_RGBA8888:
    //     r = aucData[0];
    //     g = aucData[1];
    //     b = aucData[2];
    //     a = aucData[3];
    //
    // Depth image data is always 'float' with values in [0,1].  The
    // specification of 16, 24, or 32 is for setting up the hardware with the
    // correct size depth buffer.  Data read into a depth image from the depth
    // buffer will be converted to [0,1] if necessary.

    // Construction and destruction.  Image accepts responsibility for
    // deleting the input array.  The acImageName field is used as a unique
    // identifier for the image for purposes of sharing.  The caller of
    // the constructor may provided a name.  If not, the constructor generates
    // a unique name "imageN.wmif" where N is the Object::m_uiID field. A
    // global map of images is maintained for sharing purposes.

    // 1D image
    Image (FormatMode eFormat, int iBound0, unsigned char* aucData,
        const char* acImageName);

    // 2D image
    Image (FormatMode eFormat, int iBound0, int iBound1,
        unsigned char* aucData, const char* acImageName);

    // 3D image
    Image (FormatMode eFormat, int iBound0, int iBound1, int iBound2,
        unsigned char* aucData, const char* acImageName);

    virtual ~Image ();

    // member access
    FormatMode GetFormat () const;
    const std::string& GetFormatName () const;
    static std::string GetFormatName (int eFormat);
    bool IsDepthImage () const;
    bool IsCubeImage () const;
    int GetBytesPerPixel () const;
    static int GetBytesPerPixel (int eFormat);
    int GetDimension () const;
    int GetBound (int i) const;
    int GetQuantity () const;
    unsigned char* GetData () const;
    unsigned char* operator() (int i);

    // Create an image of ColorRGBA values.  The function returns an image
    // of the same width and height for these formats.  The returned image
    // is dynamically allocated; the caller is responsible for deleting it.
    ColorRGBA* CreateRGBA () const;

    // Copy to an already existing image of ColorRGBA values.  The input
    // array must have the correct dimensions as the Image itself.
    void CopyRGBA (ColorRGBA* akCImage) const;

    // Streaming support.  The sharing system is automatically invoked by
    // these calls.  In Load, if an image corresponding to the filename is
    // already in memory, then that image is returned (i.e. shared).
    // Otherwise, a new image is created and returned.  The filename is used
    // as the image name.
    static Image* Load (const char* acImageName);

    // This is intended to support saving procedurally generated images or
    // for utilities that convert to WMIF from another format.  The filename
    // in this call does not replace the image name that might already exist.
    bool Save (const char* acFilename);

protected:
    // support for streaming
    Image ();

    FormatMode m_eFormat;
    int m_iDimension;
    int m_aiBound[3];
    int m_iQuantity;
    unsigned char* m_aucData;

    static int ms_aiBytesPerPixel[IT_QUANTITY];
    static std::string ms_akFormatName[IT_QUANTITY];
};

WM4_REGISTER_STREAM(Image);
typedef Pointer<Image> ImagePtr;
#include "Wm4Image.inl"

}

#endif
