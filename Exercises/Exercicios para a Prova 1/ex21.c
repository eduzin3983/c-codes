/*Faça um programa em C que lê uma string de no máximo 10
caracteres e no final imprime quantas letras ‘a’ tem essa string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char string[10];
    fgets(string, sizeof(string), stdin);
    string[strcmp(string, "\n")] = '\0';

    int tamanho = strlen(string);

    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (tolower(string[i]) == 'a')
        {
            contador++;
        }
        
    }

    printf("A letra A aparece %dx na string %s\n", contador, string);
    
    return 0;
}