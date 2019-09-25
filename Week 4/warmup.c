#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 10

int main() {
	int smallest = 10, largest = 99;
	int arr[size][size];
	int left = 0, right = 0;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			arr[x][y] = rand() % (largest - smallest) + smallest;
			printf("%d \0", arr[x][y]);
			if (x == y) {
				left += arr[x][y];
			}
			if (x == ((size-1) - y)) {
				right += arr[x][y];
				//printf("(%d) \0", arr[x][y]);
			}
		}
		printf("\n\0");
	}

	printf("\nLeft: %d  |  Right: %d\n\0", left, right);
	printf("Difference: %d\n\0", (int)fabs((double)(left - right)));

	
	return 0;
}