#include <stdio.h>

void teaser(int n);

int main() {

    teaser(13);

    return 0;
}

void teaser(int n) {
    
    for(int x = 0; x < n; x++) {
        for(int z = 0; z < n; z++) {
            if(x == 0 || x == n-1) {
                printf("* ");
            } else if(z == 0 || z == n-1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

}