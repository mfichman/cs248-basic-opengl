/****************************************************************************
 * OpenGL/GLUT Demo                                                         *
 * CS 248                                                                   *
 ****************************************************************************/

#define WINDOW_WIDTH 800U
#define WINDOW_HEIGHT 600U
#define WINDOW_TITLE "CS248 OpenGL Demo"
#define OSX // WINDOWS, or LINUX

/* To reduce clutter, all the includes are in common.h */
#include "common.h"

void init_sdl();
void init_opengl();
void render_frame();
void render_cube();
void render_triangle();
void handle_input();


int main(int argc, char **argv) {
    init_sdl();
    init_opengl();

    while (1) {
        render_frame();
        handle_input();
    }
    
    return 0;
}

void init_opengl() {
    /* Set the clear color */
    glClearColor(0.15f, 0.15f, 0.15f, 0.0f);

    /* Set up and enable the depth buffer */
    glEnable(GL_DEPTH_TEST);

    /* Set up the projection matrix */
    float aspect_ratio = (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glOrtho(-4*aspect_ratio, 4*aspect_ratio, -4, 4, -4, 4);

    /* This lets us draw vertices from an array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

void render_frame() {
    /* Clear the color and depth buffers */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Draw the triangle on the left side*/
    glPushMatrix();
    glTranslatef(-2, 0, 0);  
    render_triangle();
    glPopMatrix();

    /* Draw the cube with some rotation on the right side */
    glPushMatrix();

    /* EDIT: Timing control for the animation! */
    static unsigned previous_time = 0;
    unsigned current_time = SDL_GetTicks();
    unsigned elapsed_time = current_time - previous_time;
    previous_time = current_time;
	
    /* Make the cube rotate around a little */
    static float angle1 = 0.0f;
    static float angle2 = 0.0f;
    angle1 += 0.1f * elapsed_time;
    angle2 += 0.05f * elapsed_time; 

    glTranslatef(2, 0, 0);
    glRotatef(angle1, 0, 1, 0);
    glRotatef(angle2, 1, 0, 0);
    render_cube();
    glPopMatrix();

    /* Present the frame buffer */
    SDL_GL_SwapBuffers();
}

void render_triangle() {
  glBegin(GL_TRIANGLES);

  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 0.0f);

  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 1.0f, 0.0f);

  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 0.0f);

  glEnd();
}

void render_cube() {
    static GLfloat vertices[] = {
        1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0,
        1.0, 1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0,
        1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0,
        -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0,
        -1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0
    };

    static GLfloat colors[] = {
        0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,
        1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
        1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,
    }; 

    static GLfloat normals[] = {
        0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,
        0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0,
        1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
        0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0,
        0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
        -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0, -1.0, 0.0, 0.0
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), vertices);
    glNormalPointer(GL_FLOAT, sizeof(GLfloat), normals);
    glColorPointer(3, GL_FLOAT, 3*sizeof(GLfloat), colors);

    glDrawArrays(GL_QUADS, 0, sizeof(vertices)/3/sizeof(GLfloat));
}


void init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        exit(-1);
    } 

    /* Set the pixel format (RGBA, 8 pits per color) */
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_WM_SetCaption(WINDOW_TITLE, NULL);

    int mode_flags = SDL_OPENGL; /* | SDL_FULLSCREEN */
    int bits_per_pixel = 0; /* 0 means use the default */

    /* Create the window */
    if (!SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 
        bits_per_pixel, mode_flags)) {

        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError()); 
        exit(-1);
    }
}

void handle_input() {
    /* Input events are added to the input queue.  We check the queue
     * once per frame and handle the events here */
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT: exit(0); break;
            case SDL_KEYDOWN: break;
            case SDL_KEYUP: break;
            case SDL_MOUSEBUTTONDOWN: break;
            case SDL_MOUSEBUTTONUP: break;
            case SDL_MOUSEMOTION: break;
        }
    }
}
