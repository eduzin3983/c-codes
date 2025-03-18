/*Fazer um programa que faz a leitura de dois vetores X e Y, ambos
com N reais (N deve ser lido tb), com tamanho máximo igual a 20.
Efetue a multiplicação dos respectivos pares de elementos de X
por Y, gerando um terceiro vetor Z. Imprima os vetores X, Y e Z.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    do
    {
        scanf("%d", &N);
    } while (N > 20 || N < 1);

    float vetorX[N];
    float vetorY[N];
    float vetorZ[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &vetorX[i]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &vetorY[i]);
    }
    
    for (int i = 0; i < N; i++)
    {
        vetorZ[i] = vetorX[i] * vetorY[i];
    }
    
    printf("Vetor X: ");
    for (int i = 0; i < N; i++)
    {
        printf("%.2f ", vetorX[i]);
    }

    printf("\n");
    
    printf("Vetor Y: ");
    for (int i = 0; i < N; i++)
    {
        printf("%.2f ", vetorY[i]);
    }

    printf("\n");

    printf("Vetor Z: ");
    for (int i = 0; i < N; i++)
    {
        printf("%.2f ", vetorZ[i]);
    }

    printf("\n");    

    return 0;
}