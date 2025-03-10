/* Construir um programa que faz a leitura de uma matriz
quadrada de reais de tamanho N por N (máximo 20 x 20).
Somar todos os elementos da diagonal principal.
Imprimir a matriz lida e o valor da soma obtido. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    int soma = 0;

    printf("Digite o Tamanho da Matriz: ");
    do
    {
        scanf("%d", &N);
    } while (N < 1 || N > 20);
    
    int matriz[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Digite o valor da Linha %d e Coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);

            soma += matriz[i][j];
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
        
    }
    
    printf("\nSoma: %d\n", soma);

    return 0;
}
