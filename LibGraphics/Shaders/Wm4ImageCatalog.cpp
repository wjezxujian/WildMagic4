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
#include "Wm4ImageCatalog.h"
#include "Wm4Image.h"
using namespace Wm4;

const std::string ImageCatalog::ms_kNullString("");
const std::string ImageCatalog::ms_kDefaultString("Default");
ImageCatalog* ImageCatalog::ms_pkActive = 0;

//----------------------------------------------------------------------------
ImageCatalog::ImageCatalog (const std::string& rkName)
    :
    m_kName(rkName)
{
    // A magenta image to catch your attention that your requested image was
    // not found.
    unsigned char* aucData = WM4_NEW unsigned char[3];
    aucData[0] = 255;
    aucData[1] = 0;
    aucData[2] = 255;
    m_spkDefaultImage = WM4_NEW Image(Image::IT_RGB888,1,aucData,
        ms_kDefaultString.c_str());
}
//----------------------------------------------------------------------------
ImageCatalog::~ImageCatalog ()
{
}
//----------------------------------------------------------------------------
const std::string& ImageCatalog::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
bool ImageCatalog::Insert (Image* pkImage)
{
    if (!pkImage)
    {
        assert(false);
        return false;
    }

    std::string kImageName(pkImage->GetName());
    if (kImageName == ms_kNullString
    ||  kImageName == ms_kDefaultString
    ||  pkImage == m_spkDefaultImage)
    {
        return false;
    }

    // Attempt to find the image in the catalog.
    std::map<std::string,Image*>::iterator pkIter = m_kEntry.find(kImageName);
    if (pkIter != m_kEntry.end())
    {
        // The image already exists in the catalog.
        return true;
    }

    // The image does not exist in the catalog, so insert it.
    m_kEntry.insert(std::make_pair(kImageName,pkImage));
    return true;
}
//----------------------------------------------------------------------------
bool ImageCatalog::Remove (Image* pkImage)
{
    if (!pkImage)
    {
        assert(false);
        return false;
    }

    std::string kImageName(pkImage->GetName());
    if (kImageName == ms_kNullString
    ||  kImageName == ms_kDefaultString
    ||  pkImage == m_spkDefaultImage)
    {
        return false;
    }

    // Attempt to find the image in the catalog.
    std::map<std::string,Image*>::iterator pkIter = m_kEntry.find(kImageName);
    if (pkIter == m_kEntry.end())
    {
        // The image does not exist in the catalog.
        return false;
    }

    // The image exists in the catalog, so remove it.
    m_kEntry.erase(pkIter);
    return true;
}
//----------------------------------------------------------------------------
Image* ImageCatalog::Find (const std::string& rkImageName)
{
    if (rkImageName == ms_kNullString 
    ||  rkImageName == ms_kDefaultString)
    {
        return StaticCast<Image>(m_spkDefaultImage);
    }

    // Attempt to find the image in the catalog.
    std::map<std::string,Image*>::iterator pkIter =
        m_kEntry.find(rkImageName);
    if (pkIter != m_kEntry.end())
    {
        // The image exists in the catalog, so return it.
        return pkIter->second;
    }

    // Attempt to load the image from disk.
    Image* pkImage = Image::Load(rkImageName.c_str());
    if (pkImage)
    {
        // The image exists on disk and is already in the catalog.  The
        // (name,image) pair was automatically inserted into m_kEntry by
        // Image::Load, so there is no need to insert it again
        // explicitly.
        return pkImage;
    }

    // The image does not exist.  Use the default image.
    return StaticCast<Image>(m_spkDefaultImage);
}
//----------------------------------------------------------------------------
bool ImageCatalog::PrintContents (const std::string& rkFilename) const
{
    const char* acDecorated = System::GetPath(rkFilename.c_str(),
        System::SM_WRITE);

    if (acDecorated)
    {
        std::ofstream kOStr(acDecorated);
        assert(kOStr);

        std::map<std::string,Image*>::const_iterator pkIter;
        for (pkIter = m_kEntry.begin(); pkIter != m_kEntry.end(); pkIter++)
        {
            Image* pkImage = pkIter->second;
            kOStr << pkIter->first << ":" << std::endl;
            kOStr << "    dimension = " << pkImage->GetDimension()
                << std::endl;
            for (int i = 0; i < pkImage->GetDimension(); i++)
            {
                kOStr << "    bound(" << i << ") = " << pkImage->GetBound(i)
                    << std::endl;
            }
            kOStr << "    format = " << pkImage->GetFormatName() << std::endl;
            kOStr << std::endl;
        }
        kOStr.close();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void ImageCatalog::SetActive (ImageCatalog* pkActive)
{
    ms_pkActive = pkActive;
}
//----------------------------------------------------------------------------
ImageCatalog* ImageCatalog::GetActive ()
{
    return ms_pkActive;
}
//----------------------------------------------------------------------------
