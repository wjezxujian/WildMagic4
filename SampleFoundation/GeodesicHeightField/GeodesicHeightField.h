// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef GEODESICHEIGHTFIELD_H
#define GEODESICHEIGHTFIELD_H

#include "Wm4WindowApplication3.h"
#include "Wm4BSplineGeodesic.h"
using namespace Wm4;

class GeodesicHeightField : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    GeodesicHeightField ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void DrawLine (int iX0, int iY0, int iX1, int iY1,
        int iWidth, unsigned char* aucData);
    void ComputeDistanceCurvature ();
    static void RefineCallback ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkMesh;
    ImagePtr m_spkImage;
    TextureEffectPtr m_spkEffect;
    Culler m_kCuller;

    BSplineRectangled* m_pkSurface;
    BSplineGeodesicd* m_pkGeodesic;

    int m_iSelected;
    int m_aiXIntr[2], m_aiYIntr[2];
    GVectord m_akPoint[2];
    int m_iPQuantity;
    GVectord* m_akPath;

    double m_dDistance, m_dCurvature;
};

WM4_REGISTER_INITIALIZE(GeodesicHeightField);

#endif
