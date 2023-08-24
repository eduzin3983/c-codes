#include <stdio.h>
#include <stdlib.h>

int main()
{

    float salary;
    float adjustmentPercentage;
    float result;

    printf("Salary: ");
    scanf("%f", &salary);

    printf("Adjustment percentage: ");
    scanf("%f", &adjustmentPercentage);

    result = salary * (1 + (adjustmentPercentage / 100));
    printf("%2.f\n", result);

    return 0;
}
