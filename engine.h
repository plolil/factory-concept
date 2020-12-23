#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>

#include "tasks.h"

typedef struct engine {
	//store the window to interact with
	SDL_Window * window;
	//store the renderer to use
	SDL_Renderer * renderer;
	//a taskstore for anything non-critical to be run. see "tasks.h" for more.
	TASKS_taskstore queue;
} ENGINE_engine;

#endif