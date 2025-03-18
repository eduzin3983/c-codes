/*Escrever um programa que faz a leitura de um número inteiro
de até 2 dígitos e imprima a soma dos dígitos. Considere que
somente serão digitados números de 1 ou 2 dígitos. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;
    scanf("%d", &num);

    int resultado = (num / 10) + (num % 10);

    printf("Numero Digitado: %d\n", num);
    printf("Resultado: %d\n", resultado);

    return 0;
}