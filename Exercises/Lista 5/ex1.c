/* Elabore um programa que leia uma um caractere e uma string
de no máximo 20 caracteres. O programa deverá determinar
o número de vezes que esse caractere aparece na string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char character;
    char string[20];

    printf("Digite uma string: ");
    fgets(string, 20, stdin);

    string[strcspn(string, "\n")] = '\0';

    printf("Digite um character: ");
    scanf(" %c", &character);

    int contador = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == character)
        {
            contador++;
        }
        
    }
    
    printf("O caracter %c aparece na string %s, %d vezes\n", character, string, contador);

    return 0;
}