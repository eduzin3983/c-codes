/* Elabore um programa que leia uma string de no máximo 10
caracteres. O programa deverá imprimir a string sem suas
vogais */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char string[10];
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int tamanho = strlen(string);

    for (int i = 0; i < tamanho; i++)
    {
        if (tolower(string[i]) != 'a' && tolower(string[i]) != 'e' && tolower(string[i]) != 'i' && tolower(string[i]) != 'o' && tolower(string[i]) != 'u')
        {
            printf("%c", string[i]);
        }
        
    }
    
    printf("\n");

    return 0;
}