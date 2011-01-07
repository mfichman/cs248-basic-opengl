CS 248 Basic OpenGL Demo
========================

Example of basic OpenGL rendering with SDL. [Download here.](https://github.com/mfichman/cs248-basic-opengl/zipball/master)

Building/Running the Demo
------------------------
To get the demo to work, you have to install the SDL library on your machine.  The myth.stanford.edu machines already have SDL installed, but if you want to use your own machine, then download SDL as instructed below.

[demo-folder] = demo root folder

### Windows

1. [Get the SDL binaries](http://www.libsdl.org/release/SDL-devel-1.2.14-VC8.zip)
2. Copy "SDL-1.2.14" to [demo-folder]
3. Open the VS2008 project, and click Build > Start Debugging

### OS X

1. [Get the SDL disk image and open it](http://www.libsdl.org/release/SDL-1.2.14.dmg)
2. Copy SDL.framework to /Library/Frameworks
3. cd [demo-folder]
4. ./configure
5. make
6. src/main

### Linux (Ubuntu or similar)

1. sudo apt-get install libsdl-dev
2. cd [demo-folder]
3. ./configure
4. make
5. src/main

