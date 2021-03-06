// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MINIMALCYCLEBASIS_H
#define MINIMALCYCLEBASIS_H

#include "Wm4WindowApplication2.h"
#include "Wm4PlanarGraph.h"
#include <vector>
using namespace Wm4;

class MinimalCycleBasis : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    MinimalCycleBasis ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();

protected:
    typedef PlanarGraph<IVector2> Graph;
    Graph m_kGraph;
    std::vector<Graph::Primitive*> m_kPrimitives;
    Color* m_akColor;
};

WM4_REGISTER_INITIALIZE(MinimalCycleBasis);

#endif

