#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>

typedef struct engine {
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Thread * Athread;
	SDL_Thread * Bthread;
	SDL_Thread * Cthread;
} ENGINE_engine;

#endif