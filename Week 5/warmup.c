#include <stdio.h>

int main() {

	// Array ar[n]
	// int + k
	// print (i,j)
	// i < j 
	// (ar[i] + ar[j]) % k = 0

	int k = 5;
	int n = 6;
	int ar[6] = {1, 2, 3, 4, 5 ,6};

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (i < j && (ar[i] + ar[j]) % k == 0) {
				printf("[%d,%d] \0", ar[i], ar[j]);
			}
		}
	}


	return 0;
}