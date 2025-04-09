/*Faça um programa que realize a leitura dos seguintes dados
relativos a um conjunto de alunos:
• RA - inteiro
• Código da Disciplina - inteiro de 4 dígitos
• Nota1 e Nota 2 – valores reais que podem ser
armazenados na forma de um vetor de 2 posições

Considere uma turma de até 10 alunos. 

Após ler todos os
dados digitados, e depois de armazená-los em um vetor de
estrutura, exibir na tela a listagem final dos alunos com as
suas respectivas medias finais (use uma média ponderada:
Nota1 com peso=1.0 e Nota2 com peso=2.0).
*/

#include <stdio.h>
#include <stdlib.h>

#define TURMA 2

typedef struct
{
    int RA;
    int codigoDisciplina;
    float nota[2];
} aluno;

int main() {

    aluno Lista[TURMA];

    for (int i = 0; i < TURMA; i++)
    {
        printf("Aluno %d:\n", i + 1);

        // Le RA
        printf("Digite o RA do aluno: ");
        scanf("%d", &Lista[i].RA);

        // Le Codigo Disciplina
        do
        {
            printf("Digite o código da disciplina (4 dígitos): ");
            scanf("%d", &Lista[i].codigoDisciplina);

            if (Lista[i].codigoDisciplina < 1000 || Lista[i].codigoDisciplina > 9999)
            {
                printf("Valor Indisponivel\n");
            }
        } while (Lista[i].codigoDisciplina < 1000 || Lista[i].codigoDisciplina > 9999);

        // Le Nota 1
        printf("Digite a Nota 1 do aluno: ");
        scanf("%f", &Lista[i].nota[0]);

        // Le Nota 2
        printf("Digite a Nota 2 do aluno: ");
        scanf("%f", &Lista[i].nota[1]);
        printf("\n");    

    }

    float mediaPonderada;
    for (int i = 0; i < TURMA; i++)
    {
        mediaPonderada = (Lista[i].nota[0] * 1.0 + Lista[i].nota[1] * 2.0) / 3; 
        printf("Media Final do Aluno %d: %.2f\n", i+1, mediaPonderada);
    }

    return 0;
}