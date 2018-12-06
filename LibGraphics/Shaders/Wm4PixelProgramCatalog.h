// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PIXELPROGRAMCATALOG_H
#define WM4PIXELPROGRAMCATALOG_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4MainMCR.h"

namespace Wm4
{

class PixelProgram;

class WM4_GRAPHICS_ITEM PixelProgramCatalog
{
public:
    PixelProgramCatalog (const std::string& rkName);
    ~PixelProgramCatalog ();

    // For deferred setting of the renderer type and comment character.  This
    // cannot be called until the application layer has created a renderer.
    // The layer does so in WindowApplication::SetRenderer.
    void SetInformation (const std::string& rkRendererType,
        char cCommentChar);

    const std::string& GetName () const;
    bool Insert (PixelProgram* pkProgram);
    bool Remove (PixelProgram* pkProgram);
    PixelProgram* Find (const std::string& rkProgramName);
    bool PrintContents (const std::string& rkFilename) const;

    static void SetActive (PixelProgramCatalog* pkActive);
    static PixelProgramCatalog* GetActive ();

private:
    std::string m_kName;
    std::map<std::string,PixelProgram*> m_kEntry;
    ObjectPtr m_spkDefaultPProgram;
    std::string m_kRendererType;
    char m_cCommentChar;

    static const std::string ms_kNullString;
    static const std::string ms_kDefaultString;
    static PixelProgramCatalog* ms_pkActive;
};

}

#endif
