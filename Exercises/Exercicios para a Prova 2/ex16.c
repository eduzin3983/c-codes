/*Ordenação de Três Números em Ordem Crescente

Implemente uma função que receba três números inteiros por referência e os ordene em ordem crescente. O protótipo da função deve ser:

void ordena_tres(int *a, int *b, int *c);
Após a chamada da função, os valores apontados por a, b e c devem estar em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>

void ordena_tres(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a; *a = *b; *b = temp;
    }
    if (*a > *c) {
        temp = *a; *a = *c; *c = temp;
    }
    if (*b > *c) {
        temp = *b; *b = *c; *c = temp;
    }
}
int main() {

    int a = 4;
    int b = 8;
    int c = 1;

    ordena_tres(&a, &b, &c);

    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}