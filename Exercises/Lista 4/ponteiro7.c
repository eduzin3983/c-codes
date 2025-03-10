/*Faça um programa que leia 2 valores inteiros e chame uma função que receba 
estas 2 variáveis e troque o seu conteúdo, ou seja, esta função é chamada 
passando duas variáveis A e B por exemplo e, após a execução da função,
A conterá o valor de B e B conterá o valor de A.*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *num1, int *num2) {
    int c;

    c = *num1;
    *num1 = *num2;
    *num2 = c;
}

int main() {

    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    troca(ptr1, ptr2);

    printf("%d\n", num1);
    printf("%d\n", num2);
    
    return 0 ;
}
