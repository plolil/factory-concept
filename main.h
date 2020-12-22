#ifndef MAIN_H
#define MAIN_H
//SDL normally redirects all stdout writes to a file. this makes debugging a pain. disable this on finished builds because windows is wierd.
#define NO_STDIO_REDIRECT

//include SDL2 headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_image.h>

//include misc. headers
#include <stdio.h>

//include the engine.
#include "engine.h"

#endif
