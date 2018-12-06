/*
Geometric Tools OpenGL Encapsulator, Version 1 (May 2006)
Geometric Tools, Inc.
http://www.geometrictools.com
*/

#include <mach-o/dyld.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------------*/
void* GTGetFunctionPointer (const char* acFunction)
{
    NSSymbol kSymbol;
    char* acSymbolName;

    /* Prepend a '_' for the Unix C symbol mangling convention. */
    acSymbolName = malloc(strlen((const char*)acFunction) + 2);
    strcpy(acSymbolName+1,(const char*)acFunction);
    acSymbolName[0] = '_';

    kSymbol = 0;
    if (NSIsSymbolNameDefined(acSymbolName))
	{
        kSymbol = NSLookupAndBindSymbol(acSymbolName);
	}

    free(acSymbolName);
    return kSymbol ? NSAddressOfSymbol(kSymbol) : 0;
}
/*--------------------------------------------------------------------------*/
