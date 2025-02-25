#include <stdio.h>

int main() {
    int n, i = 1;
    int acum = 0;

    scanf("%d", &n);

    while (i <= n)
    {
        i++;
        acum += n * i;
    }
    
    printf("%d\n", acum);

    return 0;
}