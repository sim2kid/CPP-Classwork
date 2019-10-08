#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main() {
    printf("TEST\n");
    Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = 0;
	new_node->next = NULL;

    Node ** list = &new_node;

    printf("1\n");
    push(list, 1);
    printf("Main's List Points To Address: %d \n\0", *list);

    printf("2\n");
	push(list, 2);
    printf("Main's List Points To Address: %d \n\0", *list);

    printf("3\n");
	push(list, 3);
    printf("Main's List Points To Address: %d \n\0", *list);

	return 0;
}