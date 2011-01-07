/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#include "config.h"

#include <SDL/SDL.h>

#ifdef WINDOWS
/* On Windows we need windows.h */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#endif

#ifdef HAVE_OPENGL_GL_H 
/* OS X has to be different for some reason */
#include <OpenGL/gl.h>
#endif

#ifdef HAVE_GL_GL_H
#include <GL/gl.h>
#endif
