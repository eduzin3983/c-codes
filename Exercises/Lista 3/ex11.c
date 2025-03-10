/* Ler um vetor A com 10 elementos inteiros correspondentes as
idades de um grupo de pessoas. Escreva um programa que
determine e escreva a idade média dos elementos lidos e
quantos elementos são menores que a média. */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {

    int A[TAM];

    int soma = 0;
    for (int i = 0; i < TAM; i++)
    {
        printf("Insira a idade da pessoa %d: ", i+1);
        scanf("%d", &A[i]);

        soma += A[i];
    }

    float media = (float)soma / TAM;
    
    int contador = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (A[i] < media)
        {
            contador++;
        }
        
    }

    printf("Media: %.2f\n", media);
    printf("Menores que a media: %d\n", contador);
    
    return 0;
}