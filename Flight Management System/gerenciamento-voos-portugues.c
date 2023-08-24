#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//#include<windows.h> For Windows
#include<unistd.h> //For Linux
#include <time.h>

typedef struct {
    int codigoVoo;
    char cidadeOrigem[11];
    char cidadeDestino[11];
    int numeroEscalas;
} Voo;

void incluir(Voo voos[], int *posicao) {
    int MAX_VOOS = 50;
    int MAX_CIDADE = 11;

    if (*posicao >= MAX_VOOS) {
        printf("Limite de voos atingido.\n");
        return;
    }

    Voo novoVoo;
    system("cls");
    printf("\nCodigo do Voo (4 digitos): ");
    scanf("%d", &novoVoo.codigoVoo);
    printf("Cidade de Origem: ");
    scanf(" %[^\n]s", novoVoo.cidadeOrigem);
    printf("Cidade de Destino: ");
    scanf(" %[^\n]s", novoVoo.cidadeDestino);
    printf("Numero de escalas: ");
    scanf("%d", &novoVoo.numeroEscalas);

    voos[*posicao] = novoVoo;
    (*posicao)++;

    printf("\n-------------------------------------------\n\n");
    printf("Voo Cadastrado com Sucesso");
    sleep(2);
    system("cls");
}

void listar(Voo voos[], int posicao) {
    if (posicao == 0) {
        system("cls");
        printf("Nenhum voo cadastrado.\n");
        sleep(2);
        system("cls");
        return;
    }

    system("cls");
    printf("Voos disponiveis:\n\n");

    printf("-------------------------------------------\n");
    for (int i = 0; i < posicao; i++) {
        printf("Codigo: %d\n", voos[i].codigoVoo);
        printf("Cidade Origem: %s\n", voos[i].cidadeOrigem);
        printf("Cidade Destino: %s\n", voos[i].cidadeDestino);
        printf("Numero de escalas: %d\n", voos[i].numeroEscalas);
        printf("-------------------------------------------\n");
    }
    printf("\n");
}

void alterar(Voo voos[], int posicao) {
    int codigoVoo;
    system("cls");
    printf("Digite o codigo do voo que deseja alterar: ");
    scanf("%d", &codigoVoo);

    int indiceVoo = -1;
    int i;
    for (i = 0; i < posicao; i++) {
        if (voos[i].codigoVoo == codigoVoo) {
            indiceVoo = i;
            break;
        }
    }

    if (indiceVoo == -1) {
        system("cls");
        printf("Voo nao encontrado.\n");
        sleep(2);
        system("cls");
        return;
    }

    printf("\nNovas informacoes do voo:\n");
    printf("Cidade de Origem: ");
    scanf(" %[^\n]s", voos[indiceVoo].cidadeOrigem);
    printf("Cidade de Destino: ");
    scanf(" %[^\n]s", voos[indiceVoo].cidadeDestino);
    printf("Numero de escalas: ");
    scanf("%d", &voos[indiceVoo].numeroEscalas);

    printf("\nInformacoes do voo alteradas com sucesso.\n");
    sleep(2);
}

void excluir(Voo voos[], int *posicao) {
    int MAX_VOOS = 50;

    int codigoVoo;
    system("cls");
    printf("Digite o codigo do voo que deseja apagar: ");
    scanf("%d", &codigoVoo);

    int indiceVoo = -1;
    for (int i = 0; i < *posicao; i++) {
        if (voos[i].codigoVoo == codigoVoo) {
            indiceVoo = i;
            break;
        }
    }

    if (indiceVoo == -1) {
        printf("\nVoo nao encontrado.\n");
        sleep(2);
        system("cls");
        return;
    }

    // Desloca os voos seguintes para preencher o voo apagado
    for (int i = indiceVoo; i < *posicao - 1; i++) {
        voos[i] = voos[i + 1];
    }

    (*posicao)--;

    system("cls");
    printf("Voo apagado com sucesso.\n");
    sleep(2);
    system("cls");
}

