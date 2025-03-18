/*Fazer um programa que faz a leitura de um vetor X, com N
inteiros, com tamanho máximo igual a 20 e N deverá ser lido.
Gere um segundo vetor com os valores do vetor X em ordem
inversa. Imprimir o vetor X e vetor com a ordem inversa.*/

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

    int vetorInverso[N];
    for (int i = 0; i < N; i++)
    {
        vetorInverso[i] = vetorX[N - i -1];
    }
    
    printf("Vetor Lido: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetorX[i]);
    }
    printf("\n");

    printf("Vetor Inverso: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", vetorInverso[i]);
    }
    printf("\n");

    return 0;
}
