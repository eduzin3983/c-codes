/*Escreva uma função em C que resulte a soma dos elementos de
um vetor de números inteiros dado (a quantidade de
elementos do vetor também será fornecida).*/

#include <stdio.h>
#include <stdlib.h>

int soma(int vetor[], int qtd) {
    int soma = 0;
    for (int i = 0; i < qtd; i++)
    {
        soma += vetor[i];
    }

    return soma;
}

int main() {

    int vetor[] = {1, 4, 3, 2, 7, 8, 4};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("%d\n", soma(vetor, tamanho));

    return 0;
}