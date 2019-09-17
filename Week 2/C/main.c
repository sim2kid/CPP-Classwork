#include <stdio.h>

void print(int num);
void print(float num);

int main(int arc, char ** argv) {
    int i = 23;
    int j = 10;

    printf("Address: %d\n", &i);
    printf("Value: %d\n", i);

    //void *v = &j;

    //printf("What is your age? %d?", *v;
    //scanf("%d", &i);

    printf("Ohayou Sekai, Good Morning World!\n");
    print(10);
    //int
    //short
    //long
    //char
    //void
    //bool?

    return 0;
}

void print(int num) {
    printf("%d\n", num);
}

void print(float num) {
    printf("%d\n", num);
}