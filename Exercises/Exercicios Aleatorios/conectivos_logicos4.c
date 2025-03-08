#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a % 2 == 0 || b % 2 == 0)
    {
        printf("Par");
    } else {
        printf("Impars");
    }
    
    return 0;
}