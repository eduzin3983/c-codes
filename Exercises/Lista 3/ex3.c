/* Fazer um programa em C para ler um vetor de inteiros positivos
de 15 posições. Imprimir a quantidade de números pares e a
quantidade de múltiplos de 5 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int vetor[15];
    int pares = 0;
    int multiplos = 0;
    
    for (int i = 0; i < 15; i++)
    {
        do
        {
            scanf("%d", &vetor[i]);
        } while (vetor[i] < 0);
        
    }
    
    for (int i = 0; i < 15; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            pares++;
        }

        if (vetor[i] % 5 == 0)
        {
            multiplos++;
        }
        
    }
    
    printf("Pares: %d\n", pares);
    printf("Multiplos de 5: %d\n", multiplos);

    return 0;
}
