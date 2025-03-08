#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int a;
    scanf("%d", &a);

    int fatorial = a;

    printf("%d! = %d", a, a);
    for (int i = a-1; i > 0; i--)
    {
        fatorial *= i;
        printf(" X %d", i);    
        
    }
    
    printf(" = %d\n", fatorial);

    return 0;
}
