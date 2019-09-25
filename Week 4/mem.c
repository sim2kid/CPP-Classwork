#include "mem.h"

array * init(int * data, const size_t size) {
	array * my_array = (array*)malloc(sizeof(array));
	my_array->data = (int *)malloc(size);
	my_array->size = size
	return my_array;
}

void destroy(array * arr) {
	free(arr->data);
	free(arr);
}