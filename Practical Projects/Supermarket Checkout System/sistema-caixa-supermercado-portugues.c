#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Função para definir a quantidade de cédulas/moedas para o troco
void calculoQuantidadeNotas(float troco, int *notas200, int *notas100, int *notas50, int *notas10, int *notas5, int *moedas1, int *moedas05) {
    int count200 = 0, count100 = 0, count50 = 0, count10 = 0, count5 = 0;
    int count1 = 0, count05 = 0;
    
    // Verifica para cada valor se há troco suficiente e se há cédulas/moedas disponíveis
    while (troco >= 200 && *notas200 > 0) {
        troco -= 200;
        (*notas200)--;
        count200++;
    }
    while (troco >= 100 && *notas100 > 0) {
        troco -= 100;
        (*notas100)--;
        count100++;
    }
    while (troco >= 50 && *notas50 > 0) {
        troco -= 50;
        (*notas50)--;
        count50++;
    }
    while (troco >= 10 && *notas10 > 0) {
        troco -= 10;
        (*notas10)--;
        count10++;
    }
    while (troco >= 5 && *notas5 > 0) {
        troco -= 5;
        (*notas5)--;
        count5++;
    }
    while (troco >= 1.0 && *moedas1 > 0) {
        troco -= 1.0;
        (*moedas1)--;
        count1++;
    }
    while (troco >= 0.5 && *moedas05 > 0) {
        troco -= 0.5;
        (*moedas05)--;
        count05++;
    }
    
    // Impressão da quantidade de cada cédula/moeda utilizada para o troco
    if (count200 > 0)
        printf("%d cedula(s) de R$200\n", count200);
    if (count100 > 0)
        printf("%d cedula(s) de R$100\n", count100);
    if (count50 > 0)
        printf("%d cedula(s) de R$50\n", count50);
    if (count10 > 0)
        printf("%d cedula(s) de R$10\n", count10);
    if (count5 > 0)
        printf("%d cedula(s) de R$5\n", count5);
    if (count1 > 0)
        printf("%d moeda(s) de R$1.00\n", count1);
    if (count05 > 0)
        printf("%d moeda(s) de R$0.50\n", count05);
}

// Função para fechar o caixa
void fecharCaixaFuncao(int clientes, float totalVendas, float valorExistente,
                         int notas200, int notas100, int notas50, int notas10, int notas5,
                         int moedas1, int moedas05) {

    system("clear");
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

    printf("\n========================================\n");
    sleep(5);
}

// Função principal
int main() {
    // Variáveis de configuração e estado
    int senha = 1234;
    int tentativas = 3;
    int senhaInserida;

    float dinheiroCaixa = 1280.0; // Valor inicial do caixa
    int notas200 = 2, notas100 = 4, notas50 = 6, notas10 = 10, notas5 = 10;
    int moedas1 = 20, moedas05 = 20;

    int numeroVendas;
    float valorTotalVendas = 0.0; // Valor da venda atual
    float totalVendasAcumulado = 0.0; // Acumulador do valor de todas as vendas
    float valorPago, troco;

    int fecharCaixa = 0;
    int clientes = 0;  // Contador de clientes atendidos

    // Solicita a senha apenas no início da sessão
    system("clear");
    while (tentativas > 0) {
        printf("Insira a senha para abrir o caixa: ");
        scanf("%d", &senhaInserida);

        if (senhaInserida == senha) {
            system("clear");
            printf("\nCaixa aberto com sucesso!\n\n");
            break;
        } else {
            tentativas--;
            printf("\nSenha incorreta! Tente novamente. Voce tem mais %d tentativas!\n\n", tentativas);
        }
    }
    if (tentativas == 0) {
        system("clear");
        printf("Numero maximo de tentativas excedido. Reinicie o sistema.\n");
        return 0;
    }

    // Loop principal do caixa
    while (!fecharCaixa) {
        valorTotalVendas = 0.0;
        numeroVendas = 0;

        // Entrada dos itens da venda
        while (1) {
            float valorItem;
            printf("Insira o valor do item (%d) (ou zero para finalizar a venda): ", numeroVendas + 1);
            scanf("%f", &valorItem);

            if (valorItem == 0.0) {
                char opcao;
                printf("Fechar a lista de itens? (S/N): ");
                scanf(" %c", &opcao);
                if (opcao == 'S' || opcao == 's') {
                    system("clear");
                    printf("Lista finalizada com %d item(ns).\n", numeroVendas);
                    sleep(1);
                    break;
                } else if (opcao == 'N' || opcao == 'n') {
                    continue;
                }
            }
            if (valorItem == -1) {
                printf("Valor desconsiderado. Digite o valor correto do item (%d): ", numeroVendas + 1);
                scanf("%f", &valorItem);
                if (valorItem == -1) {
                    printf("Valor ainda inválido. Item desconsiderado.\n");
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

        // Mostra o total da venda atual
        system("clear");
        printf("====================================\n");
        printf("\nVenda Finalizada!!\n");
        printf("Total da venda: R$%.2f\n", valorTotalVendas);
        printf("\n====================================\n\n");

        // Processa o pagamento
        printf("Insira o valor pago pelo cliente: ");
        scanf("%f", &valorPago);

        // Se o valor pago for insuficiente, permite cancelar ou tentar novamente
        while (valorPago < valorTotalVendas) {
            char opcao;
            printf("\nValor pago insuficiente. Deseja cancelar a compra? (S/N): ");
            scanf(" %c", &opcao);
            if (opcao == 'S' || opcao == 's') {
                system("clear");
                printf("Compra cancelada. Encerrando o sistema...\n");
                sleep(2);
                return 0;
            } else if (opcao == 'N' || opcao == 'n') {
                printf("\nInforme o valor novamente: ");
                scanf("%f", &valorPago);
            }
        }

        // Atualiza o caixa e o acumulado de vendas
        dinheiroCaixa += valorTotalVendas;
        totalVendasAcumulado += valorTotalVendas;
        clientes++;

        // Se houver troco (valor pago maior que total da venda)
        if (valorPago > valorTotalVendas) {
            troco = valorPago - valorTotalVendas;
            // Verifica se há dinheiro suficiente para dar o troco
            if (troco > dinheiroCaixa) {
                printf("Troco indisponivel. Operação cancelada.\n");
                return 0;
            }
            // Atualiza o caixa: retira o valor do troco dado
            dinheiroCaixa -= troco;
            printf("Troco a ser devolvido: R$%.2f\n\n", troco);
            calculoQuantidadeNotas(troco, &notas200, &notas100, &notas50, &notas10, &notas5, &moedas1, &moedas05);
        } else {
            printf("Pagamento exato. Nao ha troco!\n\n");
        }

        // Pergunta se deseja fechar o caixa
        char opcao;
        printf("\nDeseja fechar o caixa? (S/N): ");
        scanf(" %c", &opcao);
        if (opcao == 'S' || opcao == 's') {
            fecharCaixa = 1;
            fecharCaixaFuncao(clientes, totalVendasAcumulado, dinheiroCaixa,
                              notas200, notas100, notas50, notas10, notas5,
                              moedas1, moedas05);
        }
        
    }

    return 0;
}
