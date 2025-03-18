/*Elabore um programa que leia vários números inteiros até
o usuário digitar um número negativo. Para cada número
lido deverá ser calculado e impresso seu fatorial.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num;
    
    do
    {
        scanf("%d", &num);
        
        if (num < 0)
        {
            break;
        } 
        else
        {
            int fatorial = num;

            printf("o fatorial de %d é: ", num);
            for (int i = num - 1; i > 0; i--)
            {
                fatorial *= i;
            }

            printf("%d\n\n", fatorial);
        }
        
    } while (num > 0);

    return 0;
}