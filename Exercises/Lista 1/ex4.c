/* A loja “FiqueFeliz” resolveu liquidar todos os seus produtos,
para isso necessita de um programa que ajude calcular os novos
preços desses produtos. Elabore um programa que leia o preço
de um produto, o valor do desconto (em porcentagem) e calcule
o novo preço. Imprimir o valor do produto, o desconto e o novo
valor. */

#include <stdio.h>

int main() {
    
    float preco_produto, desconto, novo_preco;

    printf("Digite o preço do produto: R$");
    scanf("%f", &preco_produto);
    printf("Digite o valor do desconto (em porcentagem): ");
    scanf("%f", &desconto);

    novo_preco = preco_produto - (preco_produto * (desconto / 100));

    printf("Valor Original do Produto: %.2f\n", preco_produto);
    printf("Valor do Desconto: %.2f\n", desconto);
    printf("Novo Valor do Produto: %.2f", novo_preco);
    
    return 0;
}