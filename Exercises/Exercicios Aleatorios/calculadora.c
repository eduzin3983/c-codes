#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, escolha;

    printf("Escolha qual operacao deseja fazer: 1 - Soma, 2 - Subtracao, 3 - Multiplicacao, 4 - Divisao \n");
    scanf("%d", &escolha);

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);


    switch (escolha) 
    {
    case 1:
        printf("A soma de %d e %d é %d\n", a, b, a+b);
        break;
    case 2:
        printf("A subtracao de %d e %d é %d\n", a, b, a-b);
        break;
    case 3:
        printf("A multiplicacao de %d e %d é %d\n", a, b, a*b);
        break;
    case 4:
        printf("A divisao de %d e %d é %d\n", a, b, a/b);
        break;
    default:
        printf("Operacao Indisponivel!\n");
        break;
    }
    
    return 0;
}