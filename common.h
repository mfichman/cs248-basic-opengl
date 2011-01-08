/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#ifdef _WIN32
/* On Windows we need windows.h */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <SDL_main.h>
#include <SDL.h>
#endif
/* OS X has to be different for some reason */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL/SDL.h>
#endif

#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#endif


