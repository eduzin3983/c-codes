/*Contagem de Ocorrências de um Número em um Vetor

Escreva uma função em C que determine quantas vezes um dado número inteiro ocorre em um vetor de 
números inteiros fornecido. A função deve ter o seguinte protótipo:

int conta_ocorrencias(int vetor[], int tamanho, int numero);

Onde vetor é o array de inteiros, tamanho é o número de elementos no vetor e numero é o valor cuja frequência deve ser contada.*/

#include <stdio.h>
#include <stdlib.h>

int conta_ocorrencias(int vetor[], int tamanho, int numero){
    
    int ocorrencias = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == numero)
        {
            ocorrencias++;
        }
        
    }

    return ocorrencias;
    
}


int main() {

    int vetor[] = {1, 4, 7, 3, 19, 43, 13, 7, 8, 3, 3, 5, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("%d\n", conta_ocorrencias(vetor, tamanho, 3));

    return 0;
}