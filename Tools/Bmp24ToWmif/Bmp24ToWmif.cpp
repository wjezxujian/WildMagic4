// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include <windows.h>
#include "Bmp24ToWmif.h"
using namespace std;

WM4_CONSOLE_APPLICATION(Bmp24ToWmif);

//----------------------------------------------------------------------------
void Bmp24ToWmif::Usage ()
{
    cout << endl;
    cout << "To convert Windows BITMAP format to Wild Magic Image" << endl;
    cout << "Format (wmif), use" << endl;
    cout << "    Bmp24ToWmif myfile.bmp [myfile.alpha.bmp]" << endl;
    cout << "The BITMAP myfile.bmp is a 24-bit image that stores RGB" << endl;
    cout << "components.  If you want an alpha channel, supply" << endl;
    cout << "myfile.alpha.bmp, a 24-bit BITMAP image that is gray" << endl;
    cout << "scale (R = G = B).  The common channel value is used as" << endl;
    cout << "the alpha channel of the output image, myfile.wmif." << endl;
}
//----------------------------------------------------------------------------
int Bmp24ToWmif::GetImage (const char* acBMPName, int& riWidth, int& riHeight,
    unsigned char*& raucData)
{
    riWidth = 0;
    riHeight = 0;
    raucData = 0;

    HBITMAP hImage = (HBITMAP) LoadImage(NULL,acBMPName,IMAGE_BITMAP,0,0,
        LR_LOADFROMFILE | LR_CREATEDIBSECTION);

    if (!hImage)
    {
        return -2;
    }

    DIBSECTION dibSection;
    GetObject(hImage,sizeof(DIBSECTION),&dibSection);

    riWidth = dibSection.dsBm.bmWidth;
    riHeight = dibSection.dsBm.bmHeight;
    if (dibSection.dsBm.bmBitsPixel != 24)
    {
        return -3;
    }

    // Windows pads the rows of the BMP to be 4-byte aligned.
    int iRowSize = 3*riWidth;
    if ((iRowSize % 4) != 0)
    {
        iRowSize += 4 - (riWidth % 4);
    }

    // allocate the WMIF image
    raucData = WM4_NEW unsigned char[3*riWidth*riHeight];
    memset(raucData,0,3*riWidth*riHeight);

    // Windows BMP stores BGR, need to invert to RGB.
    unsigned char* aucOldRow = (unsigned char*)dibSection.dsBm.bmBits;
    unsigned char* aucNewRow = raucData;
    for (int iY = 0; iY < riHeight; iY++)
    {
        System::Memcpy(aucNewRow,3*riWidth,aucOldRow,3*riWidth);
        for (int iX = 0; iX < riWidth; iX++)
        {
            unsigned char ucB = aucNewRow[3*iX  ];
            unsigned char ucR = aucNewRow[3*iX+2];
            aucNewRow[3*iX  ] = ucR;
            aucNewRow[3*iX+2] = ucB;
        }
        aucOldRow += iRowSize;
        aucNewRow += 3*riWidth;
    }

    DeleteObject(hImage);

    return 0;
}
//----------------------------------------------------------------------------
int Bmp24ToWmif::Main (int iArgQuantity, char** aacArgument)
{
    if (iArgQuantity <= 1)
    {
        Usage();
        return -1;
    }

    // Get RGB input file.  The filename must have extension ".bmp", so the
    // filename is at least 5 characters long.
    const char* acRGBFile = aacArgument[1];
    const size_t uiRGBFileSize = strlen(acRGBFile);
    if (uiRGBFileSize < 5)
    {
        return -2;
    }
    const char* acRGBFileExt = acRGBFile + uiRGBFileSize - 4;
    if (acRGBFileExt[0] != '.'
    ||  tolower(acRGBFileExt[1]) != 'b'
    ||  tolower(acRGBFileExt[2]) != 'm'
    ||  tolower(acRGBFileExt[3]) != 'p')
    {
        return -3;
    }

    // Generate the image name without an extension.
    std::string kImageName;
    int i;
    for (i = 0; i < (int)uiRGBFileSize - 4; i++)
    {
        kImageName += acRGBFile[i];
    }

    int iRGBWidth, iRGBHeight;
    unsigned char* aucRGBData;
    int iErrorCode = GetImage(acRGBFile,iRGBWidth,iRGBHeight,aucRGBData);
    if (iErrorCode != 0)
    {
        WM4_DELETE[] aucRGBData;
        return iErrorCode;
    }

    // The input file is SomeFile.bmp.  Allocate enough space to change
    // this to SomeFile.wmif.
    const size_t uiDstSize = strlen(acRGBFile) + 2;
    char* acWmifName = new char[uiDstSize];
    System::Strcpy(acWmifName,uiDstSize,acRGBFile);
    char* acWmifFileExt = acWmifName + uiDstSize - 5;
    acWmifFileExt[0] = 'w';
    acWmifFileExt[1] = 'm';
    acWmifFileExt[2] = 'i';
    acWmifFileExt[3] = 'f';
    acWmifFileExt[4] = 0;

    if (iArgQuantity <= 2)
    {
        // create and save the RGB image to disk
        Image* pkRGBImage = WM4_NEW Image(Image::IT_RGB888,iRGBWidth,
            iRGBHeight,aucRGBData,acRGBFile);
        if (!pkRGBImage)
        {
            WM4_DELETE[] aucRGBData;
            return -6;
        }
        if (!pkRGBImage->Save(acWmifName))
        {
            WM4_DELETE pkRGBImage;
            return -7;
        }
        WM4_DELETE pkRGBImage;
        return 0;
    }

    // get A input file
    const char* acAFile = aacArgument[2];
    int iAWidth, iAHeight;
    unsigned char* aucAData;
    iErrorCode = GetImage(acAFile,iAWidth,iAHeight,aucAData);
    if (iErrorCode != 0)
    {
        WM4_DELETE[] aucRGBData;
        WM4_DELETE[] aucAData;
        return iErrorCode;
    }
    if (iAWidth != iRGBWidth || iAHeight != iRGBHeight)
    {
        WM4_DELETE[] aucRGBData;
        WM4_DELETE[] aucAData;
        return -8;
    }

    int iWidth = iRGBWidth, iHeight = iRGBHeight;
    int iQuantity = iWidth*iHeight;
    unsigned char* aucData = WM4_NEW unsigned char[4*iQuantity];
    for (i = 0; i < iQuantity; i++)
    {
        aucData[4*i  ] = aucRGBData[3*i  ];
        aucData[4*i+1] = aucRGBData[3*i+1];
        aucData[4*i+2] = aucRGBData[3*i+2];
        aucData[4*i+3] = aucAData[3*i];  // use the R channel for alpha
    }
    WM4_DELETE[] aucRGBData;
    WM4_DELETE[] aucAData;

    Image* pkRGBAImage = WM4_NEW Image(Image::IT_RGBA8888,iWidth,iHeight,
        aucData,acRGBFile);
    if (!pkRGBAImage)
    {
        WM4_DELETE[] aucData;
        return -9;
    }
    if (!pkRGBAImage->Save(acWmifName))
    {
        WM4_DELETE pkRGBAImage;
        return -10;
    }
    WM4_DELETE pkRGBAImage;
    return 0;
}
//----------------------------------------------------------------------------
