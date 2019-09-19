#include <stdio.h>

int main() {
	unsigned long long a = 0;
	unsigned long long b = 1;

	for (int i = 0; i <= 92; i++) {
		if (i % 2 == 0) {
			printf("%d) %lld\n", i, a);
			a = a + b;
		}
		else { 
			printf("%d) %lld\n", i, b);
			b = a + b;
		}
	}
	return 0;
}