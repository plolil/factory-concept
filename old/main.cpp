#include "main.h"

//a test function, used as a task.
//all tasks must be declared in this format, with the same parameters and type. name is irrelevant tho.
int hello(void*a, void*b, void*c) {
  printf("%s was pressed!\n", (char*) b);
	return 0;
}

//take CLI flags.
int main(int argc, char ** argv) {
	//store whether we should exit
	SDL_bool quit = SDL_FALSE;
	//events (typing, window closed, clicks, etc.) get stored in this when its time to handle them
	SDL_Event event;

	//initialize SDL2
	SDL_Init(SDL_INIT_VIDEO);

	//open a window at 640*480 with no specified position. give it the title "factory game"
	SDL_Window * screen = SDL_CreateWindow("Factory Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	//assign a renderer to the window.
	SDL_Renderer * renderer = SDL_CreateRenderer(screen, -1, 0);
	//consistant framerate
	Uint32 end = SDL_GetTicks();
	Uint32 fps = 1;
	Uint32 timeperframe = 1000 / fps;
	//create a new taskstore
	TASKS_taskstore *mainstore = TASKS_newstore();
 	while (!quit){
		//event handling. its in a while loop so that all present events get handled.
		while (SDL_PollEvent(&event)) {
			switch (event.type){
				//quit when the window is closed
				case SDL_QUIT:
					quit = SDL_TRUE;
					break;
				//when a key is pressed, schedule a task for 2 seconds(60 ticks) in the future on taskstore 'test'. make the task be the function from above.
				case SDL_KEYDOWN:
				  TASKS_pushtask(mainstore, hello, NULL, (void*) SDL_GetKeyName(event.key.keysym.sym), NULL, 60);
					break;
			}
		}
		//if it's been 1/60 of a second, redraw the screen.
		if(SDL_TICKS_PASSED(SDL_GetTicks(), end)) {
			SDL_RenderClear(renderer);
			end = SDL_GetTicks() + timeperframe;
		}
	}
	//kill the threads and unallocate the taskstore
	TASKS_killstore(mainstore);
	//unload everything
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(screen);
	//deinitialize libraries
	SDL_Quit();
	//exit.
	return 0;
}
