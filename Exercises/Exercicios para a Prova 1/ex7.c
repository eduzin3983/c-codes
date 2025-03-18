/*Os números primos possuem várias aplicações dentro da
Computação, por exemplo na Criptografia. Um número
primo é aquele que é divisível apenas por um e por ele
mesmo. Faça um programa que peça um número inteiro e
determine se ele é ou não um número primo.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    bool primo = true;
    int num;
    scanf("%d", &num);

    if (num <= 1) {
        primo = false;
    } else {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                primo = false;
                break;
            }
            
        }
    }

    if (primo) {
        printf("É um numero primo\n");
    } else {
        printf("Não é um numero primo\n");
    }

    return 0;
}