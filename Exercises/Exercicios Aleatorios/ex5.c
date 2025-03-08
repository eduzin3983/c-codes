#include <stdio.h>
#include <stdlib.h>

#define GATO 2

int main() {
    float pesoKilos, quantidade;

    scanf("%f %f", &pesoKilos, &quantidade);

    int pesoGramas = pesoKilos * 1000;
    int quantidadeRestante = pesoGramas;

    for (int i = 0; i < 5; i++)
    {
        quantidadeRestante -= quantidade * GATO;
    }

    pesoKilos = quantidadeRestante / 1000;
    
    printf("Restaram %.1f KILOS", pesoKilos);

    return 0;
}
