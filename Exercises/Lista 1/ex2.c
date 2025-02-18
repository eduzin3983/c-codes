/* Faça um programa para receber um número
inteiro representando segundos e imprimir a
quantidade correspondente em horas,
minutos e segundos. */

#include <stdio.h>

int main() {
    
    int i, horas, minutos, segundos;

    printf("Digite um número inteiro: ");
    scanf("%d", &i);
    
    horas = i / 3600;
    minutos = (i % 3600) / 60;
    segundos = (i % 3600) % 60;

    printf("%d segundos correspondem a %d horas, %d minutos e %d segundos.\n", i, horas, minutos, segundos);
    
    return 0;
}