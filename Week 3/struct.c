#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point {
	int x;
	int y;
};

int main() {
	struct point *z = (struct *)malloc(sizeof(struct point));
	struct point p = { .x = 10, .y = 10};

}