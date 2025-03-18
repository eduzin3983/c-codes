/*Ler um vetor de inteiros 10 posições. Escreva a seguir o valor e a
posição do maior e menor elementos lidos.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int maior, menor, posicaoMaior, posicaoMenor;

    int vetor[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    posicaoMaior = 0;

    menor = vetor[0];
    posicaoMenor = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            posicaoMaior = i + 1;
        }
        else if (vetor[i] < menor)
        {
            menor = vetor[i];
            posicaoMenor = i + 1;
        }
    }

    printf("Vetor Lido: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Maior Numero: %d, posicao %d\n", maior, posicaoMaior);
    printf("Menor Numero: %d, posicao %d\n", menor, posicaoMenor);

    return 0;
}