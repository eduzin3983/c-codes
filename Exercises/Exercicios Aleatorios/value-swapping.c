#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    printf("Choose the value of A: ");
    scanf("%d", &a);

    printf("Choose the value of B: ");
    scanf("%d", &b);

    printf("\nA = %d, B = %d \n", a, b);

    c = a;
    a = b;
    b = c;

    printf("\nAfter swapping, it will be: A = %d, B = %d \n", a, b);

    return 0;
}
