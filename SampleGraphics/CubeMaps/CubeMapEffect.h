// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CUBEMAPEFFECT_H
#define CUBEMAPEFFECT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ShaderEffect.h"
#include "Wm4Culler.h"

namespace Wm4
{

class Culler;

class CubeMapEffect : public ShaderEffect
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  The caller is responsible for deleting
    // the input images if they were dynamically allocated.  The images must
    // be 2D, must be square with a common bound, and must have format
    // Image::IT_RGB888.
    CubeMapEffect (Image* pkXpImage, Image* pkXmImage, Image* pkYpImage,
        Image* pkYmImage, Image* pkZpImage, Image* pkZmImage,
        float fReflectivity, bool bAllowDynamicUpdates);

    virtual ~CubeMapEffect ();

    virtual void Draw (Renderer* pkRenderer, Spatial* pkGlobalObject,
        int iVisibleQuantity, VisibleObject* akVisible);

    void SetReflectivity (float fReflectivity);
    float GetReflectivity () const;

    // For dynamic updating of the cube map.  This function computes the new
    // faces only when bAllowDynamicUpdates was set to 'true' in the
    // constructor.
    bool CanDynamicallyUpdate () const;
    void UpdateFaces (Renderer* pkRenderer, Spatial* pkScene,
        const Vector3f& rkEnvOrigin, const Vector3f& rkEnvDVector,
        const Vector3f& rkEnvUVector, const Vector3f& rkEnvRVector);

protected:
    CubeMapEffect ();

    // For dynamic updates.
    void UpdateFace (int iFace, const Image* pkImage);

    // Four of the faces need a reflection of the image to correct for the
    // handedness of coordinates.
    static void ReflectXY (int iXSize, int iYSize, int iBytesPerPixel,
        unsigned char* aucData);

    // Set the user-defined constants to use local storage.
    virtual void OnLoadPrograms (int iPass, Program* pkVProgram,
        Program* pkPProgram);

    // The reflectivity is stored at index 0.  The other values are unused.
    float m_afReflectivity[4];

    // Storage for the six cube face images.
    ImagePtr m_spkHexaImage;

    // For dynamic updates after construction of the effect.
    CameraPtr m_spkCamera;
    Culler* m_pkCuller;
    ImagePtr m_spkCubeFace;
    SamplerInformation* m_pkCubeFaceSI;
    Texture* m_pkCubeFaceTexture;
    FrameBuffer* m_pkCubeFaceBuffer;
};

WM4_REGISTER_STREAM(CubeMapEffect);
typedef Pointer<CubeMapEffect> CubeMapEffectPtr;
#include "CubeMapEffect.inl"

}

#endif
