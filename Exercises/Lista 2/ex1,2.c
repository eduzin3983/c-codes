#include <stdio.h>

int main() {
    int n, i = 1;
    int acum = 0;
    
    scanf("%d", &n);

    do {
        i++;
        acum += n * i;
    } while (i <= n);

    printf("%d", acum);

    return 0;
}
