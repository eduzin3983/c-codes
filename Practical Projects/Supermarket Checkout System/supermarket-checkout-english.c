// This version translated into English may have some bugs, the tested and ideal test version is in Portuguese
// This code is not 100% finished, it has some bugs, but it gives a good idea of ​​the functionality of the system.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include<windows.h> For Windows
#include <unistd.h> //For Linux
#include <time.h>

// Function to calculate the quantity of notes
void calculateNoteQuantity(float _change, int *notes200, int *notes100, int *notes50, int *notes10, int *notes5, int *coins1, int *coins05) {
    int notesValues[] = {200, 100, 50, 10, 5};
    int notesQuantity[] = {0, 0, 0, 0, 0};
    float coinsValues[] = {1.0, 0.5};
    int coinsQuantity[] = {0, 0};

    for (int i = 0; i < 5; i++) {
        while ((*notes200 > 0 || *notes100 > 0 || *notes50 > 0 || *notes10 > 0 || *notes5 > 0) && (_change >= notesValues[i])) {
            _change -= notesValues[i];
            switch (i) {
                case 0:
                    (*notes200)--;
                    notesQuantity[0]++;
                    break;
                case 1:
                    (*notes100)--;
                    notesQuantity[1]++;
                    break;
                case 2:
                    (*notes50)--;
                    notesQuantity[2]++;
                    break;
                case 3:
                    (*notes10)--;
                    notesQuantity[3]++;
                    break;
                case 4:
                    (*notes5)--;
                    notesQuantity[4]++;
                    break;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        while ((*coins1 > 0 || *coins05 > 0) && (_change >= coinsValues[i])) {
            _change -= coinsValues[i];
            switch (i) {
                case 0:
                    (*coins1)--;
                    coinsQuantity[0]++;
                    break;
                case 1:
                    (*coins05)--;
                    coinsQuantity[1]++;
                    break;
            }
        }
    }

    // Printing the quantity of each note/coin
    for (int i = 0; i < 5; i++) {
        if (notesQuantity[i] > 0) {
            printf("%d note(s) of R$%d\n", notesQuantity[i], notesValues[i]);
        }
    }

    for (int i = 0; i < 2; i++) {
        if (coinsQuantity[i] > 0) {
            printf("%d coin(s) of R$%.1f\n", coinsQuantity[i], coinsValues[i]);
        }
    }
}

// Function to close the cash register
void closeCashRegisterFunction(int customers, float totalSales, float existingValue,
                               int notes200, int notes100, int notes50, int notes10, int notes5,
                               int coins1, int coins05) {

    system("cls");
    printf("========================================\n\n");
    printf("Cash Register Closure!!\n");
    printf("Number of customers served: %d\n", customers);
    printf("Total sales value: R$%.2f\n", totalSales);
    printf("Existing value in the cash register: R$%.2f\n", existingValue);

    printf("\nQuantity of remaining notes in the cash register:\n");
    printf("%d note(s) of R$200\n", notes200);
    printf("%d note(s) of R$100\n", notes100);
    printf("%d note(s) of R$50\n", notes50);
    printf("%d note(s) of R$10\n", notes10);
    printf("%d note(s) of R$5\n", notes5);

    printf("\nQuantity of remaining coins in the cash register:\n");
    printf("%d coin(s) of R$1.00\n", coins1);
    printf("%d coin(s) of R$0.50\n", coins05);

    printf("\n========================================");
    sleep(5);
}

// Main function
int main() {

    // Variables
    int password = 1234;
    int attempts = 3;
    int enteredPassword;

    float cashInRegister = 1280.0;
    int notes200 = 2, notes100 = 4, notes50 = 6, notes10 = 10, notes5 = 10;
    int coins1 = 20, coins05 = 20;

    int salesNumber = 0;
    float totalCashInRegister = 0.0;
    float totalSalesValue = 0.0;
    float allSalesValue = 0.0;

    int closeRegister = 0;
    int customers = 1;

    // Main loop of the cash register
    while (closeRegister == 0) {

        totalSalesValue = 0;

        system("cls");
        printf("Welcome to the supermarket cash register!\n");

        // Password system
        while (attempts > 0) {
            printf("Enter the password to open the cash register: ");
            scanf("%d", &enteredPassword);

            if (enteredPassword == password) {
                system("cls");
                printf("\nCash register opened successfully!\n\n");
                break;
            } else {
                attempts--;
                printf("\nIncorrect password! Try again. You have %d attempts left!\n\n", attempts);
            }
        }

        if (attempts == 0) {
            system("cls");
            printf("Maximum number of attempts exceeded. Restart the system.\n");
            return 0;
        }

        // Item insertion system
        salesNumber = 0;

        while (1) {
            float itemValue;

            printf("Enter the value of item (%d) (or zero to finish the sale): ", salesNumber + 1);
            scanf("%f", &itemValue);

            if (itemValue == 0.0) {
                char option;
                printf("Close the list of items? (Y/N): ");
                scanf(" %c", &option);

                if (option == 'Y' || option == 'y') {
                    system("cls");
                    printf("List Finished %d Items.\n", salesNumber);
                    printf("Please wait a moment.....\n");
                    sleep(2);
                    break;
                } else if (option == 'N' || option == 'n') {
                    continue;
                }
            }

            if (itemValue == -1) {
                printf("Value disregarded. Enter the correct value of Item (%d): ", salesNumber + 1);
                scanf("%f", &itemValue);

                if (itemValue == -1) {
                    printf("Still an invalid value. Item disregarded.\n");
                    continue;
                }
            }

            if (itemValue < 0.0 && itemValue != -1) {
                printf("Incorrect value. Item disregarded.\n");
                continue;
            }

            totalSalesValue += itemValue;
            salesNumber++;
        }

        allSalesValue = totalSalesValue;

        // Change system
        float paidValue;
        float change;

        system("cls");
        printf("====================================\n");
        printf("\nSale Completed!!\n");
        printf("Total sale value: R$%.2f\n", totalSalesValue);
        printf("\n====================================\n\n");

        printf("Enter the value paid by the customer: ");
        scanf("%f", &paidValue);

        // Calculation of change
        change = paidValue - totalSalesValue;

        // Calculation of total money in the register
        totalCashInRegister = cashInRegister - change;

        if (change > totalCashInRegister) {
            printf("Unavailable Change");
            return 0;
        }

        if (paidValue == totalSalesValue) {
            printf("No change needed!\n\n");

            char option;
            printf("Do you want to close the register? (Y/N): ");
            scanf(" %c", &option);

            if (option == 'Y' || option == 'y') {
                closeRegister = 1;
                closeCashRegisterFunction(customers, allSalesValue, totalCashInRegister, notes200, notes100, notes50, notes10, notes5, coins1, coins05);
            } else if (option == 'N' || option == 'n') {
                customers++;
                continue;
            }
        } else if (paidValue > totalSalesValue) {
            totalCashInRegister -= change;
            printf("Change to be returned: R$%.2f\n\n", change);

            calculateNoteQuantity(change, &notes200, &notes100, &notes50, &notes10, &notes5, &coins1, &coins05);

            char option;
            printf("\nDo you want to close the register? (Y/N): ");
            scanf(" %c", &option);

            if (option == 'Y' || option == 'y') {
                closeRegister = 1;
                closeCashRegisterFunction(customers, allSalesValue, totalCashInRegister, notes200, notes100, notes50, notes10, notes5, coins1, coins05);
            } else if (option == 'N' || option == 'n') {
                customers++;
                continue;
            }

            if (change > totalCashInRegister) {
                printf("Unavailable Change");
                return 0;
            }
        }

        while (paidValue < totalSalesValue) {
            char option;
            printf("\nInsufficient paid value. Do you want to cancel the purchase? (Y/N): ");
            scanf(" %c", &option);

            if (option == 'Y' || option == 'y') {
                system("cls");
                printf("Purchase canceled. Turning off the system....");
                sleep(2);
                return 0;
            } else if (option == 'N' || option == 'n') {
                printf("\nEnter the value again: ");
                scanf("%f", &paidValue);

                if (paidValue < totalSalesValue) {
                    system("cls");
                    printf("Purchase canceled. Turning off the system....");
                    sleep(2);
                    return 0;
                } else {
                    if (paidValue == totalSalesValue) {
                        printf("No change needed!\n\n");

                        char option;
                        printf("Do you want to close the register? (Y/N): ");
                        scanf(" %c", &option);

                        if (option == 'Y' || option == 'y') {
                            closeRegister = 1;
                            closeCashRegisterFunction(customers, allSalesValue, totalCashInRegister, notes200, notes100, notes50, notes10, notes5, coins1, coins05);
                        } else if (option == 'N' || option == 'n') {
                            customers++;
                            continue;
                        }
                    } else if (paidValue > totalSalesValue) {
                        totalCashInRegister -= change;
                        printf("Change to be returned: R$%.2f\n\n", change);

                        calculateNoteQuantity(change, &notes200, &notes100, &notes50, &notes10, &notes5, &coins1, &coins05);

                        char option;
                        printf("\nDo you want to close the register? (Y/N): ");
                        scanf(" %c", &option);

                        if (option == 'Y' || option == 'y') {
                            closeRegister = 1;
                            closeCashRegisterFunction(customers, allSalesValue, totalCashInRegister, notes200, notes100, notes50, notes10, notes5, coins1, coins05);
                        } else if (option == 'N' || option == 'n') {
                            customers++;
                            continue;
                        }

                        if (change > totalCashInRegister) {
                            printf("Unavailable Change");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
