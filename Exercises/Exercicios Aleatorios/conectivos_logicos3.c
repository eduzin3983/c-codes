#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a > 10 || b > 10)
    {
        printf("Maior que 10");
    } else {
        printf("menor que 10");
    }
    
    return 0;
}