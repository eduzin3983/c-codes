/*Verifica Palíndromo
int eh_palindromo(char str[]);
Implemente uma função que receba uma string e retorne 1 se ela for um palíndromo (ex: "ana", "arara"), ou 0 caso contrário.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_palindromo(char str[]) {
    int tamanho = strlen(str);

    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
        tamanho--;
    }

    for (int i = 0; i < tamanho / 2; i++) {
        if (str[i] != str[tamanho - 1 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[255];
    fgets(str, sizeof(str), stdin);

    int resultado = eh_palindromo(str);
    printf("%d\n", resultado);

    return 0;
}
