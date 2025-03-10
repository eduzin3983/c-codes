/* Fazer um programa que faz a leitura de um vetor X, com N
inteiros, com tamanho máximo igual a 20 e N deverá ser lido.
Gere um segundo vetor com os valores do vetor X em ordem
inversa. Imprimir o vetor X e vetor com a ordem inversa. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    do
    {
        scanf("%d", &N);
    } while (N < 1 || N > 20);

    int vetor[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int vetorInvertido[N];
    for (int i = 0; i < N; i++)
    {
        vetorInvertido[i] = vetor[N - 1 - i];
    }
    
    printf("Vetor Original = { ");
    for (int i = 0; i < N; i++)
    {
        printf("%d", vetor[i]);
        if(i < N - 1) printf(", ");
    }
    printf(" }\n");

    printf("Vetor Invertido = { ");
    for (int i = 0; i < N; i++)
    {
        printf("%d", vetorInvertido[i]);
        if(i < N - 1) printf(", ");
    }
    printf(" }\n");

    return 0;
}