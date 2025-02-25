/* Faça um programa que peça um número inteiro positivo e em
seguida mostre este número invertido.
Exemplo: 2349 -> Número Invertido 9432 */

#include <stdio.h>

int main(){

    int num, invertido = 0, resto;

    printf("Digite um Numero Inteiro Positivo: ");
    scanf("%d", &num);

    while (num < 0)
    {
        printf("Digite um Numero Inteiro Positivo: ");
        scanf("%d", &num);
    }

    while (num > 0)
    {
        resto = num % 10;
        invertido = invertido * 10 + resto;
        num /= 10;
    }

    printf("O numero invertido é: %d\n\n", invertido);

    return 0;
}