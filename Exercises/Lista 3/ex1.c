/* Fazer um programa que faz a leitura de dois vetores X e Y, ambos
com N reais (N deve ser lido tb), com tamanho máximo igual a 20.
Efetue a multiplicação dos respectivos pares de elementos de X
por Y, gerando um terceiro vetor Z. Imprima os vetores X, Y e Z. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    // Lendo o tamanho do vetor
    do {
        printf("Digite o tamanho do vetor (máximo 20): ");
        scanf("%d", &N);
    } while (N < 1 || N > 20);

    float X[N], Y[N], Z[N];

    // Lendo os valores do vetor X
    printf("Digite os %d elementos do vetor X:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &X[i]);
    }

    // Lendo os valores do vetor Y
    printf("Digite os %d elementos do vetor Y:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%f", &Y[i]);
    }

    // Calculando o vetor Z
    for (int i = 0; i < N; i++) {
        Z[i] = X[i] * Y[i];
    }

    // Imprimindo os vetores
    printf("Vetor X = { ");
    for (int i = 0; i < N; i++) {
        printf("%.2f", X[i]);
        if (i < N - 1) printf(", ");
    }
    printf(" }\n");

    printf("Vetor Y = { ");
    for (int i = 0; i < N; i++) {
        printf("%.2f", Y[i]);
        if (i < N - 1) printf(", ");
    }
    printf(" }\n");

    printf("Vetor Z = { ");
    for (int i = 0; i < N; i++) {
        printf("%.2f", Z[i]);
        if (i < N - 1) printf(", ");
    }
    printf(" }\n");

    return 0;
}
