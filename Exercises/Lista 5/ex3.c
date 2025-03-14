/*Faça um programa que lê uma string de 5 caracteres e inverte
esta string. No final o programa deverá imprimir a string
original e a invertida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[6];
    char stringInvertida[6];

    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';

    int tamanho = strlen(string);

    for (int i = 0; i < tamanho; i++)
    {
        stringInvertida[i] = string[tamanho - i - 1];
    }
    stringInvertida[tamanho] = '\0';

    printf("%s\n", string);
    printf("%s\n", stringInvertida);

    return 0;
}