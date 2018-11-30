#include "accumulator.h"

accumulator *initialize_accumulator(void) {
	accumulator *acc = malloc(sizeof(accumulator));
	acclist = malloc(sizeof(int));
	accsize = 0;
	return acc;
}
