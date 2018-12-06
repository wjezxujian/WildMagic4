// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTSAMPLERCUBE_H
#define WM4SOFTSAMPLERCUBE_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftSampler2.h"

namespace Wm4
{

class WM4_RENDERER_ITEM SoftSamplerCube : public SoftSampler
{
    WM4_DECLARE_INITIALIZE;

public:
    SoftSamplerCube (const Texture* pkTexture);
    virtual ~SoftSamplerCube ();

    virtual void Recreate (const ColorRGBA* akCImage);

    virtual void ComputeMipmapParameters (const int aiX[3], const int aiY[3],
        const float* aafVertex[3], const Attributes& rkAttr);
    virtual void DisallowMipmapping ();
    virtual void CurrentPixel (int iX, int iY);

    virtual ColorRGBA operator() (const float* afCoord);

private:
    // +x, -x, +y, -y, +z, -z
    Texture* m_apkTexture[6];
    SoftSampler2* m_apkSampler[6];

    // Factory creation of samplers.
    static SoftSampler* CreateCube (const Texture* pkTexture);
};

WM4_REGISTER_INITIALIZE(SoftSamplerCube);

}

#endif
