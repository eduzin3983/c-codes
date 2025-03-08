#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    
    int n1, n2;
    int temp = 0;
    bool teste = true;

    while (true)
    {
        scanf("%d", &n1);

        if (n1 < 0)
        {
            exit(0);
        }

        int i = 0;
        while (i < n1)
        {
            i++;

            scanf("%d", &n2);

            if (temp > n2)
            {
                teste = false;
            }

            temp = n2;
        }
        
        if (teste)
        {
            printf("Esta ordenado \n");
        } else {
            printf("Nao esta ordenado \n");
        }
            
    }

    return 0;
}
