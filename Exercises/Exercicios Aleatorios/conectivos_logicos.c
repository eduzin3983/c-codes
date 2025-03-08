#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    scanf("%d", &n);

    if (n >= 0 && n <= 10)
    {
        printf("Esse numero está entre 0 e 10");
    } else {
        printf("Esse numero NAO está entre 0 e 10");
    }
    
    return 0;
}