/* Uma empresa paga a seus empregados um salário de R$1.500,00 por mês
mais uma comissão de R$200,00 para cada carro vendido e mais 5% do valor
da venda. Construir um programa para calcular o salário do mês de um
funcionário, de acordo com o descrito acima. Para o cálculo da comissão e
do adicional de 5% do valor da venda, o programa deverá ler o número de
carros vendidos e valor total das vendas, do empregado, no mês e, imprimir
de forma bem explicativa o salário do funcionário: 

// Salário Base: R$ 1500.00
// Número de Carros Vendidos: ....
// Total de Vendas: R$ ....
// Total de Comissão: R$ ...
// Total de Adicional de 5%: R$ ...
// Salario a RECEBER: R$ ....

*/

#include <stdio.h>

int main() {
    
    float salario_base = 1500;
    float comissao;
    float salario_completo;
    float adicional;

    int carros_vendidos;
    float valor_total_vendas;

    printf("Digite o numero de Carros Vendidos: ");
    scanf("%d", &carros_vendidos);

    printf("Digite o valor total de vendas: ");
    scanf("%f", &valor_total_vendas);
    
    comissao = 200 * carros_vendidos;

    adicional = 0.05 * valor_total_vendas;

    salario_completo = salario_base + comissao + adicional;

    printf("\n\nSalário Base: R$ %.2f\n", salario_base);
    printf("Número de Carros Vendidos: %d\n", carros_vendidos);
    printf("Total de Vendas: R$ %.2f\n", valor_total_vendas);
    printf("Total de Comissão: R$ %.2f\n", comissao);
    printf("Total de Adicional de 5%: R$ %.2f\n", adicional);
    printf("Salario a RECEBER: R$ %.2f\n\n", salario_completo);

    return 0;
}