/*
Geometric Tools OpenGL Encapsulator, Version 1 (May 2006)
Geometric Tools, Inc.
http://www.geometrictools.com
*/

#ifndef GTGLPLUGIN_H
#define GTGLPLUGIN_H

/*
The default behavior is to have no additional semantics per OpenGL call.
Replace GTglPlugin.h and, if necessary, add a file GTglPlugin.c that
implements additional semantics.  These can include report-log generation
or profiling.
*/

#define GT_ENTER_FUNCTION(glFunction)
#define GT_NONNULL_FUNCTION(glFunction)
#define GT_NULL_FUNCTION(glFunction)
#define GT_EXIT_FUNCTION(glFunction)

#endif
