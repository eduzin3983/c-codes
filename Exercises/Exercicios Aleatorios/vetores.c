#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main(){

    int vetor[TAM];
    int soma = 0;

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < TAM; i++)
    {
        soma += vetor[i];
    }
    
    float media = (float)soma / TAM;

    for (int i = 0; i < TAM; i++)
    {
        printf("O vetor digitado é vetor[%d] = %d\n",i+1, vetor[i]);
    }
    
    printf("A media desse vetor é: %.2f\n", media);
    
    return 0;
}