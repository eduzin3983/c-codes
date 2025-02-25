/* Sendo H= 1 + 1/2 + 1/3 + 1/4 + ... + 1/N, Faça um programa
que calcule o valor de H com N termos. */

#include <stdio.h>

int main(){

    int n;
    double H = 0.0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        H += 1.0 / i;
    }
    
    printf("%.2f", H);
    
    return 0;
}