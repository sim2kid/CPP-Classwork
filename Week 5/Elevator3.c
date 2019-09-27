#include <stdio.h>
#include <stdlib.h>

int countFloors(int * floors, int maxFloors);
void swap(int * xp, int * yp);
void collapse(int * floors, int maxFloors);
void currentlySelected(int * floors, int topFloor);
int closest(int * up, int onFloor, int * floors, int numOfFloors, int topFloor);
int toggle(int floor, int * floors, int topFloor);

int main() {
    int bottemFloor = 1;
    int onFloor = bottemFloor;

    int topFloor = 80;
    int * floors = (int *)malloc(topFloor);

    int up = 1;

    for(int i = 0; i < topFloor; i++) {
        floors[i] = -1;
    }

    int quit = 0;

    while(quit == 0) {
        int gotoFloor = 0;

        printf("\nYou are on floor %d of %d.\nWhat floors would you like to goto?\n(Enter %d to leave) (Enter -1 to close the doors)\n\0", onFloor, topFloor, onFloor);
        currentlySelected(floors, topFloor);
        printf("> \0");
        
        if(scanf_s("%d", &gotoFloor) != 1) {
            printf("\n\nNon-Ints are not allowed. Get out of my elevator!\n\0");
            break;
        } else if (gotoFloor == -1) {
            // Run Elevator
            gotoFloor = closest(&up, onFloor, floors, countFloors(floors, topFloor), topFloor);
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
                toggle(onFloor, floors, topFloor);
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
            toggle(gotoFloor, floors, topFloor);
        }
    }
    
    return 0;
}

int countFloors(int * floors, int maxFloors) {
    collapse(floors, maxFloors);
    int count = 0;
    for (int i = 0; i < maxFloors; i++) {
		if(floors[i] != -1) {
            count++;
        } else {
            break;
        }
	}
    return count;
}

void swap(int * xp, int * yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void collapse(int * floors, int maxFloors) {
    for(int i = 0; i < maxFloors-1; i++) {
        for(int j = 0; j < maxFloors-i-1; j++) {
            if(floors[j] == -1) {
                swap(&floors[j], &floors[j+1]);
            }
        }
    }
}

void currentlySelected(int * floors, int topFloor) {
    printf("Floors Selected: \0");
    for (int i = 0; i < topFloor; i++) {
        if(floors[i] != -1) {
		    printf("%d, \0", floors[i]);
        }
	}
    printf("\n\0");
}

int closest(int * up, int onFloor, int * floors, int numOfFloors, int topFloor) {
    if ((*up) == 1) {
        int c = topFloor + 1;
        for(int i = 0; i < numOfFloors; i++) {
            if(floors[i] > onFloor && floors[i] < c) {
                c = floors[i];
            }
        }
        if(c == topFloor+1) {
            (*up) = 0;
            c = -1;
            for(int i = 0; i < numOfFloors; i++) {
                if(floors[i] < onFloor && floors[i] > c) {
                    c = floors[i];
                }
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
        for(int i = 0; i < numOfFloors; i++) {
            if(floors[i] < onFloor && floors[i] > c) {
                c = floors[i];
            }
        }
        if(c == -1) {
            (*up) = 1;
            return closest(up, onFloor, floors, numOfFloors, topFloor);
        } else {
            return c;
        }
    }
    return -1;
}

int toggle(int floor, int * floors, int topFloor) {
    int found = 0;

    for (int i = 0; i < topFloor; i++) {
        if(floors[i] == floor) {
		    floors[i] = -1;
            found = 1;
            collapse(floors, topFloor);
            break;
        }
	}

    if(found == 0) {
        int y = countFloors(floors, topFloor);
        floors[y] = floor;
    }

    return found;
}