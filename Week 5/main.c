#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main() {
	Node * head = (Node *)malloc(sizeof(Node));
	head->data = 5;
	head->next = NULL;
	append(&head, 10);
	append(&head, 15);
	append(&head, 55);
	print(head);
	return 0;
}