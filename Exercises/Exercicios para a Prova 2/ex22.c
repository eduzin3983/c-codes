/*Transposição de matriz quadrada
void transpor_matriz(int matriz[3][3], int transposta[3][3]);
A função deve calcular a transposta de uma matriz quadrada 3x3 e armazenar o resultado na matriz transposta.*/

#include <stdio.h>
#include <stdlib.h>

void transpor_matriz(int matriz[3][3], int transposta[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
}


int main() {

    int matriz[3][3] = {{1, 2, 3}, 
                        {4, 5, 6},
                        {7, 8, 9}};

    int transposta[3][3];
    
    transpor_matriz(matriz, transposta);

    printf("Matriz transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}