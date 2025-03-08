#include <stdio.h>
#include <stdlib.h>

int main() {

    float salario, percentual;

    scanf("%f", &salario);
    scanf("%f", &percentual);

    float aumento = salario * (1 + (percentual / 100));

    printf("O aumento foi de: %.2f\n", aumento);

    return 0;
}