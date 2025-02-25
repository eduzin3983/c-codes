/* Faça um programa que peça um número inteiro e
determine se ele é ou não um número primo. Um número
primo é aquele que é divisível somente por ele mesmo e
por 1. */

#include <stdio.h>

int main() {

    int n;
    int primo = 1;
    
    scanf("%d", &n);

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            primo = 0;
            break;
        }    
    }

    if (primo == 1)
    {
        printf("O número %d é primo\n", n);
    } else
    {
        printf("O número %d não é primo\n", n);
    }
    
    return 0;
}