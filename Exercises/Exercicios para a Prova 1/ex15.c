/*Fazer um programa em C para ler um vetor de inteiros positivos
de 15 posições. Imprimir a quantidade de números pares e a
quantidade de múltiplos de 5*/

#include <stdio.h>
#include <stdio.h>

int main() {

    int vetor[15];
    for (int i = 0; i < 15; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int pares = 0;
    int multiplos5 = 0;

    for (int i = 0; i < 15; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            pares++;
        }
        
        if (vetor[i] % 5 == 0)
        {
            multiplos5++;
        }
    }
    
    printf("Pares = %d\n", pares);
    printf("Multiplos de 5 = %d\n", multiplos5);

    return 0;
}