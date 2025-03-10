#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", vetor[i]);
    }
    
}

int main() {

    int vetor[5] = {1, 2, 3, 4, 5};

    imprimeVetor(vetor, 5);

}