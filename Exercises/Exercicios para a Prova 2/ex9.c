/*Escreva uma função em C que resulte quantas vezes um dado
número inteiro ocorre em um vetor de números inteiros
fornecido (a quantidade de elementos do vetor também será
fornecida).*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 6

int qtdNumero(int vetor[TAM], int num) {
    int count = 0;
    
    for (int i = 0; i < TAM; i++)
    {
        if (vetor[i] == num)
        {
            count++;
        }
        
    }

    return count;
}

int main() {
    int vetor[TAM] = {3, 6, 5, 6, 8, 10};

    printf("%d\n", qtdNumero(vetor, 6));

    return 0;
}