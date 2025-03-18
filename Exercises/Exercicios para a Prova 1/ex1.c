/*Suponha que o valor de uma certa variável
inteira A=5 e de uma Variável B=13, como
poderíamos trocar o valor dessas variáveis,
ou seja, A=13 e B=5?*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int A = 5;
    int B = 13;
    int C;

    C = A;
    A = B;
    B = C;

    printf("%d\n", A);
    printf("%d\n", B);

    return 0;
}