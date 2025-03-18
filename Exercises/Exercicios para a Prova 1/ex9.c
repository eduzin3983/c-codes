/*Um usuário deseja utilizar um sistema protegido por
senha. Ele tem 3 tentativas para acertar a senha correta.
Defina uma senha (tipo int) e faça um programa que
solicite a senha do usuário. Enquanto ele não acertar o
programa deverá imprimir “Acesso negado”. Caso
contrário, deverá imprimir “Acesso liberado”. */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int senha = 1234;
    int tentativa;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &tentativa);

        if (tentativa == senha) {
            printf("Acesso liberado!\n");
            exit(0);
        } else {
            printf("Acesso Negado! tente novamente!\n");
        }
    }    

    printf("Numero maximo de tentativas!\n");

    return 0;
}