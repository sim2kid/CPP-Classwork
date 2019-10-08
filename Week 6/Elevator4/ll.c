#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void push(Node ** list, int data) {
    if(list == NULL) { return; }
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

    Node * point = *list;

	if (point == NULL) { // If the list is empty, create the first point //
		point = new_node;
		return;
	}

	while (point->next != NULL) { // Move to end of Linked List //
		point = point->next;
	}

    point->next = new_node; // Point the last point to new node //
	return;
}

void pop(Node ** list, int data) {
    Node * point = *list;
    Node * lastPoint = NULL;

    if (point == NULL) { // If the list is empty, return right away //
		return;
	}

    int loop = 1;

    while (loop == 1) { // loop through list via point.
        if(point->next == NULL) {
            loop = 0;
        }
        
        if(point->data != -1) {
            if(point->data == data) {
                if(point->next != NULL) {
                    lastPoint->next = point->next;
                    free(point);
                    point = lastPoint->next;
                } else {
                    lastPoint->next = NULL;
                    free(point);
                    return;
                }
            } else {
                lastPoint = point;
                point = point->next;
            }
        } else {
            lastPoint = point;
            point = point->next;
        }
	}
	return;
}

int has(Node ** list, int data) {
    Node * point = *list;

    if (point == NULL) { // If the list is empty, return false right away //
		return 0;
	}

    int loop = 1;

    while (loop == 1) { // loop through list via point.
        if(point->next == NULL) {
            loop = 0;
        }
        
        if(point->data != -1) {
            if(point->data == data) {
                return 1;
            }
        }
        point = point->next;
	}
	return 0;
}

void print(Node * point) {
    //printf("List: \n\0");
	while (point != NULL) {
		//printf("Address: %d | Data: %d | Next: %d\n\0", point, point->data, point->next);
        if(point->data != -1)
            printf("%d, \0", point->data);
		point = point->next;
	}
    printf("\n\0");
}