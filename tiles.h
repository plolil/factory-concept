#ifndef TILES_H
#define TILES_H

#include <SDL2/SDL.h>

#include "genericdefs.h"

#ifndef TILES_CHUNK_SIZE
#define TILES_CHUNK_SIZE 32
#endif

#ifndef TILES_LOADED_MAP_SIZE
#define TILES_LOADED_MAP_SIZE 512
#endif

#ifndef TILES_TYPES
#define TILES_TYPES 512
#endif

typedef unsigned int TILES_id;

typedef struct tile {
	TILES_id id;
} TILES_tile;

typedef struct chunk {
	TILES_tile tiles[TILES_CHUNK_SIZE][TILES_CHUNK_SIZE];
} TILES_chunk;

typedef struct meta {
	TILES_id id;
	char filename[50];
	SDL_Surface * image;
} TILES_meta;

typedef struct tilebindings {
	TILES_meta tiles[TILES_TYPES];
} TILES_bindings;

typedef struct map {
	TILES_chunk chunks[TILES_LOADED_MAP_SIZE][TILES_LOADED_MAP_SIZE];
} TILES_map;

#endif

//TILES_tile