/*Fazer um programa que faz a leitura de um vetor X com N inteiros,
com tamanho máximo igual a 20 e N deverá ser lido. Multiplique
cada elemento do vetor por um inteiro K (K também deverá ser
lido). Imprimir o vetor lido, o valor da variável K e o vetor
multiplicado por K.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    do
    {
        scanf("%d", &N);
    } while (N < 1 || N > 20);
    
    int vetorX[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetorX[i]);
    }

    int K;
    scanf("%d", &K);

    printf("Vetor Lido: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetorX[i]);
    }
    printf("\n");

    printf("Valor de K: %d\n", K);

    printf("Vetor Multiplicado por K: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetorX[i] * K);
    }
    printf("\n");

    return 0;
}