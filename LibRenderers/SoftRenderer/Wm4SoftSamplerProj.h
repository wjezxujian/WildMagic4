// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTSAMPLERPROJ_H
#define WM4SOFTSAMPLERPROJ_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4SoftSampler.h"

namespace Wm4
{

class WM4_RENDERER_ITEM SoftSamplerProj : public SoftSampler
{
    WM4_DECLARE_INITIALIZE;

public:
    SoftSamplerProj (const Texture* pkTexture);
    virtual ~SoftSamplerProj ();

    virtual void Recreate (const ColorRGBA* akCImage);
    virtual void Recreate (const float* afDImage);

    virtual void ComputeMipmapParameters (const int aiX[3], const int aiY[3],
        const float* aafVertex[3], const Attributes& rkAttr);
    virtual void DisallowMipmapping ();
    virtual void CurrentPixel (int iX, int iY);

    virtual ColorRGBA operator() (const float* afCoord);

private:
    int Index (int iX, int iY) const;
    void CreateMipmaps ();
    void RecreateMipmaps ();

    ColorRGBA GetNearestColor (float fXIm, float fYIm) const;
    ColorRGBA GetLinearColor (float fXIm, float fYIm) const;

    int* m_aiXBound;
    int* m_aiYBound;
    int* m_aiLog2XBound;
    int m_iXBound0, m_iXBound1;
    int m_iYBound0, m_iYBound1;
    int m_iLog2XBound0, m_iLog2XBound1;
    int m_iCurrXBound, m_iCurrYBound;
    int m_iCurrLog2XBound;

    // Mipmapping parameters.  The texture coordinates and derivatives at
    // the pixel (x,y) are
    //   u = (a0*x + b0*y + c0)/(d*x + e*y + f)
    //   du/dx = (+(a0*e-b0*d)*y + (a0*f-c0*d))/(d*x + e*y + f)^2
    //   du/dy = (-(a0*e-b0*d)*x + (b0*f-c0*e))/(d*x + e*y + f)^2
    //   v = (a1*x + b1*y + c1)/(d*x + e*y + f)
    //   dv/dx = (+(a1*e-b1*d)*y + (a1*f-c1*d))/(d*x + e*y + f)^2
    //   dv/dy = (-(a1*e-b1*d)*x + (b1*f-c1*e))/(d*x + e*y + f)^2
    float m_afA[2], m_afB[2], m_afC[2];
    float m_afAEmBD[2], m_afAFmCD[2], m_afBFmCE[2];

    // Factory creation of samplers.
    static SoftSampler* CreateProj (const Texture* pkTexture);
};

WM4_REGISTER_INITIALIZE(SoftSamplerProj);

#include "Wm4SoftSamplerProj.inl"

}

#endif
