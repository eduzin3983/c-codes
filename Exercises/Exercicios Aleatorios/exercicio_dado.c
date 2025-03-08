#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srandom(time(NULL));

    int dado1 = (random() % 6) + 1;
    int dado2 = (random() % 6) + 1;
    int dado3 = (random() % 6) + 1;

    printf("%d", dado1 + dado2 + dado3);

    return 0;
}