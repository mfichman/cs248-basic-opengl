CS 248 Basic OpenGL Demo
========================

Example of basic OpenGL rendering with SDL. [Download here.](https://github.com/mfichman/cs248-basic-opengl/zipball/master)

Building/Running the Demo
------------------------
To get the demo to work, you have to install the SDL library on your machine.  The myth.stanford.edu machines already have SDL installed, but if you want to use your own machine, then follow the instructions for your platform below.

### Windows

1. [Get the binaries](http://www.libsdl.org/release/SDL-1.2.14-win32.zip)
2. Unzip the file in the demo root directory
3. Open the VS2008 project, and build from the menu

### OS X

1. [Get the disk image](http://www.libsdl.org/release/SDL-1.2.14.dmg)
2. Copy SDL.framework to /Library/Frameworks
3. cd [demo-folder]
4. ./configure
5. make

### Linux (Ubuntu or similar)

1. sudo apt-get install libsdl-dev
2. cd [demo-folder]
3. ./configure
4. make

