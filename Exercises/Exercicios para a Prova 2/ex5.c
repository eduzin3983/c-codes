/*Faça um programa que lê um número não determinado de valores
inteiros e positivos, e para cada valor lido:

a) calcula e escreve o seu fatorial;
b) calcula e escreve os seus divisores;
c) Você deverá construir o programa, elaborando as seguintes funções:
    - Ler_num(int &x) – função que lê um valor inteiro
    - int Fatorial(int N) – função que retorna o fatorial de um número inteiro N
    - void divisores(int valor) – função que imprime os divisores deum número
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Ler_num(int *x) {
    printf("Digite um número inteiro positivo (ou negativo para sair): ");
    scanf("%d", x);
}

int fatorial(int N) {
    int resultado = 1;
    for (int i = 1; i <= N; i++)
    {
        resultado *= i;
    }

    return resultado;    
}

void divisores(int valor) {
    printf("Divisores de %d: ", valor);
    for (int i = 1; i <= valor; i++) {
        if (valor % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;

    while (true) {
        Ler_num(&num);

        if (num < 0) {
            printf("Programa encerrado.\n");
            break;
        } else {
            int fat = fatorial(num);
            printf("O fatorial de %d é %d.\n", num, fat);
            divisores(num);
            printf("\n");
        }
    }

    return 0;
}
