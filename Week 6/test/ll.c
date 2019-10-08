#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

Node ** push(Node ** list, int data) {
    if(list != NULL) {printf("List Points To Address: %d \n\0", *list);}
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
    printf("\nnew_node: Address: %d | Data: %d | Next: %d\n\0", new_node, new_node->data, new_node->next);

    Node * point = NULL;
    if(list != NULL) {
        point = *list;
        printf("point:    Address: %d | Data: %d | Next: %d\n\n\0", point, point->data, point->next);
    }

	if (point == NULL) { // If the list is empty, create the first point //
		list = &new_node;
        printf("Added1 \n");
        printf("new_node: Address: %d | Data: %d | Next: %d\n\0", new_node, new_node->data, new_node->next);
        printf("List Points To Address: %d \n\0", *list);
		return list;
	}

	while (point->next != NULL) { // Move to end of Linked List //
        printf("\nIn Loop -- ");
        printf("point:    Address: %d | Data: %d | Next: %d\n\0", point, point->data, point->next);
		point = point->next;
	}

	printf("new_node: Address: %d | Data: %d | Next: %d\n\0", new_node, new_node->data, new_node->next);
    printf("point:    Address: %d | Data: %d | Next: %d\n\0", point, point->data, point->next);
    point->next = new_node; // Point the last point to new node //
    printf("Added2 \n");
    printf("point:    Address: %d | Data: %d | Next: %d\n\0", point, point->data, point->next);
    printf("List Points To Address: %d \n\0", *list);
	return;
}