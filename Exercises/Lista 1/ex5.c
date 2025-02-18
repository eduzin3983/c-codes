/* Escrever um programa que faz a leitura de um número inteiro
de até 2 dígitos e imprima a soma dos dígitos. Considere que
somente serão digitados números de 1 ou 2 dígitos. */

#include <stdio.h>

int main() {
    
    int num, soma;

    printf("Digite um numeros inteiro de 2 Digitos: ");
    scanf("%d", &num);

    while (num < 10 || num > 99)
    {
        printf("Digite um numeros inteiro de 2 Digitos: ");
        scanf("%d", &num);
    }

    soma = (num / 10) + (num % 10);

    printf("A soma dos digitos de %d é: %d\n\n", num, soma);
    
    return 0;
}