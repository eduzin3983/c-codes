#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int escolha;

    printf("========================\n");
    printf("1 - Pizza Marguerita \n");
    printf("2 - Pizza Calabresa\n");
    printf("3 - Pizza Pepperoni\n");
    printf("4 - Pizza Mussarela\n");
    printf("5 - sair \n");
    printf("========================\n");

    scanf("%d", &escolha);

    while (escolha != 5)
    {
        switch (escolha)
        {
        case 1:
            printf("Pizza de Marguerita \n");
            scanf("%d", &escolha);
            break;
            
        case 2:
            printf("Pizza de Calabresa \n");
            scanf("%d", &escolha);
            break;
            
        case 3:
            printf("Pizza de Pepperoni \n");
            scanf("%d", &escolha);
            break;
            
        case 4:
            printf("Pizza de Mussarela \n");
            scanf("%d", &escolha);
            break;
        
        default:
            printf("Opcao indisponivel. \n");
            scanf("%d", &escolha);
            break;
        }
    }
    
    printf("Saindo... \n");

    return 0;
}
