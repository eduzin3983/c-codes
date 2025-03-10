/* Fazer um programa que faz a leitura de um vetor X com N inteiros,
com tamanho máximo igual a 20 e N deverá ser lido. Multiplique
cada elemento do vetor por um inteiro K (K também deverá ser
lido). Imprimir o vetor lido, o valor da variável K e o vetor
multiplicado por K. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    // Lendo o tamanho do vetor (entre 1 e 20)
    do {
        printf("Digite o tamanho do vetor (máximo 20): ");
        scanf("%d", &n);
    } while (n < 1 || n > 20);

    // Lendo o valor de K
    printf("Digite o valor de K: ");
    scanf("%d", &k);

    int X[n], Y[n];

    // Lendo os elementos do vetor X
    printf("Digite os %d elementos do vetor X:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i] * k;  // Calculando o vetor multiplicado por K
    }

    // Imprimindo o vetor original X
    printf("Vetor X = { ");
    for (int i = 0; i < n; i++) {
        printf("%d", X[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");

    // Imprimindo o valor de K
    printf("Valor de K = %d\n", k);

    // Imprimindo o vetor resultante Y
    printf("Vetor multiplicado por K = { ");
    for (int i = 0; i < n; i++) {
        printf("%d", Y[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");

    return 0;
}
