all:
	-gcc -g main.c function.c SDL_dialogue.c -o main -lSDL2 -lSDL2_ttf -lSDL2_image
	-gcc -g sdl.c -o sdl -lSDL2 -lSDL2_ttf -lSDL2_image
	