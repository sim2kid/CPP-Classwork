#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int * c, size_t count) {
	for (int i = 0; i < count; i++) {
		int t = c[i];
		printf("%d\n\0", t);
	}
}

void boo(int * num) {
	*num += 10;
}

void bar(int num) {
	num += 10;
}

int main() {
	int c[10];

	size_t size = sizeof(c) / sizeof(int);
	foo(c, 10);
	printf("\n%d\n\n\0", size);

	char * hello = "Ohayou Sekai\0";
	char * goodbye = "Sayonara Sekai\0";
	size_t s = strleng(hello);

	if (strcmp(hello, goodbye) == 1) {
		//Same
	}
	else 
	{
		//Different
	}

	int i = 100;
	boo(&i);
	int y = 100;
	bar(y);
	printf("i: %d y: %d", i, y);

	return 0;
}

