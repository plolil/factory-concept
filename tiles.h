#ifndef TILES_H
#define TILES_H

#include <SDL2/SDL.h>

#include "genericdefs.h"

#ifndef TILE_CHUNK_SIZE
#define TILE_CHUNK_SIZE 32
#endif

#ifndef LOADED_MAP_SIZE
#define LOADED_MAP_SIZE 512
#endif

typedef unsigned int TILES_id;

typedef struct tile {
	TILES_id id;
} TILES_tile;

typedef struct chunk {
	TILES_tile tiles[TILE_CHUNK_SIZE][TILE_CHUNK_SIZE];
} TILES_chunk;

typedef struct meta {
	TILES_id id;
	char filename[50];
	SDL_RWops * image;
} TILES_meta;

typedef struct tilebindings {
	TILES_id id;
} TILES_bindings;

typedef struct map {
	TILES_chunk chunks[LOADED_MAP_SIZE][LOADED_MAP_SIZE];
} TILES_map;

#endif