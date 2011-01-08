AC_INIT([cs248-opengl-demo], [1.0], [mfichman@stanford.edu])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CC
AC_PROG_OBJC

AC_CHECK_LIB([SDL], [SDL_Init])
AC_CHECK_LIB([GL], [glEnable])
AC_CHECK_HEADERS([OpenGL/gl.h GL/gl.h])
AC_CHECK_HEADERS([SDL/SDL.h])

AC_CHECK_FILE(/Library/Frameworks/,
  [LDFLAGS+="-framework OpenGL `sdl-config --libs`"],
  []
)

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
