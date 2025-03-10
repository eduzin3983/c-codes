/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, 
real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável 
usando os ponteiros. Imprima os valores das variáveis antes e após a modificação*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numInteiro = 10;
    float numReal = 13.4;
    char character = 'o';

    int *ptrInteiro = &numInteiro;
    float *ptrReal = &numReal;
    char *ptrChar = &character;

    printf("%d\n", numInteiro);
    printf("%.2f\n", numReal);
    printf("%c\n", character);

    *ptrInteiro = 20;
    *ptrReal = 3.6;
    *ptrChar = 'e';

    printf("%d\n", numInteiro);
    printf("%.2f\n", numReal);
    printf("%c\n", character);

    return 0 ;
}