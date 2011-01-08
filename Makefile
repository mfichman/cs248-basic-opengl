main: main.o
	$(CC) -o $@ $^ -lGL -lGLU -lSDL
