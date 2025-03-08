#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a > 10 && b > 10 && c > 10)
    {
        printf("Todos sao maiores que 10");
    } else {
        printf("nem todos sao maiores que 10");
    }
    
    return 0;
}