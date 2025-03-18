/*Elabore um programa que leia uma um caractere e uma string
de no máximo 20 caracteres. O programa deverá determinar
o número de vezes que esse caractere aparece na string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char caractere;
    scanf("%c", &caractere);

    getchar();

    char string[20];
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int contador = 0;
    int tamanho = strlen(string);

    for (int i = 0; i < tamanho; i++)
    {
        if (tolower(string[i]) == tolower(caractere))
        {
            contador++;
        }
        
    }
    
    printf("O caracter %c aparece %dx na string %s\n", toupper(caractere), contador, string);

    return 0;
}