#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float number1, number2, result;
    
    while (1) {  // Infinite loop, will keep running until user decides to exit
        
        printf("========================================= \n");
        printf("Choose the operation you want to perform:\n");
        printf("1 = Addition (+)\n");
        printf("2 = Subtraction (-)\n");
        printf("3 = Multiplication (*)\n");
        printf("4 = Division (/)\n");
        printf("5 = Exit\n");
        printf("========================================= \n\n");
        
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;  // Exit the loop when user chooses to exit
        }
        
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please choose a valid operation.\n");
            continue;  // Skip the rest of the loop and restart
        }
        
        system("clear");
        
        printf("Enter the first number: ");
        scanf("%f", &number1);
        
        printf("Enter the second number: ");
        scanf("%f", &number2);
        
        if (choice == 1) {
            result = number1 + number2;
        } else if (choice == 2) {
            result = number1 - number2;
        } else if (choice == 3) {
            result = number1 * number2;
        } else if (choice == 4) {
            if (number2 == 0) {
                printf("Division by zero is not allowed.\n");
                continue;  // Skip the rest of the loop and restart
            }
            result = number1 / number2;
        }
        
        printf("Your result is: %.3f\n", result);
    }

    return 0;
}
