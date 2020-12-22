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
	//hold threads. each runs tasks. this is mainly for long running (blocking) operations, but im gonna make everything do it.
	SDL_Thread * Athread;
	SDL_Thread * Bthread;
	SDL_Thread * Cthread;
	//a taskstore for anything to be run. see "tasks.h" for more.
	TASKS_taskstore queue;
} ENGINE_engine;

#endif