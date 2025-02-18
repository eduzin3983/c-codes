/* Suponha que o valor de uma certa variável
inteira A=5 e de uma Variável B=13, como
poderíamos trocar o valor dessas variáveis,
ou seja, A=13 e B=5? */

#include <stdio.h>

int main() {
    
    int A = 5, B = 13, temp;

    temp = A;
    A = B;
    B = temp;

    printf("A = %d\n", A);
    printf("B = %d\n", B);
    
    return 0;
}