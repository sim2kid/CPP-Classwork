#ifndef MEM_H
#define MEM_H
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct my_array {
	int * data;
	size_t size;
} array;

array * init(const size_t size);
void destroy(array *);

#endif