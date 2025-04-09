/* Troca de dois valores com ponteiros
void troca(int *a, int *b);
Implemente uma função que receba dois inteiros e troque seus valores usando ponteiros.*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
}

int main() {

    int a = 3;
    int b = 5;

    troca(&a, &b);

    printf("a: %d, b: %d\n", a, b);

    return 0;
}