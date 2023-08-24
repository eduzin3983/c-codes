// This version translated into English may have some bugs, the tested and ideal test version is in Portuguese

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//#include<windows.h> For Windows
#include<unistd.h> //For Linux
#include <time.h>

typedef struct {
    int flightCode;
    char originCity[11];
    char destinationCity[11];
    int numberOfStops;
} Flight;

void addFlight(Flight flights[], int *position) {
    int MAX_FLIGHTS = 50;
    int MAX_CITY = 11;

    if (*position >= MAX_FLIGHTS) {
        printf("Flight limit reached.\n");
        return;
    }

    Flight newFlight;
    system("cls");
    printf("\nFlight Code (4 digits): ");
    scanf("%d", &newFlight.flightCode);
    printf("Origin City: ");
    scanf(" %[^\n]s", newFlight.originCity);
    printf("Destination City: ");
    scanf(" %[^\n]s", newFlight.destinationCity);
    printf("Number of stops: ");
    scanf("%d", &newFlight.numberOfStops);

    flights[*position] = newFlight;
    (*position)++;

    printf("\n-------------------------------------------\n\n");
    printf("Flight Successfully Added");
    sleep(2);
    system("cls");
}

void listFlights(Flight flights[], int position) {
    if (position == 0) {
        system("cls");
        printf("No flights registered.\n");
        sleep(2);
        system("cls");
        return;
    }

    system("cls");
    printf("Available Flights:\n\n");

    printf("-------------------------------------------\n");
    for (int i = 0; i < position; i++) {
        printf("Code: %d\n", flights[i].flightCode);
        printf("Origin City: %s\n", flights[i].originCity);
        printf("Destination City: %s\n", flights[i].destinationCity);
        printf("Number of stops: %d\n", flights[i].numberOfStops);
        printf("-------------------------------------------\n");
    }
    printf("\n");
}

void modifyFlight(Flight flights[], int position) {
    int flightCode;
    system("cls");
    printf("Enter the flight code you want to modify: ");
    scanf("%d", &flightCode);

    int flightIndex = -1;
    int i;
    for (i = 0; i < position; i++) {
        if (flights[i].flightCode == flightCode) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        system("cls");
        printf("Flight not found.\n");
        sleep(2);
        system("cls");
        return;
    }

    printf("\nNew flight information:\n");
    printf("Origin City: ");
    scanf(" %[^\n]s", flights[flightIndex].originCity);
    printf("Destination City: ");
    scanf(" %[^\n]s", flights[flightIndex].destinationCity);
    printf("Number of stops: ");
    scanf("%d", &flights[flightIndex].numberOfStops);

    printf("\nFlight information modified successfully.\n");
    sleep(2);
}

void deleteFlight(Flight flights[], int *position) {
    int MAX_FLIGHTS = 50;

    int flightCode;
    system("cls");
    printf("Enter the flight code you want to delete: ");
    scanf("%d", &flightCode);

    int flightIndex = -1;
    for (int i = 0; i < *position; i++) {
        if (flights[i].flightCode == flightCode) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        printf("\nFlight not found.\n");
        sleep(2);
        system("cls");
        return;
    }

    // Shift the following flights to fill the deleted flight's position
    for (int i = flightIndex; i < *position - 1; i++) {
        flights[i] = flights[i + 1];
    }

    (*position)--;

    system("cls");
    printf("Flight deleted successfully.\n");
    sleep(2);
    system("cls");
}

void flightsFromSameCity(Flight flights[], int position) {
    char originCity[11];
    int count = 0;

    system("cls");
    printf("Enter the origin city: ");
    scanf(" %[^\n]s", originCity);

    system("cls");
    printf("Flights departing from city %s:\n\n", originCity);
    printf("-------------------------------------------");

    for (int i = 0; i < position; i++) {
        if (strcmp(flights[i].originCity, originCity) == 0) {
            printf("\nCode: %d\n", flights[i].flightCode);
            printf("Origin City: %s\n", flights[i].originCity);
            printf("Destination City: %s\n", flights[i].destinationCity);
            printf("Stops: %d\n", flights[i].numberOfStops);
            printf("-------------------------------------------");
            count++;
        }
    }

    if (count == 0) {
        system("cls");
        printf("No flights found departing from city %s.\n", originCity);
        sleep(3);
        system("cls");
    } else {
        printf("\n\nNumber of flights departing from city %s: %d\n", originCity, count);
    }
}

