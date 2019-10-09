#include <stdio.h>
#include <stdlib.h>


int hasColor(int * arr, int color, int length) {
	for (int i = 0; i < length; i++) {
		if (*((arr+i*2) + 0) == color) {
			//printf("%d - %d \n", i, color);
			return i;
		}
	}
	return -1;
}


void addColor(int * arr, int color, int length) {
	for (int i = 0; i < length; i++) {
		//printf("%d) %d - %d | %d\n", i, *((arr + i * 2) + 0), *((arr + i * 2) + 1), color);
		if (*((arr + i * 2) + 0) == 0) {
			*((arr + i * 2) + 0) = color;
			*((arr + i * 2) + 1) += 1;
			return;
		}
	}
	return;
}

int main() {
	int n = 20;
	int ar[20];

	printf("{ \0");
	for (int i = 0; i < n; i++) {
		ar[i] = rand() % (5 - 1) + 1;
		printf("%d\0", ar[i]);
		if (i + 1 < n)
			printf(", \0");
	}
	printf(" }\n\0");

	int re[20][2];
	for (int col = 0; col < n; col++) {
		for (int row = 0; row < 2; row++) {
			re[col][row] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		int loc = hasColor((int *)re, ar[i], n);
		//printf("%d) color %d at loc %d\n", i, ar[i], loc);
		if (loc == -1) {
			addColor((int *)re, ar[i], n);
		}
		else {
			re[loc][1] += 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (re[i][0] != 0) {
			printf("Color %d has %d pairs and %d left over socks.\n\0", re[i][0], (int) (re[i][1]/2), re[i][1]%2);
		}
		//printf("%d: %d - %d\n\0", i, re[i][0], re[i][1]);
	}
}
