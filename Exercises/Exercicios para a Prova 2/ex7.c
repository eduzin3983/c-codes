/*Construa um programa que seja constituído das seguintes
funções
- Ler um vetor de inteiros de 20 posíções
- Função que retorna a quantidade de números pares e a
quantidade de múltiplos de 5
- Função que retorna a média do vetor e quantos valores são
maiores que essa média*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void le_vetor(int vetor[TAM]) {

    printf("Digite um Vetor de %d posicoes.\n", TAM);

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }

}

void quantidade_pares_multiplos(int vetor[TAM]){

    int qtd_pares = 0;
    int qtd_multiplos = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            qtd_pares++;
        }
        
        if (vetor[i] % 5 == 0)
        {
            qtd_multiplos++;
        }
    }

    printf("A quantidade de numeros pares presente no vetor é %d\n", qtd_pares);
    printf("A quantidade de multiplos de 5 no vetor é %d\n", qtd_multiplos);

}

void mediaVetor(int vetor[TAM]) {

    int soma = 0;
    for (int i = 0; i < TAM; i++)
    {
        soma += vetor[i];
    }

    float media = (float)soma / TAM;

    int maior = 0;
    for (int i = 0; i < TAM; i++)
    {
        if ((float)vetor[i] > media)
        {
            maior++;
        }
        
    }

    printf("A media do vetor é %d\n", media);
    printf("A quantidade de numeros acima da media no vetor é %d\n", maior);

}

int main() {

    int vetor[TAM];

    le_vetor(vetor);
    quantidade_pares_multiplos(vetor);
    mediaVetor(vetor);

    return 0;
}