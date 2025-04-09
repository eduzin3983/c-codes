/*Elabore um programa que contenha duas funções:
• Uma função que lê um número real e o retorna.
• E uma função que a partir do número real lido retorna a
parte fracionária do mesmo.*/

#include <stdio.h>
#include <stdlib.h>

float le() {
    float num;
    scanf("%f", &num);

    return num;
}

float fraciona(float num){
    int numInteiro = (int)num;
    float resultado = num - numInteiro;

    return resultado;
}

int main() {
    float num = le();
    float fracao = fraciona(num);

    printf("%.4f\n", num);
    printf("%.4f\n", fracao);

}