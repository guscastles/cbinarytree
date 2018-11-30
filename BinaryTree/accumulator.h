#pragma once
#include <malloc.h>
#define acclist acc->list
#define accsize acc->size
#define expand_accumulator(acc) \
		((int*) realloc(acc->list, sizeof(int) * (acc->size + 1)))

struct accum_list {
	int *list;
	size_t size;
};

typedef struct accum_list accumulator;

accumulator *initialize_accumulator(void);
