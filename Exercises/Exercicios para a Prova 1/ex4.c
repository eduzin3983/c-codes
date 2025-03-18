/* A loja “FiqueFeliz” resolveu liquidar todos os seus produtos,
para isso necessita de um programa que ajude calcular os novos
preços desses produtos. Elabore um programa que leia o preço
de um produto, o valor do desconto (em porcentagem) e calcule
o novo preço. Imprimir o valor do produto, o desconto e o novo
valor. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    float preco, desconto;

    scanf("%f", &preco);
    scanf("%f", &desconto);

    float novoPreco = preco - (preco * (desconto / 100));

    printf("Preco Inicial: %.2f\n", preco);
    printf("Desconto: %.f\n", desconto);
    printf("Novo Preco: %.2f\n", novoPreco);

    return 0;
}