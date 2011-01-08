/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#ifdef _WIN32
/* On Windows we need windows.h */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#else
#include "config.h"
#ifdef HAVE_OPENGL_GL_H 
/* OS X has to be different for some reason */
#include <OpenGL/gl.h>
#endif
#ifdef HAVE_GL_GL_H
#include <GL/gl.h>
#endif
#ifdef HAVE_SDL_SDL_H
#include <SDL/SDL.h>
#endif
#endif
