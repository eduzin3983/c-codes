/*Elabore um programa que leia uma matriz de reais 10x10 e
determine:
• A soma da linha 4.
• O menor elemento da coluna 5.
• O maior elemento da diagonal principal.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float matriz[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("Digite o valor da linha %d e coluna %d: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    float soma = 0;
    for (int j = 0; j < 10; j++)
    {
        soma += matriz[4][j];
    }
    
    float menor = matriz[0][5];
    for (int i = 0; i < 10; i++)
    {
        if (matriz[i][5] < menor)
        {
            menor = matriz[i][5];
        }
        
    }

    float maior = matriz[0][0];
    for (int i = 0; i < 10; i++)
    {
        if (matriz[i][i] > maior)
        {
            maior = matriz[i][i];
        }
        
    } 
    
    printf("Soma: %.2f\n", soma);
    printf("Menor: %.2f\n", menor);
    printf("Maior: %.2f\n", maior);

    return 0;
}