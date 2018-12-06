// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4CollisionGroup.h"
#include "Wm4CollisionRecord.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CollisionGroup::CollisionGroup ()
{
}
//----------------------------------------------------------------------------
CollisionGroup::~CollisionGroup ()
{
    for (int i = 0; i < (int)m_kRecord.size(); i++)
    {
        WM4_DELETE m_kRecord[i];
    }
}
//----------------------------------------------------------------------------
bool CollisionGroup::Add (CollisionRecord* pkRecord)
{
    for (int i = 0; i < (int)m_kRecord.size(); i++)
    {
        if (pkRecord == m_kRecord[i])
        {
            return false;
        }
    }

    m_kRecord.push_back(pkRecord);
    return true;
}
//----------------------------------------------------------------------------
bool CollisionGroup::Remove (CollisionRecord* pkRecord)
{
    std::vector<CollisionRecord*>::iterator pkIter = m_kRecord.begin();
    for (/**/; pkIter != m_kRecord.end(); pkIter++)
    {
        if (pkRecord == *pkIter)
        {
            m_kRecord.erase(pkIter);
            WM4_DELETE pkRecord;
            return true;
        }
    }

    return false;
}
//----------------------------------------------------------------------------
void CollisionGroup::TestIntersection ()
{
    // objects are assumed to be stationary, compare all pairs
    for (int i0 = 0; i0 < (int)m_kRecord.size(); i0++)
    {
        CollisionRecord* pkRecord0 = m_kRecord[i0];
        for (int i1 = i0+1; i1 < (int)m_kRecord.size(); i1++)
        {
            CollisionRecord* pkRecord1 = m_kRecord[i1];
            pkRecord0->TestIntersection(*pkRecord1);
        }
    }
}
//----------------------------------------------------------------------------
void CollisionGroup::FindIntersection ()
{
    // objects are assumed to be stationary, compare all pairs
    for (int i0 = 0; i0 < (int)m_kRecord.size(); i0++)
    {
        CollisionRecord* pkRecord0 = m_kRecord[i0];
        for (int i1 = i0+1; i1 < (int)m_kRecord.size(); i1++)
        {
            CollisionRecord* pkRecord1 = m_kRecord[i1];
            pkRecord0->FindIntersection(*pkRecord1);
        }
    }
}
//----------------------------------------------------------------------------
void CollisionGroup::TestIntersection (float fTMax)
{
    // objects are assumed to be moving, compare all pairs
    for (int i0 = 0; i0 < (int)m_kRecord.size(); i0++)
    {
        CollisionRecord* pkRecord0 = m_kRecord[i0];
        for (int i1 = i0+1; i1 < (int)m_kRecord.size(); i1++)
        {
            CollisionRecord* pkRecord1 = m_kRecord[i1];
            if ( pkRecord0->GetVelocity() || pkRecord1->GetVelocity() )
                pkRecord0->TestIntersection(fTMax,*pkRecord1);
        }
    }
}
//----------------------------------------------------------------------------
void CollisionGroup::FindIntersection (float fTMax)
{
    // objects are assumed to be moving, compare all pairs
    for (int i0 = 0; i0 < (int)m_kRecord.size(); i0++)
    {
        CollisionRecord* pkRecord0 = m_kRecord[i0];
        for (int i1 = i0+1; i1 < (int)m_kRecord.size(); i1++)
        {
            CollisionRecord* pkRecord1 = m_kRecord[i1];
            if ( pkRecord0->GetVelocity() || pkRecord1->GetVelocity() )
                pkRecord0->FindIntersection(fTMax,*pkRecord1);
        }
    }
}
//----------------------------------------------------------------------------
