/* Fazer um programa que faz a leitura de um vetor X com N reais ,
com tamanho máximo igual a 20 e N deverá ser lido. Calcule o
somatório de todos os elementos do vetor. Imprimir o vetor lido
e o valor do somatório. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    int soma = 0;
    do
    {
        scanf("%d", &N);
    } while (N < 1 || N > 20);
    
    int vetorX[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetorX[i]);
        soma += vetorX[i];
    }

    printf("Vetor Lido: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetorX[i]);
    }
    printf("\n");

    printf("Somatorio: %d\n", soma);

    return 0;
}
