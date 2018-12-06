// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4IMAGECATALOG_H
#define WM4IMAGECATALOG_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4MainMCR.h"

namespace Wm4
{

class Image;

class WM4_GRAPHICS_ITEM ImageCatalog
{
public:
    ImageCatalog (const std::string& rkName);
    ~ImageCatalog ();

    const std::string& GetName () const;
    bool Insert (Image* pkImage);
    bool Remove (Image* pkImage);
    Image* Find (const std::string& rkImageName);
    bool PrintContents (const std::string& rkFilename) const;

    static void SetActive (ImageCatalog* pkActive);
    static ImageCatalog* GetActive ();

private:
    std::string m_kName;
    std::map<std::string,Image*> m_kEntry;
    ObjectPtr m_spkDefaultImage;

    static const std::string ms_kNullString;
    static const std::string ms_kDefaultString;
    static ImageCatalog* ms_pkActive;
};

}

#endif
