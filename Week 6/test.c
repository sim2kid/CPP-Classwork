#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main() {
    Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = -1;
	new_node->next = NULL;
	Node ** list = &new_node;

    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);

	print(*list);
    pop(list, 3);
    pop(list, 5);
    print(*list);

	return 0;
}