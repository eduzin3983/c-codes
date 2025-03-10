/* Elabore um programa que leia uma matriz de reais 10x10 e
determine:
• A soma da linha 4.
• O menor elemento da coluna 5.
• O maior elemento da diagonal principal. */

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {

    float matriz[TAM][TAM];
    float soma = 0;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        soma += matriz[4][i];
    }

    float menor = matriz[0][5];

    for (int i = 0; i < TAM; i++)
    {
        if (matriz[i][5] < menor)
        {
            menor = matriz[i][5];
        }

    }
    
    float maior = matriz[0][0];
    for (int i = 1; i < TAM; i++) 
    {
        if (matriz[i][i] > maior) 
        {
            maior = matriz[i][i];
        }
    }
    
    printf("Soma da linha 4: %.2f\n", soma);
    printf("O menor elemento da coluna 5: %.2f\n", menor);
    printf("O maior elemento da diagonal principal: %.2f\n", maior);

    return 0;
}