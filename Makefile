INCLUDE='.'
LIB='./SDL'

%.o: %.c
	gcc -c -o $@ $^ -I$(INCLUDE)

main: main.o
	gcc -o $@ $^ -L$(LIB) -lSDL -lSDLmain \
		-Wl,-framework,OpenGL \
		-Wl,-framework,Cocoa \
		-Wl,-framework,ApplicationServices \
		-Wl,-framework,Carbon \
		-Wl,-framework,AudioToolbox \
		-Wl,-framework,AudioUnit \
		-Wl,-framework,IOKit


clean:
	rm -f *.o main
