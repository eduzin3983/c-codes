/*Construa um programa em C que leia um número inteiro não
negativo e determine a soma dos seus divisores. A soma dever ser
efetuada através de uma função somadiv e o resultado
impresso no programa principal. O protótipo da função é:
void somadiv(int x, int*y);*/

#include <stdio.h>
#include <stdlib.h>

void somadiv(int x, int *y) {
    *y = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            *y += i;
        }
        
    }
    
}

int main() {

    int num, soma;
    do
    {
        scanf("%d", &num);
    } while (num < 0);
        
    somadiv(num, &soma);
    printf("A soma dos divisores de %d é: %d\n", num, soma);

    return 0;
}
