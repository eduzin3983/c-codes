/*Elabore um programa que possua uma função que recebe um valor
inteiro e verifica se o valor é par. A função deve retornar um
booleano e o resultado deverá ser impresso no programa principal.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verifica(int num) {
    if (num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int num;
    scanf("%d", &num);

    if (verifica(num))
    {
        printf("É par!\n");
    }
    else
    {
        printf("É impar!\n");
    }
    
    return 0;
}