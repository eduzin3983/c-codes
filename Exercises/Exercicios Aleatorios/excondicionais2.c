#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a > b)
    {
        printf("A é maior que B");
    } else if (a < b)
    {
        printf("B é maior que A");
    } else {
        printf("Eles sao Iguais");
    }
    

    return 0;
}