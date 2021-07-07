
#ifndef GENERICDEFS_H
#define GENERICDEFS_H

typedef union num {
	long long i;
	double f;
} number;


typedef struct Vec2 {
	number x;
	number y;
} Vector2;

#endif