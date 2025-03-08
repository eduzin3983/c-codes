#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int i = 10;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }

        i++;
        
    }

    return 0;
}