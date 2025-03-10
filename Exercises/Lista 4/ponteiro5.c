/*Escreva um programa que contenha duas variáveis inteiras. 
Compare seus endereços e exiba o maior endereço.*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int num1 = 100;
    int num2= 34;

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    if (ptr1 > ptr2) {
        printf("O ponteiro 1 (%p) é maior que o ponteiro 2 (%p)\n", ptr1, ptr2);
    } else {
        printf("O ponteiro 2 (%p) é maior que o ponteiro 1 (%p)\n", ptr2, ptr1);
    }
    
    return 0 ;
}