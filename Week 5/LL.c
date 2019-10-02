#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void append(Node ** head, int data) {
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	Node * last = *head;

	if (last == NULL) {
		*head = new_node;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return;
}

void print(Node * head) {
	while (head != NULL) {
		printf("%d\n\0", head->data);
		head = head->next;
	}
}