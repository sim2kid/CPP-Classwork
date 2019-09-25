#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mem.h"

/*
int * foo() {
	return (int *)malloc(sizeof(int));
}

void bar(int * i) {
	*i = 10;
	free(i);
}

int main() {
	//int *i = (int *)malloc(sizeof(int));
	int *z = foo();
	bar(z);
	printf("%d\0", *z);
	return 0;
}
*/

int main() {
	size_t size = (BUFFER_SIZE * sizeof(int));
	//int * data = (int *)malloc(size);
	array * my_array = init(size);

	int local[BUFFER_SIZE] = {1,2,3,4,5};
	my_array->data = &local;

	///

	destroy(my_array);
	return 0;
}