#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void currentlySelected(Node ** floors);
int closest(int * up, int onFloor, Node ** floors, int topFloor);
int toggle(int floor, Node ** floors);

int main() {
    int bottemFloor = 1;
    int onFloor = bottemFloor;

    int topFloor = 80;

    Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = -1;
	new_node->next = NULL;

	Node ** floors = &new_node;

    int up = 1;
    int quit = 0;

    while(quit == 0) {
        int gotoFloor = 0;

        printf("\nYou are on floor %d of %d.\nWhat floors would you like to goto?\n(Enter %d to leave) (Enter -1 to close the doors)\n\0", onFloor, topFloor, onFloor);
        currentlySelected(floors);
        printf("> \0");
        
        if(scanf_s("%d", &gotoFloor) != 1) {
            printf("\n\nNon-Ints are not allowed. Get out of my elevator!\n\0");
            break;
        } else if (gotoFloor == -1) {
            // Run Elevator
            gotoFloor = closest(&up, onFloor, floors, topFloor);
            if(gotoFloor != -1) {
                int add = 1;
                if(up == 0) {
                    add = -1;
                }
                printf("\n\0");
                while(onFloor != gotoFloor) {
                    onFloor += add;
                    printf("Now on floor %d.\n\0", onFloor);   
                }
                printf("\nYou have arived at floor %d!\n\0", onFloor);
                toggle(onFloor, floors);
            } else {
                printf("\n\nNo floors have been selected!\n\0");
            }
        } else if(gotoFloor < bottemFloor || gotoFloor > topFloor) {
            // Out Of Bounds
            printf("\n\nThere is no floor %d in this building!\n\0", gotoFloor);
        } else if (gotoFloor == onFloor) {
            // Exit Conditions
            printf("\n\nYou have gotten off The elevator at floor %d\n\0", onFloor);
            quit = 1;
            break;
        } else {
            // Add Number To List
            printf("\n\nYou have pressed floor %d.\n\0", gotoFloor);
            toggle(gotoFloor, floors);
        }
    }
    
    return 0;
}

void currentlySelected(Node ** floors) {
    printf("Floors Selected: \0");
    print(*floors);
}

int closest(int * up, int onFloor, Node ** floors, int topFloor) {
    if ((*up) == 1) {
        int c = topFloor + 1;
        Node * point = *floors;
        while(point != NULL) {
            if(point->data != -1) {
                if(point->data > onFloor && point->data < c) {
                    c = point->data;
                }
            }
            point = point->next;
        }
        if(c == topFloor+1) {
            (*up) = 0;
            c = -1;
            point = *floors;
            while(point != NULL) {
                if(point->data != -1) {
                    if(point->data < onFloor && point->data > c) {
                        c = point->data;
                    }
                }
                point = point->next;
            }
            if(c == -1) {
                return -1;
            } else {
                return c;
            }
        } else {
            return c;
        }
    } 
    if ((*up) == 0) {
        int c = -1;
        Node * point = *floors;
        while(point != NULL) {
            if(point->data != -1) {
                if(point->data < onFloor && point->data > c) {
                    c = point->data;
                }
            }
            point = point->next;
        }
        if(c == -1) {
            (*up) = 1;
            return closest(up, onFloor, floors, topFloor);
        } else {
            return c;
        }
    }
    return -1;
}

int toggle(int floor, Node ** floors) {
    int found = has(floors, floor);
    if(found == 1) {
        pop(floors, floor);
    } else {
        push(floors, floor);
    }

    return found;
}