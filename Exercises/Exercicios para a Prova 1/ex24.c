/* Elabore um programa que leia um nome completo de
até 100 caracteres e imprima as iniciais deste nome.
Exemplo: João Carlos Nascimento da Silva, será impresso
JCNDS. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char nome[100];
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int tamanho = strlen(nome);

    for (int i = 0; i < tamanho; i++)
    {
        if (i == 0 || (nome[i - 1] == ' ' && nome[i] != ' '))
        {
            printf("%c", toupper(nome[i]));
        } 
    }
    
    printf("\n");    

    return 0;
}
