/*Escreva um programa que contenha duas variáveis inteiras. 
Leia essas variáveis do teclado. Em seguida, compare seus 
endereços e exiba o conteúdo do maior endereço.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    int *ptr = &num1;
    int *ptr2 = &num2;

    if (ptr > ptr2)
    {
        printf("%d\n", *ptr);
    } else {
        printf("%d\n", *ptr2);
    }
    
    return 0 ;
}
