/*EX 3)Elabore um programa que contenha uma função que dado um numero
inteiro natural ela retorne o seu fatorial.*/

/* EX4) Faça uma função no programa anterior que imprime os divisores do
numero inteiro natural lido*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

// Função que imprime os divisores de um número inteiro natural
void imprimeDivisores(int num) {
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int num = 5;
    int resultado = fatorial(num);

    printf("Fatorial de %d é %d\n", num, resultado);
    printf("Divisores de %d:\n", resultado);
    imprimeDivisores(resultado);

    return 0;
}
