// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CLODMESH_H
#define WM4CLODMESH_H

#include "Wm4GraphicsLIB.h"
#include "Wm4CollapseRecord.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ClodMesh : public TriMesh
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  ClodMesh accepts responsibility for
    // deleting the input arrays.
    ClodMesh (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer,
        int iRecordQuantity, CollapseRecord* akRecord);

    virtual ~ClodMesh ();

    // LOD selection is based on manual selection by the application.  To
    // use distance from camera or screen space coverage, derive a class
    // from Wm4ClodMesh and override 'GetAutomatedTargetRecord'.
    int GetRecordQuantity () const;
    int& TargetRecord ();
    virtual int GetAutomatedTargetRecord ();

    // Geometric updates.  The Draw method will call this update and adjust
    // the TriMesh quantities according to the current value of the target
    // record.  You can call this manually in an application that does not
    // need to display the mesh.
    void SelectLevelOfDetail ();

protected:
    ClodMesh ();

    // culling
    virtual void GetVisibleSet (Culler& rkCuller, bool bNoCull);

    // selection of LOD
    int m_iCurrentRecord, m_iTargetRecord;
    int m_iRecordQuantity;
    CollapseRecord* m_akRecord;
};

WM4_REGISTER_STREAM(ClodMesh);
typedef Pointer<ClodMesh> ClodMeshPtr;
#include "Wm4ClodMesh.inl"

}

#endif
