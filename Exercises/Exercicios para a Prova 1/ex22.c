/*Faça um programa que lê uma string de 5 caracteres e inverte
esta string. No final o programa deverá imprimir a string
original e a invertida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[6];
    
    printf("Digite uma string de até 5 caracteres: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    int tamanho = strlen(string);

    char stringInvertida[6];

    for (int i = 0; i < tamanho; i++) {
        stringInvertida[i] = string[tamanho - i - 1];
    }

    stringInvertida[tamanho] = '\0';

    printf("String original: %s\n", string);
    printf("String invertida: %s\n", stringInvertida);

    return 0;
}
