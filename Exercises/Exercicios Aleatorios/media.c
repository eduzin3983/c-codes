#include <stdio.h>
#include <stdlib.h>

int main(){

    float a, b;

    scanf("%f", &a);
    scanf("%f", &b);

    float media = (a + b) / 2.0;

    printf("A Média entre %.2f e %.2f é: %.2f", a, b, media);

    return 0;
}