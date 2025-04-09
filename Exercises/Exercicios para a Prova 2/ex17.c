/*Cálculo da Média e Desvio Padrão de um Vetor

Escreva uma função que calcule a média e o desvio padrão dos elementos de um vetor de números reais. 
A função deve ter o seguinte protótipo:

void calcula_media_desvio(float vetor[], int tamanho, float *media, float *desvio);

Onde vetor é o array de números reais, tamanho é o número de elementos no vetor, 
media é um ponteiro para armazenar a média calculada e desvio é um ponteiro para armazenar o desvio padrão calculado.
*/

#include <stdio.h>
#include <stdlib.h>

void calcula_media_desvio(float vetor[], int tamanho, float *media, float *desvio) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    *media = soma / tamanho;

    float soma_quadrados = 0;
    for (int i = 0; i < tamanho; i++) {
        float diferenca = vetor[i] - *media;
        soma_quadrados += diferenca * diferenca;
    }

    float variancia = soma_quadrados / tamanho;

    float raiz = variancia / 2.0;
    for (int i = 0; i < 10; i++) {
        raiz = (raiz + variancia / raiz) / 2.0;
    }

    *desvio = raiz;
}

int main() {

    float vetor[] = {4.3, 2.1, 6, 7.8, 4, 6.8 ,3.2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    float media;
    float desvio;

    calcula_media_desvio(vetor, tamanho, &media, &desvio);

    printf("Media: %f, Desvio: %f\n", media, desvio);
    
    return 0;
}