void voosPorCidadeOrigem(Voo voos[], int posicao) {
    char cidadeOrigem[11];
    int contador = 0;

    system("cls");
    printf("Digite a cidade de origem: ");
    scanf(" %[^\n]s", cidadeOrigem);

    system("cls");
    printf("Voos saindo da cidade %s:\n\n", cidadeOrigem);
    printf("-------------------------------------------");

    for (int i = 0; i < posicao; i++) {
        if (strcmp(voos[i].cidadeOrigem, cidadeOrigem) == 0) {
            printf("\nCodigo: %d\n", voos[i].codigoVoo);
            printf("Cidade de Origem: %s\n", voos[i].cidadeOrigem);
            printf("Cidade de Destino: %s\n", voos[i].cidadeDestino);
            printf("Escalas: %d\n", voos[i].numeroEscalas);
            printf("-------------------------------------------");
            contador++;
        }
    }

    if (contador == 0) {
        system("cls");
        printf("Nenhum voo encontrado saindo da cidade %s.\n", cidadeOrigem);
        sleep(3);
        system("cls");
    } else {
        printf("\n\nQuantidade de voos saindo da cidade %s: %d\n", cidadeOrigem, contador);
    }
}

void voocomMenorNumeroEscalas(Voo voos[], int posicao) {
    char cidadeOrigem[11];
    char cidadeDestino[11];
    int menorEscalas = INT_MAX;
    int indiceVoo = -1;

    system("cls");
    printf("Digite a cidade de origem: ");
    scanf(" %[^\n]s", cidadeOrigem);
    printf("Digite a cidade de destino: ");
    scanf(" %[^\n]s", cidadeDestino);

    for (int i = 0; i < posicao; i++) {
        if (strcmp(voos[i].cidadeOrigem, cidadeOrigem) == 0 && strcmp(voos[i].cidadeDestino, cidadeDestino) == 0) {
            if (voos[i].numeroEscalas < menorEscalas) {
                menorEscalas = voos[i].numeroEscalas;
                indiceVoo = i;
            }
        }
    }

    if (indiceVoo != -1) {
        system("cls");
        printf("Voo com o menor numero de escalas de %s para %s:\n", cidadeOrigem, cidadeDestino);
        printf("-------------------------------------------\n");
        printf("Codigo: %d\n", voos[indiceVoo].codigoVoo);
        printf("Cidade de Origem: %s\n", voos[indiceVoo].cidadeOrigem);
        printf("Cidade de Destino: %s\n", voos[indiceVoo].cidadeDestino);
        printf("Escalas: %d\n", voos[indiceVoo].numeroEscalas);
        printf("-------------------------------------------\n\n");
    } else {
        system("cls");
        printf("Nenhum voo encontrado com a combina ao de cidades %s para %s.\n", cidadeOrigem, cidadeDestino);
        sleep(2);
        system("cls");
    }
}

void pesquisar(Voo voos[], int posicao) {
    int codigoVoo;
    system("cls");
    printf("Digite o codigo do voo que deseja pesquisar: ");
    scanf("%d", &codigoVoo);

    int indiceVoo = -1;
    for (int i = 0; i < posicao; i++) {
        if (voos[i].codigoVoo == codigoVoo) {
            indiceVoo = i;
            break;
        }
    }

    if (indiceVoo == -1) {
        system("cls");
        printf("Voo nao encontrado.\n");
        sleep(2);
        system("cls");
        return;
    }

    system("cls");
    printf("Voo encontrado:\n");
    printf("-------------------------------------------\n");
    printf("Codigo: %d\n", voos[indiceVoo].codigoVoo);
    printf("Cidade Origem: %s\n", voos[indiceVoo].cidadeOrigem);
    printf("Cidade Destino: %s\n", voos[indiceVoo].cidadeDestino);
    printf("Numero de escalas: %d\n", voos[indiceVoo].numeroEscalas);
    printf("-------------------------------------------\n\n");
}

int main() {
    int MAX_VOOS = 50;
    int posicao = 0;
    Voo voos[MAX_VOOS];
    int opcao;

    do {
        printf("\nMenu Inicial\n\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Incluir\n");
        printf("2 - Listar\n");
        printf("3 - Alterar as informa oes sobre um voo\n");
        printf("4 - Excluir\n");
        printf("5 - Numero e informacoes dos voos que saem da mesma cidade\n");
        printf("6 - Voo com menor numero de escala para uma rota\n");
        printf("7 - Pesquisar\n");
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n\n\n");

        switch (opcao) {
            case 1:
                incluir(voos, &posicao);
                break;
            case 2:
                listar(voos, posicao);
                break;
            case 3:
                alterar(voos, posicao);
                break;
            case 4:
                excluir(voos, &posicao);
                break;
            case 5:
                voosPorCidadeOrigem(voos, posicao);
                break;
            case 6:
                voocomMenorNumeroEscalas(voos, posicao);
                break;
            case 7:
                pesquisar(voos, posicao);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                system("cls");
                printf("Opcao invalida. Tente novamente.\n");
                sleep(2);
                system("cls");
                break;
        }

    } while (opcao != 0);

    return 0;
}
