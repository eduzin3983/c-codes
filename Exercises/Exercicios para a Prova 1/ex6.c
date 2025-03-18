/*Uma empresa paga a seus empregados um salário de R$1.500,00 por mês
mais uma comissão de R$200,00 para cada carro vendido e mais 5% do valor
da venda. Construir um programa para calcular o salário do mês de um
funcionário, de acordo com o descrito acima. Para o cálculo da comissão e
do adicional de 5% do valor da venda, o programa deverá ler o número de
carros vendidos e valor total das vendas, do empregado, no mês e, imprimir
de forma bem explicativa o salário do funcionário:

    Salário Base: R$ 1500.00
    Número de Carros Vendidos: .....
    Total de Vendas: R$ .....
    Total de Comissão: R$ ...
    Total de Adicional de 5%: R$ ....
    Salário a RECEBER: R$ .....

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float salario = 1500;

    int numeroVendidos;
    scanf("%d", &numeroVendidos);

    float valorTotal;
    scanf("%f", &valorTotal);

    float comissao = numeroVendidos * 200.00;
    float adicional = valorTotal * 0.05;
    
    float salarioTotal = salario + comissao + adicional;

    printf("Salário Base: R$ %.2f\n", salario);
    printf("Número de Carros Vendidos: %d\n", numeroVendidos);
    printf("Total de Vendas: R$ %.2f\n", valorTotal);
    printf("Total de Comissão: R$ %.2f\n", comissao);
    printf("Total de Adicional de 5%%: R$ %.2f\n", adicional);
    printf("Salário a RECEBER: %.2f\n", salarioTotal);

    return 0;
}
