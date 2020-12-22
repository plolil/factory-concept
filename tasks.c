#include "tasks.h"

TASKS_taskstore *TASKS_newstore() {
	TASKS_taskstore *returner = SDL_calloc(1, sizeof(TASKS_taskstore));
	returner->safe = SDL_TRUE;
	returner->tick = 0;
	returner->numtasks = 0;
	return returner;
}

int TASKS_pushtask(TASKS_taskstore* store, int * func, void * target, int * paramA, int * paramB) {

}

int TASKS_poptask(TASKS_taskstore* store) {

}