#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<10;i++){
        printf("%d\n", rand()%6);
    }
    return 0;
}