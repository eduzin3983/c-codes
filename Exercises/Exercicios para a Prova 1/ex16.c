/*Ler um vetor A com 10 elementos inteiros correspondentes as
idades de um grupo de pessoas. Escreva um programa que
determine e escreva a idade média dos elementos lidos e
quantos elementos são menores que a média.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int soma = 0;

    int vetorA[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetorA[i]);
        soma += vetorA[i];
    }

    float media = soma / 10.00;

    int contador = 0;
    for (int i = 0; i < 10; i++)
    {
        if (vetorA[i] < media)
        {
            contador++;
        }
    }

    printf("Vetor Lido: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetorA[i]);
    }
    printf("\n");

    printf("Media: %.2f\n", media);

    printf("Menores que a media: %d\n", contador);

    return 0;
}