#include "tasks.h"

int facilitate(void* in) {
	printf("facilitation time\n");
	TASKS_taskstore * store = in;
	store->ready += 1;
	while (!store->exit) {
		SDL_Delay(1000/30);
		while (store->numtasks > 0) {
			printf("waiting\n");
			SDL_Delay(1);
		}
		//printf("tick!\n");
		store->safe = SDL_FALSE;
		store->tick += 1;
		store->numtasks = 0;
		for (int i = 0; i < TASKS_LIMIT; i++) {
			if (store->tasklist[i].tick <= store->tick && store->tasklist[i].valid) {
				store->numtasks += 1;
			}
		}
		store->safe = SDL_TRUE;
	}
	printf("exiting facilitator\n");
	store->ready -= 1;
	return 0;
}

int handle(void* in) {
	TASKS_taskstore * store = in;
	store->ready += 1;
	while (!store->exit) {
		TASKS_poptask(store);
	}
	printf("exiting handler\n");
	store->ready -= 1;
	return 0;
}

TASKS_taskstore *TASKS_newstore() {
	TASKS_taskstore *returner = SDL_calloc(1, sizeof(TASKS_taskstore));
	returner->safe = SDL_TRUE;
	returner->tick = 0;
	returner->numtasks = 0;
	returner->exit = SDL_FALSE;
	returner->ready = 0;
	returner->popblock = SDL_FALSE;
	returner->Facilitator = SDL_CreateThread(facilitate, "Task Facilitator", returner);
	returner->Athread = SDL_CreateThread(handle, "Task Handler", returner);
	returner->Bthread = SDL_CreateThread(handle, "Task Handler", returner);

	return returner;
}

int TASKS_pushtask(TASKS_taskstore* store, TASKS_taskfunc func, void * target, void * paramA, void * paramB, int delay) {
	SDL_bool pushed = SDL_FALSE;
	for(int i = 0; i < TASKS_LIMIT; i++) {
		printf("%d\n", i);
		if (!store->tasklist[i].valid) {
			pushed = SDL_TRUE;
			store->tasklist[i].funcptr = func;
			store->tasklist[i].affected = target;
			store->tasklist[i].extraA = paramA;
			store->tasklist[i].extraB = paramB;
			store->tasklist[i].id = i;
			store->tasklist[i].tick = store->tick + delay;
			store->tasklist[i].inprogress = SDL_FALSE;
			store->tasklist[i].valid = SDL_TRUE;
			break;
		}
	}
	if (delay == 0) {
		store->numtasks += 1;
	}
	if (pushed) {return 0;} else {return -1;}
}

int TASKS_poptask(TASKS_taskstore* store) {
	if (store->safe) {
//		printf("safe to pop");
		if (store->numtasks > 0 && !store->popblock) {
//			printf("available tasks");
			store->popblock = SDL_TRUE;
			for(int i = 0; i < TASKS_LIMIT; i++) {
				if (store->tasklist[i].valid && !store->tasklist[i].inprogress && store->tasklist[i].tick <= store->tick && store->numtasks - 1 >= 0) {
					printf("popping task %d\n", i);
					store->tasklist[i].inprogress = SDL_TRUE;
					store->tasklist[i].funcptr(store->tasklist[i].affected, store->tasklist[i].extraA, store->tasklist[i].extraB);
					store->tasklist[i].valid = SDL_FALSE;
					store->tasklist[i].inprogress = SDL_FALSE;
					store->numtasks = store->numtasks - 1;
					printf("%d\n", store->numtasks);
					break;
				}
				if (!store->safe || store->exit || store->numtasks <= 0) {
					break;
				}
			}
			store->popblock = SDL_FALSE;
		}
	}
	return 0;
}

int TASKS_killstore(TASKS_taskstore* store) {
	store->exit = SDL_TRUE;
	SDL_WaitThread(store->Athread, NULL);
	SDL_WaitThread(store->Bthread, NULL);
	SDL_WaitThread(store->Facilitator, NULL);
	SDL_free(store);
	return 0;
}