/*Construir um programa que leia o salário
mensal atual de um funcionário e o percentual
de reajuste. Determine o valor do novo salário
e imprima os valores lidos e o novo salário.
Introdução à Linguagem C */

#include <stdio.h>
#include <stdlib.h>

int main() {

    float salarioMensal, percentualReajuste;

    scanf("%f", &salarioMensal);
    scanf("%f", &percentualReajuste);

    float novoSalario = salarioMensal * ((percentualReajuste / 100) + 1);

    printf("Salario Mensal: %.2f\n",salarioMensal);
    printf("Salario Mensal: %.2f\n",percentualReajuste);
    printf("Salario Mensal: %.2f\n",novoSalario);

    return 0;
}