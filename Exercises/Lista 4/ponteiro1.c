#include <stdio.h>
#include <stdlib.h>

int main() {

    int num = 10;

    int *ptr = &num;

    printf("Valor de num: %d\n", num);
    printf("Valor de num via ponteiro: %d\n", *ptr);
    printf("Endereço de num: %p\n", &num);
    printf("Endereço armazenado em ptr: %p\n", ptr);

    return 0;
}