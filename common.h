/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#include <SDL/SDL.h>

#ifdef WINDOWS
/* On Windows we need windows.h */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#ifdef OSX 
/* OS X has to be different for some reason */
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif
