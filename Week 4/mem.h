#ifndef MEM_H
#define MEM_H
#include <stdlib.h>

typedef struct my_array {
	int * data;
	size_t size;
} array;

array * init(int *, size_t size);
void destroy(array *);

#endif