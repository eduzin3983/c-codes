/*Desenvolva um gerador de tabuada, capaz de gerar a
tabuada de qualquer número inteiro entre 1 a 10. O
usuário deve informar de qual numero ele deseja ver a
tabuada.*/

#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);

    for(int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}