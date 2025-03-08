#include <stdio.h>

int main() {
    int num, dias, horas, minutos, segundos;

    // Entrada do usuário
    printf("Digite a quantidade de segundos: ");
    scanf("%d", &num);

    // Cálculo dos dias
    dias = num / 86400; // 1 dia = 86400 segundos
    num %= 86400;       // Resto dos segundos após calcular os dias

    // Cálculo das horas
    horas = num / 3600; // 1 hora = 3600 segundos
    num %= 3600;        // Resto dos segundos após calcular as horas

    // Cálculo dos minutos
    minutos = num / 60; // 1 minuto = 60 segundos
    segundos = num % 60; // O restante são os segundos

    // Exibição do resultado
    printf("Dias: %d, Horas: %d, Minutos: %d, Segundos: %d\n", dias, horas, minutos, segundos);

    return 0;
}
