#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("É um numero PAR");
    } else {
        printf("é um numero ímpar");
    }
    
    return 0;
}