#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if(a+b >= 10) {
        printf("A soma de A + B é Maior ou Igual a 10");
    } else if (a+b < 10)
    {
        printf("A soma de A + B é Menor que 10");
    }

    return 0;
}