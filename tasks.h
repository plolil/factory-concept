#ifndef TASKS_H
#define TASKS_H

//set a default max number of tasks per list. redefine before you include this to change it
#ifndef TASKLIMIT
#define TASKLIMIT 512
#endif

//type for storing the ID of a task
typedef unsigned int TASKS_taskid;

typedef struct task {
	//the function to be run by the task
	int * funcptr;
	//what entity(if any) is affected
	void * affected;
	//extra args for changing behavior
	int * extraA;
	int * extraB;
	//is this a valid queue item, or has it been completed and is therefore open
	char valid;
	//should a thread try to complete this, or is it already in progress
	char inprogress;
	//task ID. used for marking as complete.
	TASKS_taskid id;
} TASKS_task;

typedef struct taskstore {
	//store a list of tasks
	TASKS_task tasklist[TASKLIMIT];
	//keep track of how many tasks there are. this will block if it gets filled.
	int numtasks;
} TASKS_taskstore;

//function to generate and allocate a new taskstore
TASKS_taskstore *TASKS_newstore();
//function to add a task
int TASKS_pushtask(TASKS_taskstore* store, int * func, void * target, int * paramA, int * paramB);
//function to complete and remove a task
int TASKS_poptask();


#endif