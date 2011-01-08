/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#ifdef _WIN32
/* On Windows we need windows.h */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <SDL/SDL_main.h>
#endif
/* OS X has to be different for some reason */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <SDL/SDL.h>

