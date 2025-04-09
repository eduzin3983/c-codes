/*Soma e Maior Dígito de um Número Inteiro

Elabore um programa que leia um número inteiro e implemente as seguintes funções:

int soma_digitos(int n); – Esta função deve retornar a soma dos dígitos do número inteiro n.​

void maior_digito(int n, int *maior); – Esta função deve determinar o maior dígito do número inteiro n e armazená-lo na variável apontada por maior.​

Os resultados devem ser impressos na função main.
*/

#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n){
    n = abs(n);

    int soma = 0;
    int temp;
    while (n > 0)
    {
        temp = n % 10;
        soma += temp;
        n /= 10;
    }

    return soma;
}

void maior_digito(int n, int *maior) {
    n = abs(n);

    int temp;
    *maior = n % 10;

    while (n > 0)
    {
        temp = n % 10;
        if (*maior < temp)
        {
            *maior = temp;
        }
        n /= 10;
    }
}

int main() {

    printf("%d\n", soma_digitos(2145));
    
    int Maior;
    maior_digito(2945, &Maior);

    printf("%d\n", Maior);

    return 0;
}