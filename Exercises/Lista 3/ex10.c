/*Ler um vetor de inteiros 10 posições. Escreva a seguir o valor e a
posição do maior e menor elementos lidos.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int vetor[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    int maior = vetor[0];
    int posicaoMaior = 0;

    int menor = vetor[0];
    int posicaoMenor = 0;

    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            posicaoMaior = i;
        }

        if (vetor[i] < menor)
        {
            menor = vetor[i];
            posicaoMenor = i;
        }
    }

    printf("Vetor Original = { ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", vetor[i]);
        if(i < 10 - 1) printf(", ");
    }
    printf(" }\n");

    printf("O maior valor é %d e esta na posicao %d\n", maior, posicaoMaior);
    printf("O menor valor é %d e esta na posicao %d\n", menor, posicaoMenor);

    return 0;
}