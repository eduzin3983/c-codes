/*Faça um algoritmo que leia uma matriz M 5x5 de númeors
reias. O programa deve determinar o maior número da
matriz e a sua posição (linha, coluna).*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    float matriz[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Digite o valor da linha %d e coluna %d: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }

    float maior = matriz[0][0];
    int posicaoLinha = 0;
    int posicaoColuna = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                posicaoLinha = i;
                posicaoColuna = j;
            }
            
        }
        
    }
    
    printf("Maior Numero da matriz: %.2f\n", maior);
    printf("Posicao do maior numero, Linha: %d, Coluna: %d\n", posicaoLinha, posicaoColuna);

    return 0;
}