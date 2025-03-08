#include <stdio.h>
#include <stdlib.h>

int main() {

    float deposito, juros, depositoAtualizado;
    int tempo;

    scanf("%f %f %d", &deposito, &juros, &tempo);

    depositoAtualizado = deposito;

    for (int i = 1; i <= tempo; i++)
    {

        depositoAtualizado *= (1 + (juros / 100));

        printf("O deposito de %.2f com a taxa de juros em %.2f' o ano %d é de: %.2f\n\n", deposito, juros, i, depositoAtualizado);
    }

    printf("O total do rendimento vai ser de: %.2f\n", depositoAtualizado);
    

    return 0;
}