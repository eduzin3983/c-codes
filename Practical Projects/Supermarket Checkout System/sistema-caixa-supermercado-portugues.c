// Este código não está 100% finalizado, possui alguns bugs, mas dá uma boa ideia da funcionalidade do sistema.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include<windows.h> For Windows
#include<unistd.h> //For Linux
#include <time.h>

// Função para definir a quantidade de cédulas
void calculoQuantidadeNotas(float _troco, int *notas200, int *notas100, int *notas50, int *notas10, int *notas5, int *moedas1, int *moedas05) {
    int valoresCedulas[] = {200, 100, 50, 10, 5};
    int quantidadeCedulas[] = {0, 0, 0, 0, 0};
    float valoresMoedas[] = {1.0, 0.5};
    int quantidadeMoedas[] = {0, 0};

    for (int i = 0; i < 5; i++) {
        while ((*notas200 > 0 || *notas100 > 0 || *notas50 > 0 || *notas10 > 0 || *notas5 > 0) && (_troco >= valoresCedulas[i])) {
            _troco -= valoresCedulas[i];
            switch (i) {
                case 0:
                    (*notas200)--;
                    quantidadeCedulas[0]++;
                    break;
                case 1:
                    (*notas100)--;
                    quantidadeCedulas[1]++;
                    break;
                case 2:
                    (*notas50)--;
                    quantidadeCedulas[2]++;
                    break;
                case 3:
                    (*notas10)--;
                    quantidadeCedulas[3]++;
                    break;
                case 4:
                    (*notas5)--;
                    quantidadeCedulas[4]++;
                    break;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        while ((*moedas1 > 0 || *moedas05 > 0) && (_troco >= valoresMoedas[i])) {
            _troco -= valoresMoedas[i];
            switch (i) {
                case 0:
                    (*moedas1)--;
                    quantidadeMoedas[0]++;
                    break;
                case 1:
                    (*moedas05)--;
                    quantidadeMoedas[1]++;
                    break;
            }
        }
    }

    // Impressão da quantidade de cada cédula/moeda
    for (int i = 0; i < 5; i++) {
        if (quantidadeCedulas[i] > 0) {
            printf("%d cedula(s) de R$%d\n", quantidadeCedulas[i], valoresCedulas[i]);
        }
    }

    for (int i = 0; i < 2; i++) {
        if (quantidadeMoedas[i] > 0) {
            printf("%d moeda(s) de R$%.1f\n", quantidadeMoedas[i], valoresMoedas[i]);
        }
    }
}

// Função para fechar o caixa
void fecharCaixaFuncao(int clientes, float totalVendas, float valorExistente,
                       int notas200, int notas100, int notas50, int notas10, int notas5,
                       int moedas1, int moedas05) {

    system("cls");
    printf("========================================\n\n");
    printf("Fechamento do Caixa!!\n");
    printf("Numero de clientes atendidos: %d\n", clientes);
    printf("Valor total das vendas: R$%.2f\n", totalVendas);
    printf("Valor existente no caixa: R$%.2f\n", valorExistente);

    printf("\nQuantidade de cedulas restantes no caixa:\n");
    printf("%d cedula(s) de R$200\n", notas200);
    printf("%d cedula(s) de R$100\n", notas100);
    printf("%d cedula(s) de R$50\n", notas50);
    printf("%d cedula(s) de R$10\n", notas10);
    printf("%d cedula(s) de R$5\n", notas5);

    printf("\nQuantidade de moedas restantes no caixa:\n");
    printf("%d moeda(s) de R$1.00\n", moedas1);
    printf("%d moeda(s) de R$0.50\n", moedas05);

    printf("\n========================================");
    sleep(5);
}

// Função principal
int main() {

	//Variaveis
    int senha = 1234;
    int tentativas = 3;
    int senhaInserida;

    float dinheiroCaixa = 1280.0;
    int notas200 = 2, notas100 = 4, notas50 = 6, notas10 = 10, notas5 = 10;
    int moedas1 = 20, moedas05 = 20;

	int numeroVendas = 0;
	float dinheiroCaixaTotal = 0.0;
    float valorTotalVendas = 0.0;
    float valorTodasVendas =0.0;

    int fecharCaixa = 0;
    int clientes = 1;

    // Loop principal do caixa
    while (fecharCaixa == 0) {

        valorTotalVendas = 0;

    	system("cls");
        printf("Bem-vindo(a) ao caixa do supermercado!\n");

        // Sistema de senha
        while (tentativas > 0) {
            printf("Insira a senha para abrir o caixa: ");
            scanf("%d", &senhaInserida);

            if (senhaInserida == senha) {
            	system("cls");
                printf("\nCaixa aberto com sucesso!\n\n");
                break;
            } else {
                tentativas--;
                printf("\nSenha incorreta! Tente novamente. Voce tem mais %d tentativas!\n\n", tentativas);
            }
        }

        if (tentativas == 0) {
        	system("cls");
            printf("Numero maximo de tentativas excedido. Reinicie o sistema.\n");
            return 0;
        }

        // Sistema de inserção de itens
        numeroVendas = 0;

        while (1) {
            float valorItem;

            printf("Insira o valor do item (%d) (ou zero para finalizar a venda): ", numeroVendas + 1);
            scanf("%f", &valorItem);

            if (valorItem == 0.0) {
                char opcao;
                printf("Fechar a lista de itens? (S/N): ");
                scanf(" %c", &opcao);

                if (opcao == 'S' || opcao == 's') {
                	system("cls");
                    printf("Lista Finalizada %d Itens.\n", numeroVendas);
                    printf("Aguarde um segundo.....\n");
                    sleep(2);
                    break;
                } else if (opcao == 'N' || opcao == 'n') {
                    continue;
                }
            }

            if (valorItem == -1) {
                printf("Valor desconsiderado. Digite o valor correto do Item (%d): ", numeroVendas + 1);
                scanf("%f", &valorItem);

                if (valorItem == -1) {
                    printf("Valor ainda invalido. Item desconsiderado.\n");
                    continue;
                }
            }

            if (valorItem < 0.0 && valorItem != -1) {
                printf("Valor incorreto. Item desconsiderado.\n");
                continue;
            }

            valorTotalVendas += valorItem;
            numeroVendas++;
        }

        valorTodasVendas = valorTotalVendas;

        // Sistema de Troco
        float valorPago;
        float troco;

        system("cls");
        printf("====================================\n");
        printf("\nVenda Finalizada!!\n");
        printf("Total da venda: R$%.2f\n", valorTotalVendas);
        printf("\n====================================\n\n");

        printf("Insira o valor pago pelo cliente: ");
        scanf("%f", &valorPago);

        //calculo do troco
        troco = valorPago - valorTotalVendas;

        //calculo do dinheiro total no caixa
        dinheiroCaixaTotal = dinheiroCaixa - troco;

        if (troco > dinheiroCaixaTotal) {
                printf("Troco Indisponivel");
                return 0;
            }

        if (valorPago == valorTotalVendas) {
            printf("Nao ha troco!\n\n");

			char opcao;
            printf("Deseja fechar o caixa? (S/N): ");
            scanf(" %c", &opcao);

            if (opcao == 'S' || opcao == 's') {
                fecharCaixa = 1;
                fecharCaixaFuncao(clientes, valorTodasVendas, dinheiroCaixaTotal, notas200, notas100, notas50, notas10, notas5, moedas1, moedas05);
            } else if (opcao == 'N' || opcao == 'n') {
                clientes++;
                continue;
            }
        } else if (valorPago > valorTotalVendas) {
            dinheiroCaixaTotal -= troco;
            printf("Troco a ser devolvido: R$%.2f\n\n", troco);

            calculoQuantidadeNotas(troco, &notas200, &notas100, &notas50, &notas10, &notas5, &moedas1, &moedas05);

            char opcao;
            printf("\nDeseja fechar o caixa? (S/N): ");
            scanf(" %c", &opcao);

            if (opcao == 'S' || opcao == 's') {
                fecharCaixa = 1;
                fecharCaixaFuncao(clientes, valorTodasVendas, dinheiroCaixaTotal, notas200, notas100, notas50, notas10, notas5, moedas1, moedas05);
            } else if (opcao == 'N' || opcao == 'n') {
                clientes++;
                continue;
            }
        }

        while (valorPago < valorTotalVendas) {
            char opcao;
            printf("\nValor pago insuficiente. Deseja cancelar a compra? (S/N): ");
            scanf(" %c", &opcao);

            if (opcao == 'S' || opcao == 's') {
                system("cls");
				printf("Compra cancelada desligando o sistema....");
				sleep(2);
                return 0;
            } else if (opcao == 'N' || opcao == 'n') {
                printf("\nInforme o valor novamente: ");
                scanf("%f", &valorPago);

                if (valorPago < valorTotalVendas) {
                    system("cls");
					printf("Compra cancelada desligando o sistema....");
					sleep(2);
                    return 0;
                } else {
                    if (valorPago == valorTotalVendas)
					{
                        printf("Nao ha troco!\n\n");

                        char opcao;
			            printf("Deseja fechar o caixa? (S/N): ");
			            scanf(" %c", &opcao);

			            if (opcao == 'S' || opcao == 's') {
			                fecharCaixa = 1;
			                fecharCaixaFuncao(clientes, valorTodasVendas, dinheiroCaixaTotal, notas200, notas100, notas50, notas10, notas5, moedas1, moedas05);
			            } else if (opcao == 'N' || opcao == 'n') {
			                clientes++;
			                continue;
			            }
                    }
					else if (valorPago > valorTotalVendas) {
                        dinheiroCaixaTotal -= troco;
                        printf("Troco a ser devolvido: R$%.2f\n\n", troco);

                        calculoQuantidadeNotas(troco, &notas200, &notas100, &notas50, &notas10, &notas5, &moedas1, &moedas05);

						char opcao;
			            printf("\nDeseja fechar o caixa? (S/N): ");
			            scanf(" %c", &opcao);

			            if (opcao == 'S' || opcao == 's') {
			                fecharCaixa = 1;
			                fecharCaixaFuncao(clientes, valorTodasVendas, dinheiroCaixaTotal, notas200, notas100, notas50, notas10, notas5, moedas1, moedas05);
			            } else if (opcao == 'N' || opcao == 'n') {
			                clientes++;
			                continue;
			            }

                        if (troco > dinheiroCaixaTotal) {
                            printf("Troco Indisponível");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
