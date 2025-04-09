/*A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes, coletando
dados sobre o salário, idade, sexo e número de filhos. Use a estrutura seguinte...

struct dados{
int idade, filhos;
float salario;
char sexo;
}
...faça um programa que leia os dados de 100 habitantes e calcule:
- A média de idade das mulheres com salário inferior ao salário mínimo.
- A média de salário da população.
- A média do número de filhos.
- A menor idade do sexo feminino.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HABITANTES 2
#define SALARIO_MINIMO 1518.0

typedef struct
{
    int idade, filhos;
    float salario;
    char sexo;
} dados;

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{

    dados Pessoas[HABITANTES];

    // Le dados
    for (int i = 0; i < HABITANTES; i++)
    {
        printf("Habitante %d\n", i + 1);

        printf("Idade: ");
        scanf("%d", &Pessoas[i].idade);

        printf("Número de filhos: ");
        scanf("%d", &Pessoas[i].filhos);

        printf("Salário: ");
        scanf("%f", &Pessoas[i].salario);

        do
        {
            printf("Sexo (M - Masculino, F - Feminino): ");
            limpaBuffer();
            scanf("%c", &Pessoas[i].sexo);

            Pessoas[i].sexo = toupper(Pessoas[i].sexo);

            if (Pessoas[i].sexo != 'M' && Pessoas[i].sexo != 'F')
            {
                printf("Dado inválido\n");
            }

        } while (Pessoas[i].sexo != 'M' && Pessoas[i].sexo != 'F');

        printf("\n");
    }

    float somaMediaIdade = 0;
    int qtdMediaIdade = 0;

    float somaMediaSalario = 0;

    int somaMediaFilhos = 0;

    int menorIdadeFem = 0;
    int temMulher = 0;

    // Primeiro loop para iniciar menorIdadeFem com a primeira mulher encontrada
    for (int i = 0; i < HABITANTES; i++)
    {
        if (Pessoas[i].sexo == 'F')
        {
            menorIdadeFem = Pessoas[i].idade;
            temMulher = 1;
            break;
        }
    }

    // Segundo loop para cálculos
    for (int i = 0; i < HABITANTES; i++)
    {
        if (Pessoas[i].sexo == 'F' && Pessoas[i].salario < SALARIO_MINIMO)
        {
            somaMediaIdade += Pessoas[i].idade;
            qtdMediaIdade++;
        }

        somaMediaSalario += Pessoas[i].salario;
        somaMediaFilhos += Pessoas[i].filhos;

        if (Pessoas[i].sexo == 'F' && Pessoas[i].idade < menorIdadeFem)
        {
            menorIdadeFem = Pessoas[i].idade;
        }
    }

    float mediaIdade = 0;
    if (qtdMediaIdade > 0) {
        mediaIdade = somaMediaIdade / (float)qtdMediaIdade;
    }

    float mediaSalario = somaMediaSalario / (float)HABITANTES;
    float mediaFilhos = (float)somaMediaFilhos / (float)HABITANTES;

    printf("\n--- RESULTADOS DA PESQUISA ---\n");

    if (qtdMediaIdade > 0) {
        printf("Média de idade das mulheres com salário inferior ao salário mínimo: %.2f\n", mediaIdade);
    } else {
        printf("Nenhuma mulher com salário inferior ao salário mínimo.\n");
    }

    printf("Média de salário da população: %.2f\n", mediaSalario);
    printf("Média do número de filhos: %.2f\n", mediaFilhos);

    if (temMulher) {
        printf("Menor idade entre as mulheres: %d\n", menorIdadeFem);
    } else {
        printf("Não possui pessoas do sexo feminino na pesquisa\n");
    }

    return 0;
}
