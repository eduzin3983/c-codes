#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Biblioteca para sqrt() e cbrt()

int main() {
    double numero, quadrado, cubo, raizQuadrada, raizCubica;

    // Solicita ao usuário um número positivo maior que zero
    do {
        printf("Digite um número positivo maior que zero: ");
        scanf("%lf", &numero);

        if (numero <= 0) {
            printf("Erro! O número deve ser maior que zero.\n");
        }

    } while (numero <= 0);

    // Cálculo dos valores solicitados
    quadrado = pow(numero, 2);      // Número ao quadrado
    cubo = pow(numero, 3);          // Número ao cubo
    raizQuadrada = sqrt(numero);    // Raiz quadrada
    raizCubica = cbrt(numero);      // Raiz cúbica

    // Exibe os resultados
    printf("\nResultados:\n");
    printf("a. O número ao quadrado: %.2lf\n", quadrado);
    printf("b. O número ao cubo: %.2lf\n", cubo);
    printf("c. A raiz quadrada: %.2lf\n", raizQuadrada);
    printf("d. A raiz cúbica: %.2lf\n", raizCubica);

    return 0;
}
