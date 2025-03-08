#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define TAM 3

// Função para limpar o buffer de entrada (evita erros ao usar scanf)
void limpaBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu principal
void printMenu() {
    printf("\n");
    printf("===================================\n");
    printf("       BEM-VINDO AO JOGO DA VELHA  \n");
    printf("===================================\n");
    printf("            1 - Jogar              \n");
    printf("            2 - Sair               \n");
    printf("===================================\n");
    printf(" Escolha uma opção: ");
}

// Função para imprimir o tabuleiro do jogo da velha
void printMatriz(char matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            printf(" %c ", matriz[i][j]);

            if (j < TAM - 1) 
            {
                printf("|"); // Adiciona separador de colunas
            }
        }

        printf("\n");

        if (i < TAM - 1) 
        {
            printf("---+---+---\n"); // Adiciona separador de linhas
        }
    }
}

// Função para verificar se há um vencedor
int verifica(char matriz[TAM][TAM]) {
    // Retornos:
    // 0 -> Jogador X venceu
    // 1 -> Jogador O venceu
    // -1 -> Nenhum jogador venceu ainda

    // Verificação horizontal (linhas)
    for (int i = 0; i < TAM; i++) {
        if (matriz[i][0] == 'X' && matriz[i][1] == 'X' && matriz[i][2] == 'X') 
        {
            return 0;
        }

        if (matriz[i][0] == 'O' && matriz[i][1] == 'O' && matriz[i][2] == 'O') 
        {
            return 1;
        }
    }

    // Verificação vertical (colunas)
    for (int j = 0; j < TAM; j++) {
        if (matriz[0][j] == 'X' && matriz[1][j] == 'X' && matriz[2][j] == 'X') 
        {
            return 0;
        }

        if (matriz[0][j] == 'O' && matriz[1][j] == 'O' && matriz[2][j] == 'O') 
        {
            return 1;
        }
    }

    // Verificação diagonal principal (\)
    bool ganhouX = true;
    bool ganhouO = true;
    for (int i = 0; i < TAM; i++) 
    {
        if (matriz[i][i] != 'X') 
        {
            ganhouX = false;
        }

        if (matriz[i][i] != 'O') 
        {
            ganhouO = false;
        }
    }

    if (ganhouX) return 0;
    if (ganhouO) return 1;

    // Verificação diagonal secundária (/)
    ganhouX = true;
    ganhouO = true;
    for (int i = 0; i < TAM; i++) 
    {
        if (matriz[i][TAM - 1 - i] != 'X') 
        {
            ganhouX = false;
        }

        if (matriz[i][TAM - 1 - i] != 'O') 
        {
            ganhouO = false;
        }
    }

    if (ganhouX) return 0;
    if (ganhouO) return 1;

    // Se ninguém ganhou ainda, retorna -1
    return -1;
}

int main() {
    // Inicializa o tabuleiro vazio
    char matriz[TAM][TAM] = {{' ', ' ', ' '}, 
                             {' ', ' ', ' '}, 
                             {' ', ' ', ' '}};

    int linha, coluna, resultado, ganhador, temp, escolha;
    bool completo;

    while (true) {
        // Exibe o menu e recebe a opção do usuário
        do {
            printMenu();
            temp = scanf("%d", &escolha);
            limpaBuffer();

            if (temp != 1 || (escolha != 1 && escolha != 2)) 
            {
                printf("Operação Indisponível! Escolha 1 para Jogar ou 2 para Sair.\n");
            }
        } while (temp != 1 || (escolha != 1 && escolha != 2));

        if (escolha == 2) 
        {
            system("clear");
            printf("\nSaindo do jogo... Até logo!\n");
            exit(0);
        }

        // Reseta o tabuleiro antes de iniciar um novo jogo
        for (int i = 0; i < TAM; i++) 
        {
            for (int j = 0; j < TAM; j++) 
            {
                matriz[i][j] = ' ';
            }
        }
        
        ganhador = -1;
        system("clear");
        printMatriz(matriz);

        // Loop principal do jogo
        while (true) {
            // Turno do Jogador X
            do {
                printf("\nJogador X: Digite a Linha e a Coluna (ex: 3 2): ");
                resultado = scanf("%d %d", &linha, &coluna);
                limpaBuffer();

                if (resultado != 2 || linha < 1 || linha > TAM || coluna < 1 || coluna > TAM) 
                {
                    printf("\nEntrada inválida! Digite números entre 1 e %d.\n", TAM);
                    continue;
                }
                else if (matriz[linha - 1][coluna - 1] != ' ') 
                {
                    printf("\nPosição ocupada! Escolha outra.");
                    continue;
                }
                else 
                {
                    matriz[linha - 1][coluna - 1] = 'X';
                    system("clear");
                    printMatriz(matriz);
                    break;
                }
            } while (1);

            ganhador = verifica(matriz);
            if (ganhador != -1) break;

            // Verifica se o tabuleiro está cheio (empate)
            completo = true;
            for (int i = 0; i < TAM; i++) 
            {
                for (int j = 0; j < TAM; j++) 
                {
                    if (matriz[i][j] == ' ') 
                    {
                        completo = false;
                        break;
                    }
                }
                if (!completo) break;
            }
            if (completo) break;

            // Turno do Jogador O
            do {
                printf("\nJogador O: Digite a Linha e a Coluna (ex: 3 2): ");
                resultado = scanf("%d %d", &linha, &coluna);
                limpaBuffer();

                if (resultado != 2 || linha < 1 || linha > TAM || coluna < 1 || coluna > TAM) 
                {
                    printf("\nEntrada inválida! Digite números entre 1 e %d.\n", TAM);
                    continue;
                }
                else if (matriz[linha - 1][coluna - 1] != ' ') 
                {
                    printf("\nPosição ocupada! Escolha outra.");
                    continue;
                }
                else 
                {
                    matriz[linha - 1][coluna - 1] = 'O';
                    system("clear");
                    printMatriz(matriz);
                    break;
                }
            } while (1);

            ganhador = verifica(matriz);
            if (ganhador != -1) break;
        }

        // Exibe o resultado final do jogo
        if (ganhador == 0) 
        {
            printf("\nParabéns, o X ganhou!\n");
            sleep(5);
            system("clear");
        } 
        else if (ganhador == 1) 
        {
            printf("\nParabéns, o O ganhou!\n");
            sleep(5);
            system("clear");
        } 
        else 
        {
            printf("\nO jogo terminou em empate!\n");
            sleep(5);
            system("clear");
        }
    }

    return 0;
}
