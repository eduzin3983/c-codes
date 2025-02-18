//Include of Libraries
#include <stdio.h>
#include <stdlib.h>
//#include<windows.h> For Windows
#include<unistd.h> //For Linux
#include <time.h>

//Declaration of Functions
int rando();
void tips(int number, int password, int attempt, int choice);

int main()
{
    
//Declaration of Variables
    int Continue=1,
    	password,
        attempt,
        number,
		choice;

//Beginning of the game
    do
    {
        //Choose game mode
        system("cls");
        printf("============================== \n");
        printf("Choose game mode: \n");
        printf("Singleplayer = 1 \n");
        printf("Multiplayer = 2 \n");
        printf("============================== \n");
        scanf("%d", &choice);
        system("cls");
        
        //Singleplayer
        if(choice == 1) 
        {
            
            printf("Drawing a number between 1 and 50...\n");
            password = rando();
            sleep(2);
            
            printf("It started! Try to guess the number! \n\n");
            attempt = 0;

            do
            {
                attempt++;
                printf("Attempt %d: ", attempt);
                scanf("%d", &number);
                tips(number,password,attempt,choice);
            }
            
            while( number != password);

            printf("Enter 0 to exit, or any other number to continue: ");
            scanf("%d", &Continue);
            
        } 
        
        //Multiplayer
        else if (choice == 2) {
            
            printf("Player 1: Choose an integer between 1 to 50\n");
            scanf("%d", &password);
        
            //Test to see if the number is between 1 and 50
            while(password < 1 || password > 50)
            {
            	system("cls");
                printf("Invalid number Try again \n");
                printf("Player 1: Choose an integer between 1 to 50\n");
                scanf("%d", &password);
            }
            
            system("cls");
            printf("Player 2: It started! Try to guess the number! \n\n");
            attempt = 0;
            
            do
            {
                attempt++;
                printf("Attempt %d: ", attempt);
                scanf("%d", &number);
                tips(number,password,attempt,choice);
            }
            while( number != password);

            printf("Enter 0 to exit, or any other number to continue: ");
            scanf("%d", &Continue);
        }
        
    }
        while(Continue);
}

//Functions
int rando()
{
    srand(time(NULL));
    
    return (rand() % 49) + 1;
}

void tips(int number, int password, int attempt, int choice)
{
    if(number > password && choice == 1)
    {
        printf("The drawn number is less than %d\n\n", number);
    }
    else if(number < password && choice == 1) 
    {
        printf("The drawn number is greater than %d\n\n", number);
    } 
    else if(number > password && choice == 2)
	{
		printf("The chosen number is less than %d\n\n", number);
	}
	else if(number < password && choice == 2)
	{
		printf("The chosen number is greater than %d\n\n", number);
	}
    else 
    {
        system("cls");
        printf("Congratulations! You got the number right in %d attempts! the number was %d \n\n", attempt, password);
    }
}
