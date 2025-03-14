#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to calculate the number of bills/coins for the change
void calculateChange(float change, int *bill200, int *bill100, int *bill50, int *bill10, int *bill5, int *coin1, int *coin05) {
    int billCount200 = 0, billCount100 = 0, billCount50 = 0, billCount10 = 0, billCount5 = 0;
    int coinCount1 = 0, coinCount05 = 0;
    
    // Check for each denomination if there is enough change and if bills/coins are available
    while (change >= 200 && *bill200 > 0) {
        change -= 200;
        (*bill200)--;
        billCount200++;
    }
    while (change >= 100 && *bill100 > 0) {
        change -= 100;
        (*bill100)--;
        billCount100++;
    }
    while (change >= 50 && *bill50 > 0) {
        change -= 50;
        (*bill50)--;
        billCount50++;
    }
    while (change >= 10 && *bill10 > 0) {
        change -= 10;
        (*bill10)--;
        billCount10++;
    }
    while (change >= 5 && *bill5 > 0) {
        change -= 5;
        (*bill5)--;
        billCount5++;
    }
    while (change >= 1.0 && *coin1 > 0) {
        change -= 1.0;
        (*coin1)--;
        coinCount1++;
    }
    while (change >= 0.5 && *coin05 > 0) {
        change -= 0.5;
        (*coin05)--;
        coinCount05++;
    }
    
    // Print the quantity of each bill/coin used for the change
    if (billCount200 > 0)
        printf("%d bill(s) of $200\n", billCount200);
    if (billCount100 > 0)
        printf("%d bill(s) of $100\n", billCount100);
    if (billCount50 > 0)
        printf("%d bill(s) of $50\n", billCount50);
    if (billCount10 > 0)
        printf("%d bill(s) of $10\n", billCount10);
    if (billCount5 > 0)
        printf("%d bill(s) of $5\n", billCount5);
    if (coinCount1 > 0)
        printf("%d coin(s) of $1.00\n", coinCount1);
    if (coinCount05 > 0)
        printf("%d coin(s) of $0.50\n", coinCount05);
}

// Function to close the cash register
void closeCashRegister(int customers, float totalSales, float currentCash,
                         int bill200, int bill100, int bill50, int bill10, int bill5,
                         int coin1, int coin05) {

    system("clear");
    printf("========================================\n\n");
    printf("Cash Register Closing!!\n");
    printf("Number of customers served: %d\n", customers);
    printf("Total sales amount: $%.2f\n", totalSales);
    printf("Cash register balance: $%.2f\n", currentCash);

    printf("\nRemaining bills in the register:\n");
    printf("%d bill(s) of $200\n", bill200);
    printf("%d bill(s) of $100\n", bill100);
    printf("%d bill(s) of $50\n", bill50);
    printf("%d bill(s) of $10\n", bill10);
    printf("%d bill(s) of $5\n", bill5);

    printf("\nRemaining coins in the register:\n");
    printf("%d coin(s) of $1.00\n", coin1);
    printf("%d coin(s) of $0.50\n", coin05);

    printf("\n========================================\n");
    sleep(5);
}

// Main function
int main() {
    // Configuration and state variables
    int password = 1234;
    int attempts = 3;
    int enteredPassword;

    float cashRegister = 1280.0; // Initial cash register balance
    int bill200 = 2, bill100 = 4, bill50 = 6, bill10 = 10, bill5 = 10;
    int coin1 = 20, coin05 = 20;

    int saleCount;
    float currentSaleTotal = 0.0;       // Total of the current sale
    float totalSalesAccumulated = 0.0;    // Accumulated total of all sales
    float amountPaid, change;

    int closeRegister = 0;
    int customers = 0;  // Counter for customers served

    // Request password only at the start of the session
    system("clear");
    while (attempts > 0) {
        printf("Enter the password to open the register: ");
        scanf("%d", &enteredPassword);

        if (enteredPassword == password) {
            system("clear");
            printf("\nRegister opened successfully!\n\n");
            break;
        } else {
            attempts--;
            printf("\nIncorrect password! Try again. You have %d attempt(s) remaining!\n\n", attempts);
        }
    }
    if (attempts == 0) {
        system("clear");
        printf("Maximum number of attempts exceeded. Restart the system.\n");
        return 0;
    }

    // Main loop of the cash register
    while (!closeRegister) {
        currentSaleTotal = 0.0;
        saleCount = 0;

        // Input the sale items
        while (1) {
            float itemPrice;
            printf("Enter the price of item (%d) (or zero to finish the sale): ", saleCount + 1);
            scanf("%f", &itemPrice);

            if (itemPrice == 0.0) {
                char option;
                printf("Close the item list? (Y/N): ");
                scanf(" %c", &option);
                if (option == 'Y' || option == 'y') {
                    system("clear");
                    printf("List finalized with %d item(s).\n", saleCount);
                    sleep(1);
                    break;
                } else if (option == 'N' || option == 'n') {
                    continue;
                }
            }
            if (itemPrice == -1) {
                printf("Value disregarded. Enter the correct price for item (%d): ", saleCount + 1);
                scanf("%f", &itemPrice);
                if (itemPrice == -1) {
                    printf("Value still invalid. Item disregarded.\n");
                    continue;
                }
            }
            if (itemPrice < 0.0 && itemPrice != -1) {
                printf("Incorrect value. Item disregarded.\n");
                continue;
            }
            currentSaleTotal += itemPrice;
            saleCount++;
        }

        // Display the total of the current sale
        system("clear");
        printf("====================================\n");
        printf("\nSale Completed!!\n");
        printf("Sale total: $%.2f\n", currentSaleTotal);
        printf("\n====================================\n\n");

        // Process the payment
        printf("Enter the amount paid by the customer: ");
        scanf("%f", &amountPaid);

        // If the amount paid is insufficient, allow canceling or re-entering the amount
        while (amountPaid < currentSaleTotal) {
            char option;
            printf("\nAmount paid is insufficient. Do you want to cancel the purchase? (Y/N): ");
            scanf(" %c", &option);
            if (option == 'Y' || option == 'y') {
                system("clear");
                printf("Purchase canceled. Closing the system...\n");
                sleep(2);
                return 0;
            } else if (option == 'N' || option == 'n') {
                printf("\nEnter the amount again: ");
                scanf("%f", &amountPaid);
            }
        }

        // Update the cash register and accumulated sales
        cashRegister += currentSaleTotal;
        totalSalesAccumulated += currentSaleTotal;
        customers++;

        // If there is change (amount paid is greater than the sale total)
        if (amountPaid > currentSaleTotal) {
            change = amountPaid - currentSaleTotal;
            // Check if there is enough cash available to give change
            if (change > cashRegister) {
                printf("Change unavailable. Operation canceled.\n");
                return 0;
            }
            // Update the cash register: deduct the change given
            cashRegister -= change;
            printf("Change to be returned: $%.2f\n\n", change);
            calculateChange(change, &bill200, &bill100, &bill50, &bill10, &bill5, &coin1, &coin05);
        } else {
            printf("Exact payment. No change required!\n\n");
        }

        // Ask if the register should be closed
        char option;
        printf("\nDo you want to close the register? (Y/N): ");
        scanf(" %c", &option);
        if (option == 'Y' || option == 'y') {
            closeRegister = 1;
            closeCashRegister(customers, totalSalesAccumulated, cashRegister,
                              bill200, bill100, bill50, bill10, bill5,
                              coin1, coin05);
        }
    }

    return 0;
}
