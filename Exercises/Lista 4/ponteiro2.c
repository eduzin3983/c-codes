#include <stdio.h>
#include <stdlib.h>

int main() {

    int x = 10;
    int *p = &x;

    printf("Valor original de x: %d\n", x);

    *p = 20;

    printf("Valor de x após modificação via ponteiro: %d\n", x);

    return 0;
}