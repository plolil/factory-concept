#ifndef TASKS_H
#define TASKS_H

typedef struct task {
	int * funcptr;
	void * affected;
	int * extraA;
	int * extraB;
	char valid;
	char inprogress;
	int id;
} TASKS_task;

typedef struct taskstore {
	TASKS_task tasklist[10];
	int numtasks;
} TASKS_taskstore;

typedef unsigned int TASKS_taskid;

TASKS_taskstore *TASKS_newstore();
int TASKS_pushtask(TASKS_taskstore* store, int * func, void * target, int * paramA, int * paramB, TASKS_taskid *);
int TASKS_poptask();


#endif