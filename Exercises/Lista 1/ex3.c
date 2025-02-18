/* Construir um programa que leia o salário
mensal atual de um funcionário e o percentual
de reajuste. Determine o valor do novo salário
e imprima os valores lidos e o novo salário. */

#include <stdio.h>

int main() {
    
    float salario_mensal, percentual_reajuste, novo_salario;

    printf("Digite o salário mensal atual: ");
    scanf("%f", &salario_mensal);
    printf("Digite o percentual de reajuste: ");
    scanf("%f", &percentual_reajuste);

    novo_salario = salario_mensal + (salario_mensal * (percentual_reajuste / 100));

    printf("Salário mensal atual: R$%.2f\n", salario_mensal);
    printf("Percentual de reajuste: %.2f%%\n", percentual_reajuste);
    printf("Novo salário: R$%.2f\n", novo_salario);
    
    return 0;
}