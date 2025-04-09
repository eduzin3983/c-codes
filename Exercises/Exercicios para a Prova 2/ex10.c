/*Faça um programa que leia um vetor de 10 posições usando
uma função. Este programa deverá também criar uma função
que dados dois números inteiros X e Y (entre 0 e 9), a função
retorne a somas dos elementos desse vetor nesse intervalo*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void le_vetor(int vetor[TAM]) {
    printf("Digite um vetor de 10 posicoes: \n");
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

int soma_intervalo(int vetor[TAM], int X, int Y) {
    int soma = 0;

    for (int i = X; i < Y; i++)
    {
        soma += vetor[i];
    }
    
    return soma;
}

int main() {

    int vetor[TAM];
    le_vetor(vetor);
    printf("%d\n", soma_intervalo(vetor, 2, 8));

    return 0;
}