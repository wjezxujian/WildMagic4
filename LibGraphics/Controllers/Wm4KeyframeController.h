// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4KEYFRAMECONTROLLER_H
#define WM4KEYFRAMECONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Controller.h"
#include "Wm4FloatArray.h"
#include "Wm4QuaternionArray.h"
#include "Wm4Vector3Array.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM KeyframeController : public Controller
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    KeyframeController ();
    virtual ~KeyframeController ();

    FloatArrayPtr TranslationTimes;
    Vector3fArrayPtr TranslationData;

    FloatArrayPtr RotationTimes;
    QuaternionfArrayPtr RotationData;

    FloatArrayPtr ScaleTimes;
    FloatArrayPtr ScaleData;

    // animation update
    virtual bool Update (double dAppTime);

protected:
    static void GetKeyInfo (float fCtrlTime, int iQuantity, float* afTime,
        int& riLastIndex, float& rfNormTime, int& ri0, int& ri1);

    Vector3f GetTranslate (float fNormTime, int i0, int i1);
    Matrix3f GetRotate (float fNormTime, int i0, int i1);
    float GetScale (float fNormTime, int i0, int i1);

    // Cached indices for the last found pair of keys used for interpolation.
    // For a sequence of times, this guarantees an O(1) lookup.
    int m_iTLastIndex;
    int m_iRLastIndex;
    int m_iSLastIndex;
};

WM4_REGISTER_STREAM(KeyframeController);
typedef Pointer<KeyframeController> KeyframeControllerPtr;

}

#endif
