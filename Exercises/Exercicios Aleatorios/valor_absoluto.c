#include <stdio.h>
#include <stdlib.h>

int main(){

    int nota1, nota2;

    scanf("%d", &nota1);
    scanf("%d", &nota2);

    printf("A diferenca absoluta entre %d e %d é %d", nota1, nota2, abs(nota1 - nota2));

    return 0;
}