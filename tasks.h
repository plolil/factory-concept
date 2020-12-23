#ifndef TASKS_H
#define TASKS_H

#include <SDL2/SDL.h>

//set a default max number of tasks per list. redefine before you include this to change it
#ifndef TASKLIMIT
#define TASKLIMIT 1024
#endif

//type for storing the ID of a task
typedef unsigned int TASKS_taskid;

typedef int (*TASKS_taskfunc)(void*, void*, void*);

typedef struct task {
	//the function to be run by the task
	TASKS_taskfunc funcptr;
	//what entity(if any) is affected
	void * affected;
	//extra parameters. can be used to pass pointers.
	void * extraA;
	void * extraB;
	//is this a valid queue item, or has it been completed and is therefore open
	SDL_bool valid;
	//should a thread try to complete this, or is it already in progress
	SDL_bool inprogress;
	//task ID. used for marking as complete.
	TASKS_taskid id;
	//the tick that this is to be executed on.
	unsigned long tick;
} TASKS_task;

typedef struct taskstore {
	//store a list of tasks
	TASKS_task tasklist[TASKLIMIT];
	//keep track of how many tasks there are. this will block if it gets filled.
	int numtasks;
	//used for timing. will not increment until all tasks for this tick are finished.
	unsigned long tick;
	//used to handle atomic operations
	SDL_bool safe;
	//hold threads. each runs tasks.
	SDL_Thread * Athread;
	SDL_Thread * Bthread;
	//manager thread. handles ticks and entity updates.
	SDL_Thread * Facilitator;
	//exit value. used when cleanly shutting down a tasklist. Threads will complete their current task before exiting. Do not directly edit this.
	SDL_bool exit;
	//each thread increments this when it's ready. when this is equal to 3, all threads are working. newstore will not return until all threads are ready.
	unsigned char ready;
} TASKS_taskstore;

//declare the threads above.
int facilitate(void* in);
int handle(void* in);

//function to generate and allocate, and start the threads for a new taskstore.
TASKS_taskstore *TASKS_newstore();
//function to add a task
int TASKS_pushtask(TASKS_taskstore* store, int * func, void * target, void * paramA, void * paramB, int delay);
//function to complete and remove a task
int TASKS_poptask();
//function to cleanly disable, deallocate, and delete a taskstore
int TASKS_killstore(TASKS_taskstore* store);


#endif