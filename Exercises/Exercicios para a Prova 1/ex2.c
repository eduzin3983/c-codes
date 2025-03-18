/*Faça um programa para receber um número
inteiro representando segundos e imprimir a
quantidade correspondente em horas,
minutos e segundos.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int segundos, horas, minutos, resto;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &segundos);

    horas = segundos / 3600;  // 1 hora tem 3600 segundos
    resto = segundos % 3600;  // Resto após extrair as horas
    minutos = resto / 60;     // 1 minuto tem 60 segundos
    segundos = resto % 60;    // O que sobra são os segundos

    printf("O tempo correspondente é: %02d:%02d:%02d\n", horas, minutos, segundos);

    return 0;
}
