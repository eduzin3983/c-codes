/* Faça um algoritmo que leia uma matriz de inteiros 5x3 e
construa sua transposta. O programa deverá imprimir as
duas matrizes, a original e a transposta. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int matriz[5][3];
    int transposta[3][5];

    // Lendo os elementos da matriz original
    printf("Digite os elementos da matriz 5x3:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimindo a matriz original
    printf("\nMatriz Original:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Construindo a matriz transposta
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Imprimindo a matriz transposta
    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