void flightWithFewestStops(Flight flights[], int position) {
    char originCity[11];
    char destinationCity[11];
    int lowestStops = INT_MAX;
    int flightIndex = -1;

    system("cls");
    printf("Enter the origin city: ");
    scanf(" %[^\n]s", originCity);
    printf("Enter the destination city: ");
    scanf(" %[^\n]s", destinationCity);

    for (int i = 0; i < position; i++) {
        if (strcmp(flights[i].originCity, originCity) == 0 && strcmp(flights[i].destinationCity, destinationCity) == 0) {
            if (flights[i].numberOfStops < lowestStops) {
                lowestStops = flights[i].numberOfStops;
                flightIndex = i;
            }
        }
    }

    if (flightIndex != -1) {
        system("cls");
        printf("Flight with the fewest stops from %s to %s:\n", originCity, destinationCity);
        printf("-------------------------------------------\n");
        printf("Code: %d\n", flights[flightIndex].flightCode);
        printf("Origin City: %s\n", flights[flightIndex].originCity);
        printf("Destination City: %s\n", flights[flightIndex].destinationCity);
        printf("Stops: %d\n", flights[flightIndex].numberOfStops);
        printf("-------------------------------------------\n\n");
    } else {
        system("cls");
        printf("No flights found with the combination of cities %s to %s.\n", originCity, destinationCity);
        sleep(2);
        system("cls");
    }
}

void searchFlight(Flight flights[], int position) {
    int flightCode;
    system("cls");
    printf("Enter the flight code you want to search for: ");
    scanf("%d", &flightCode);

    int flightIndex = -1;
    for (int i = 0; i < position; i++) {
        if (flights[i].flightCode == flightCode) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        system("cls");
        printf("Flight not found.\n");
        sleep(2);
        system("cls");
        return;
    }

    system("cls");
    printf("Found Flight:\n");
    printf("-------------------------------------------\n");
    printf("Code: %d\n", flights[flightIndex].flightCode);
    printf("Origin City: %s\n", flights[flightIndex].originCity);
    printf("Destination City: %s\n", flights[flightIndex].destinationCity);
    printf("Number of stops: %d\n", flights[flightIndex].numberOfStops);
    printf("-------------------------------------------\n\n");
}

int main() {
    int MAX_FLIGHTS = 50;
    int position = 0;
    Flight flights[MAX_FLIGHTS];
    int option;

    do {
        printf("\nMain Menu\n\n");
        printf("Choose an option:\n");
        printf("1 - Add Flight\n");
        printf("2 - List Flights\n");
        printf("3 - Modify Flight Information\n");
        printf("4 - Delete Flight\n");
        printf("5 - Flights Departing from Same City\n");
        printf("6 - Flight with Fewest Stops for a Route\n");
        printf("7 - Search\n");
        printf("0 - Exit\n\n");
        printf("Option: ");
        scanf("%d", &option);
        printf("\n\n\n");

        switch (option) {
            case 1:
                addFlight(flights, &position);
                break;
            case 2:
                listFlights(flights, position);
                break;
            case 3:
                modifyFlight(flights, position);
                break;
            case 4:
                deleteFlight(flights, &position);
                break;
            case 5:
                flightsFromSameCity(flights, position);
                break;
            case 6:
                flightWithFewestStops(flights, position);
                break;
            case 7:
                searchFlight(flights, position);
                break;
            case 0:
                printf("Exiting the system...\n");
                break;
            default:
                system("cls");
                printf("Invalid option. Please try again.\n");
                sleep(2);
                system("cls");
                break;
        }

    } while (option != 0);

    return 0;
}
