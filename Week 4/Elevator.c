#include <stdio.h>

int main() {
    int bottemFloor = 1;
    int onFloor = bottemFloor;
    int topFloor = 30;

    while(1 == 1) {
        int gotoFloor = 0;

        printf("\nYou are on floor %d of %d.\nWhat floor would you like to goto?\n(Enter %d to leave)\n> ", onFloor, topFloor, onFloor);
        
        if(scanf_s("%d", &gotoFloor) != 1) {
            printf("\nNon-Ints are not allowed. Get out of my elevator!\n");
            break;
        } else if(gotoFloor < bottemFloor || gotoFloor > topFloor) {
            // Out Of Bounds
            printf("\nThere is no floor %d in this building!\n", gotoFloor);
        } else if (gotoFloor == onFloor) {
            // Exit Conditions
            printf("\nYou have gotten off The elevator at floor %d\n", onFloor);
            break;
        } else {
            // Normal Elevator Operations
            int add = 1;
            if(gotoFloor < onFloor) {
                add = -1;
            }
            printf("\n");
            while(onFloor != gotoFloor) {
                onFloor += add;
                printf("Now on floor %d.\n", onFloor);   
            }
            printf("\nYou have arived at floor %d!\n", onFloor);
        }
    }
    
    return 0;
}