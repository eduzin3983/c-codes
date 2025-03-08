#include <stdio.h>
#include <stdlib.h>

int main(){

    int valorInicial, valorFinal, mult;
    scanf("%d", &valorInicial);
    scanf("%d", &valorFinal);
    scanf("%d", &mult);

    for (int i = valorInicial; i <= valorFinal; i += mult)
    {
        printf("%d\n", i);
    }
    
    
    return 0;
}