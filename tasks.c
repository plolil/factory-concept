#include "tasks.h"

TASKS_taskstore *TASKS_newstore() {
	TASKS_taskstore *returner = SDL_calloc(1, sizeof(TASKS_taskstore));
	returner->safe = SDL_TRUE;
	returner->tick = 0;
	returner->numtasks = 0;
	return returner;
}

int TASKS_pushtask(TASKS_taskstore* store, int * func, void * target, int * paramA, int * paramB, int delay) {
	SDL_bool pushed = SDL_FALSE;
	for(int i = 0; i < TASKLIMIT; i++) {
		if (store->tasklist[i].valid == SDL_FALSE) {
			pushed = SDL_TRUE;
			store->tasklist[i].funcptr = func;
			store->tasklist[i].affected = target;
			store->tasklist[i].extraA = paramA;
			store->tasklist[i].extraB = paramB;
			store->tasklist[i].id = i;
			store->tasklist[i].tick = store->tick + delay;
			store->tasklist[i].valid = SDL_TRUE;
		}
	}
	if (pushed) {return 0;} else {return -1;}
}

int TASKS_poptask(TASKS_taskstore* store) {

}