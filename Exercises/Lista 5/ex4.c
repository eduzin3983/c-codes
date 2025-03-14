/* Faça um programa que leia o nome e sobrenome de uma
pessoa. O programa deve escrever o nome e o sobrenome numa
única string. Deverá ser impresso, a nova string, o tamanho dela
a primeira e a última letra da string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char nome[100], sobrenome[100], nomeCompleto[255];

    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    strcpy(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenome);

    printf("Nome e Sobrenome: %s\n", nomeCompleto);

    int tamanho = strlen(nomeCompleto);
    printf("Tamanho: %d\n", tamanho);
    printf("Primeira letra: %c\n", nomeCompleto[0]);
    printf("Ultima letra: %c\n", nomeCompleto[tamanho-1]);

    return 0;
}