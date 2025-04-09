/*Soma de dois vetores
void soma_vetores(int v1[], int v2[], int resultado[], int tamanho);
A função deve somar dois vetores inteiros v1 e v2 e armazenar o resultado em um terceiro vetor.*/

#include <stdio.h>
#include <stdlib.h>

void soma_vetores(int v1[], int v2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
    {
        resultado[i] = v1[i] + v2[i];
    }
}

int main() {

    int v1[] = {3, 5, 7, 2, 4};
    int v2[] = {14, 2, 6, 6, 8};
    int tamanho = sizeof(v1) / sizeof(v1[0]);

    int resultado[tamanho];

    soma_vetores(v1, v2, resultado, tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", resultado[i]);
    }
    
    printf("\n");

    return 0;
}