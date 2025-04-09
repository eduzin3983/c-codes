/*Exercício 4 – Conta vogais
int conta_vogais(char str[]);
Implemente uma função que conte quantas vogais existem em uma string (maiusculas e minusculas devem ser consideradas).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int conta_vogais(char str[]) {
    
    int tamanho = strlen(str);
    int vogais = 0;

    for (int i = 0; i < tamanho; i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vogais++;
        }   
    }
    
    return vogais;
}

int main() {
    
    char string[255];
    fgets(string, sizeof(string), stdin);
    
    string[strcspn(string, "\n")] = '\0';

    printf("%d\n", conta_vogais(string));

    return 0;
}