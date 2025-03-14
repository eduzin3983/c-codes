/* Faça um programa em C que lê uma string de no máximo 10
caracteres e no final imprime quantas letras ‘a’ tem essa string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char string[10];
    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';

    int tamanho = strlen(string);
    int contador = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (toupper(string[i]) == 'A')
        {
            contador++;
        }
        
    }
    
    printf("Na string %s tem %d letras a\n", string, contador);

    return 0;
}