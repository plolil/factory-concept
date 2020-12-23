#include "main.h"

int hello(void*a, void*b, void*c) {
	printf("Hello, World!");
	return 0;
}

//take CLI flags.
int main(int argc, char ** argv) {
	//store whether we should exit
	SDL_bool quit = SDL_FALSE;
	//events (typing, window closed, clicks, etc.) get stored in this when its time to handle them
	SDL_Event event;

	//initialize SDL2 and the font renderer
	SDL_Init(SDL_INIT_VIDEO); TTF_Init();

	//load the font. 
	TTF_Font * font = TTF_OpenFont("assets/font.ttf", 32);
	//open a window at 640*480 with no specified position. give it the title "factory game"
	SDL_Window * screen = SDL_CreateWindow("Factory Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	//assign a renderer to the window.
	SDL_Renderer * renderer = SDL_CreateRenderer(screen, -1, 0);
	//consistant framerate
	Uint32 end = SDL_GetTicks();
	Uint32 fps = 1;
	Uint32 timeperframe = 1000 / fps;
	TASKS_taskstore *test = TASKS_newstore();
 	while (!quit){
		//event handling. its in a while loop so that all present events get handled.
		while (SDL_PollEvent(&event)) {
			switch (event.type){
				//quit when the window is closed
				case SDL_QUIT:
					quit = SDL_TRUE;
					break;
				case SDL_KEYDOWN:
					TASKS_pushtask(test, hello, NULL, NULL, NULL, 0);
					printf("test");
					break;
			}
		}
		//if it's been 1/60 of a second, redraw the screen.
		if(SDL_TICKS_PASSED(SDL_GetTicks(), end)) {
			SDL_RenderClear(renderer);
			end = SDL_GetTicks() + timeperframe;
		}
	}
	TASKS_killstore(test);
	//unload everything
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	TTF_CloseFont(font);
	//deinitialize libraries
	TTF_Quit();
	SDL_Quit();
	//exit.
	return 0;
}
