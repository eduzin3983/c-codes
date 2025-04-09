/*Elabore um programa que crie uma estrutura com as
seguintes informações de um produto:
• Código do produto – inteiro de 3 dígitos
• Quantidade em estoque - inteiro
• Valor de compra - real
• Valor de Venda - real
O programa deverá ler a informação de 10 produtos e determinar
• O código do produto com maior quantidade de estoque
• O quantidade de estoque do produto que proporciona o maior
lucro*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    int quantidade;
    float valorCompra;
    float valorVenda;
} produto;


int main() {

    int qtdProdutos;
    printf("Digite a quantidade e produtos que quer adicionar: ");
    scanf("%d", &qtdProdutos);

    produto Produto[qtdProdutos];

    for (int i = 0; i < qtdProdutos; i++)
    {
        //Le produto.
        do
        {
            printf("Digite o codigo do produto %d: ", i+1);
            scanf("%d", &Produto[i].codigo);

            if (Produto[i].codigo < 100 || Produto[i].codigo > 999)
            {
                printf("Valor Indisponivel, digite um inteiro de 3 digitos. \n");
            }
            
        } while (Produto[i].codigo < 100 || Produto[i].codigo > 999);
        
        //Le Quantidade em Estoque.
        printf("Digite a quantidade em Estoque do Produto %d: ", i+1);
        scanf("%d", &Produto[i].quantidade);

        //Le Valor de Compra
        printf("Digite o valor de Compra do Produto %d: ", i+1);
        scanf("%f", &Produto[i].valorCompra);

        //Le Valor de Venda
        printf("Digite o valor de Venda do Produto %d: ", i+1);
        scanf("%f", &Produto[i].valorVenda);

        printf("\n");
    }

    int maiorEstoque = Produto[0].quantidade;
    int indiceEstoque = 0;

    float maiorLucro = (Produto[0].valorVenda - Produto[0].valorCompra) * Produto[0].quantidade;
    int indiceLucro = 0;

    for (int i = 0; i < qtdProdutos; i++)
    {
        if (maiorEstoque < Produto[i].quantidade)
        {
            maiorEstoque = Produto[i].quantidade;
            indiceEstoque = i;
        }

        if (maiorLucro < (Produto[i].valorVenda - Produto[i].valorCompra) * Produto[i].quantidade)
        {
            maiorLucro = (Produto[i].valorVenda - Produto[i].valorCompra) * Produto[i].quantidade;
            indiceLucro = i;
        }
    }

    printf("\nO codigo do produto com mais Estoque é %d\n", Produto[indiceEstoque].codigo);
    printf("A quantidade de estoque do produto que proporciona o maior lucro é: %d\n", Produto[indiceLucro].quantidade);

    return 0;
}