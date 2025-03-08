#include <stdio.h>
#include <stdlib.h>

int main(){

    int a, b;
    
    while (1)
    {
        scanf("%d", &a);
        scanf("%d", &b);

        if (a >= 5 && a <=10 && b >= 5 && b <= 10)
        {
            int soma = a + b;
            printf("%d\n", soma);
            break;
        } else {
            printf("Os numeros nao estao dentro de 5 e 10 digite novamente: \n");
        }
        
    }

    return 0;
}