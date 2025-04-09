/*Elabore um programa que leia um número inteiro
e construa os seguintes procedimentos
• int soma_digit(int a) – este procedimento irá somar os dígitos
desse número inteiro
• void Maior_Digit(int N, int *M) – este procedimento irá
determinar o maior dígito desse número inteiro
• Os resultados deverão ser impressos no programa principal*/

#include <stdio.h>
#include <stdlib.h>

int soma_digit(int a) {
    int soma = 0;
    a = abs(a);
    while (a > 0) {
        soma += a % 10;
        a /= 10;
    }
    return soma;
}

void Maior_Digit(int N, int *M) {
    int digito;
    *M = 0;
    N = abs(N);

    while (N > 0) {
        digito = N % 10;
        if (digito > *M) {
            *M = digito;
        }
        N /= 10;
    }
}


int main() {

    int numero, soma, maior;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    soma = soma_digit(numero);
    Maior_Digit(numero, &maior);

    printf("Soma dos dígitos: %d\n", soma);
    printf("Maior dígito: %d\n", maior);

    return 0;
}