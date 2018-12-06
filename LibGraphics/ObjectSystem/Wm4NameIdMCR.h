// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4NAMEIDMCR_H
#define WM4NAMEIDMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_NAME_ID \
public: \
    virtual Object* GetObjectByName (const std::string& rkName); \
    virtual void GetAllObjectsByName (const std::string& rkName, \
        std::vector<Object*>& rkObjects); \
    virtual Object* GetObjectByID (unsigned int uiID)
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_DEFAULT_NAME_ID(classname,baseclassname) \
Object* classname::GetObjectByName (const std::string& rkName) \
{ \
    return baseclassname::GetObjectByName(rkName); \
} \
\
void classname::GetAllObjectsByName (const std::string& rkName, \
    std::vector<Object*>& rkObjects) \
{ \
    baseclassname::GetAllObjectsByName(rkName,rkObjects); \
} \
\
Object* classname::GetObjectByID (unsigned int uiID) \
{ \
    return baseclassname::GetObjectByID(uiID); \
}
//----------------------------------------------------------------------------

#endif
