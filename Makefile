all:
	- gcc main.c function.c SDL_dialogue.c -o main -lSDL2 -lSDL2_image -lSDL2_ttf