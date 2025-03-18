/*Faça um algoritmo que leia uma matriz de inteiros 5x3 e
construa sua transposta. O programa deverá imprimir as
duas matrizes, a original e a transposta.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int matriz[5][3];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor da linha %d e coluna %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int matrizTransposta[3][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrizTransposta[j][i] = matriz[i][j];
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
        
    }

    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matrizTransposta[i][j]);
        }

        printf("\n");
        
    }
    

    return 0;
}