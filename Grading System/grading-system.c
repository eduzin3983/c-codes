#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<windows.h> para windows
#include<unistd.h> //para linux

#define MAX_STUDENTS 50 // maximum number of students

// Structure representing a student
typedef struct {
    char name[50];
    float grade;
} Student;

// Function Declarations

// Function to insert a student into the system
void insertStudent(Student students[], int *numStudents);

// Function to delete a student from the system
void deleteStudent(Student students[], int *numStudents);

// Function to list all students in the system
void listStudents(Student students[], int numStudents);

// Function to search for a student in the system
void searchStudent(Student students[], int numStudents);

int main() {

    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("\n");
        printf("Grade System Created by Eduardo Kairalla \n\n");
        printf("1 - Insert student\n");
        printf("2 - Delete student\n");
        printf("3 - List students\n");
        printf("4 - Search student\n");
        printf("0 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &numStudents);
                break;
            case 2:
                deleteStudent(students, &numStudents);
                break;
            case 3:
                listStudents(students, numStudents);
                break;
            case 4:
                searchStudent(students, numStudents);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Function Definitions

void insertStudent(Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        system("clear");
        printf("Maximum number of students reached.\n");
        return;
    }

    system("clear");
    printf("Enter the student's name: ");
    scanf("%s", students[*numStudents].name);

    printf("Enter the student's grade: ");
    scanf("%f", &students[*numStudents].grade);

    (*numStudents)++;

    system("clear");
    printf("Student inserted successfully...\n");
    sleep(2);
    system("clear");
}

void deleteStudent(Student students[], int *numStudents) {
    int option;

    system("clear");
    printf("1 - Delete all students\n");
    printf("2 - Delete specific student\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    if (option == 1) {

        system("clear");
        *numStudents = 0;
        printf("All students have been deleted.\n");
        sleep(2);
        system("clear");

    } else if (option == 2) {
        char name[50];
        int i, j, found = 0;

        system("clear");
        printf("Enter the name of the student you want to delete: ");
        scanf("%s", name);

        for (i = 0; i < *numStudents; i++) {
            if (strcmp(students[i].name, name) == 0) {
                found = 1;
                for (j = i; j < *numStudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                (*numStudents)--;
                printf("Student deleted successfully.\n");
                sleep(2);
                system("clear");
                break;
            }
        }

        if (!found) {
            system("clear");
            printf("Student not found.\n");
            sleep(2);
            system("clear");
        }
    } else {
        system("clear");
        printf("Invalid option.\n");
        sleep(2);
        system("clear");
    }
}

void listStudents(Student students[], int numStudents) {
    int i;

    system("clear");
    printf("List of students:\n\n");
    for (i = 0; i < numStudents; i++) {
        printf("Name: %s\tGrade: %.1f\tStatus: %s\n", students[i].name, students[i].grade, students[i].grade >= 5 ? "Approved" : "Failed");
    }

    printf("\n ----------------------------------------------------- \n");
}

void searchStudent(Student students[], int numStudents) {
    char name[50];
    int i, found = 0;

    system("clear");
    printf("Enter the name of the student you want to search for: ");
    scanf("%s", name);

    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            found = 1;
            printf("\nName: %s\tGrade: %.1f\tStatus: %s\n", students[i].name, students[i].grade, students[i].grade >= 5 ? "Approved" : "Failed");
            break;
        }
    }

    if (!found) {
        system("clear");
        printf("Student not found.\n");
    }
}
