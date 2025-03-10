/*Fazer um programa que faz a leitura de um vetor X com N reais ,
com tamanho máximo igual a 20 e N deverá ser lido. Calcule o
somatório de todos os elementos do vetor. Imprimir o vetor lido
e o valor do somatório.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;

    do
    {
        scanf("%d", &N);
    } while (N < 1 || N > 20);

    int vetor[N];
    int soma = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("Vetor = { ");
    for (int i = 0; i < N; i++)
    {
        printf("%d", vetor[i]);
        if(i < N - 1) printf(", ");
    }
    printf(" }\n");

    printf("Somatorio = %d\n", soma);

    return 0;
}