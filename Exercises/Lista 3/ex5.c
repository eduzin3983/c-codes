/* Faça um algoritmo que leia uma matriz M 5x5 de númeors
reias. O programa deve determinar o maior número da
matriz e a sua posição (linha, coluna). */

#include <stdio.h>
#include <stdlib.h>

int main() {

    float matriz[5][5];
    float maior = 0;
    int linha, coluna;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%f", &matriz[i][j]);

            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                linha = i+1;
                coluna = j+1;
            }
            
        }
        
    }
    
    printf("Maior numero: %.2f\n", maior);
    printf("Linha: %d\n", linha);
    printf("Coluna: %d\n", coluna);

    return 0;
}
