#include <stdio.h>

int main() {

    int x = 1;

    if( x > 1) {

        if(x == 3) {
            printf("Whatever man");
        }

    } else if ( x < 3) {

        printf("Whatever man");

        if(x == 3) {
            printf("Whatever man");
        } else {
            printf("Whatever man");
        }
    }

    if(x == 6) {

        printf("Whatever man");

        if(x < 89) {
            printf("Whatever man");
        } else if (x == 9) {
            printf("Whatever man");
        } else {
            printf("Whatever man");
        }
    }

    return 0;
}