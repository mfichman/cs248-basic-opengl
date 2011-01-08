CS 248 Basic OpenGL Demo
========================

Example of basic OpenGL rendering with SDL. [Download here.](https://github.com/mfichman/cs248-basic-opengl/zipball/master)

Building/Running the Demo
------------------------
To get the demo to work, you have to install the SDL library on your machine.  The myth.stanford.edu machines already have SDL installed, but if you want to use your own machine, then download SDL as instructed below.  However, if you're running Windows, the SDL binaries are included.

[demo-folder] = demo root folder

### Linux (Ubuntu or similar)

1. sudo apt-get install libsdl-dev
2. cd [demo-folder]
4. make
5. ./main

### OS X

1. [Get the SDL disk image and open it](http://www.libsdl.org/release/SDL-1.2.14.dmg)
2. Copy SDL.framework to /Library/Frameworks
3. Open the XCode project in "xcode" and run

### Windows

1. Open demo/demo.sln, and click Build > Start Debugging

