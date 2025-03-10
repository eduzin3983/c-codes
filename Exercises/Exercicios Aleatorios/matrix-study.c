#include <stdio.h>
#include <stdlib.h>

#define rows 5
#define columns 5

int main() {
    
    int matrix[rows][columns];

    // Reading the matrix
    printf("Enter the elements of the %d x %d matrix:\n", rows, columns);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    system("clear");

    // Printing the original matrix
    printf("\nOriginal Matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Largest value in each row
    printf("\nLargest value in each row:\n");
    for(int i=0; i<rows; i++) {
        int max = matrix[i][0];
        for(int j=1; j<columns; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        printf("Row %d: %d\n", i, max);
    }

    // Sum of values in each column
    printf("\nSum of values in each column:\n");
    for(int j=0; j<columns; j++) {
        int sum = 0;
        for(int i=0; i<rows; i++) {
            sum += matrix[i][j];
        }
        printf("Column %d: %d\n", j, sum);
    }

    // Swap row 0 with row 3
    int temp[columns];
    for(int j=0; j<columns; j++) {
        temp[j] = matrix[0][j];
        matrix[0][j] = matrix[3][j];
        matrix[3][j] = temp[j];
    }
    printf("\nMatrix after swapping row 0 with row 3:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Swap column 1 with column 4
    for(int i=0; i<rows; i++) {
        int temp = matrix[i][1];
        matrix[i][1] = matrix[i][4];
        matrix[i][4] = temp;
    }
    printf("\nMatrix after swapping column 1 with column 4:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
