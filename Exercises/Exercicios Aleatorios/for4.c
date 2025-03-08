#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    bool primo = true;
    int n;
    scanf("%d", &n);

    if (n < 1)
    {
        primo = false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            primo = false;
            break;
        } else {
            primo = true;
        }
    }

    if (primo == true)
    {
        printf("É Primo");
    } else {
        printf("Não é Primo");
    }
        
    return 0;
}