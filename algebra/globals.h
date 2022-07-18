#ifndef GLOBALS_H
#define GLOBALS_H

#include "stdio.h"
#include "stdlib.h"

#define MAX_VARS 100;
#define FREE_POINTERS_THEN_EXIT  free_all(); printf("\n"); return 0


void* new_pointer(size_t _size);

void free_all();

void free_pointer(void* p);

#endif
