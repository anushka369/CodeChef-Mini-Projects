#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Global variables for scores
int you_score = 0;
int computer_score = 0;

// Function to convert a string to lowercase
void toLower(char *str) 
{
    for (int i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

// Function to get the user's choice (rock, paper, or scissors)
int get_user_choice(char *user_choice, char *output) 
{
    toLower(user_choice);
  
    if (strcmp(user_choice, "rock") == 0 || strcmp(user_choice, "paper") == 0 || strcmp(user_choice, "scissors") == 0) 
    {
        strcpy(output, user_choice);
        return 1;
    }
  
    return 0;
}

// Function to generate the computer's choice (rock, paper, or scissors)
void get_computer_choice(char *output) 
{
    int rand_num = rand() % 3;
  
    if (rand_num == 0) 
    {
        strcpy(output, "rock");
    } 
    
    else if (rand_num == 1) 
    {
        strcpy(output, "paper");
    } 
    
    else 
    {
        strcpy(output, "scissors");
    }
}

// Function to determine the winner of the round
void determine_winner(char *user_choice, char *computer_choice, char *result) 
{
    if (strcmp(user_choice, computer_choice) == 0) 
    {
        strcpy(result, "It's a tie!");
    } 
    
    else if ((strcmp(user_choice, "rock") == 0 && strcmp(computer_choice, "scissors") == 0) ||
               (strcmp(user_choice, "paper") == 0 && strcmp(computer_choice, "rock") == 0) ||
               (strcmp(user_choice, "scissors") == 0 && strcmp(computer_choice, "paper") == 0)) 
    {
        you_score++;
        strcpy(result, "Congratulations! You win this round!");
    } 
    
    else 
    {
        computer_score++;
        strcpy(result, "Computer wins this round!");
    }
}

// Function to compare the scores and return the overall result
void compare_scores(char *result) 
{
    if (you_score < computer_score) 
    {
        strcpy(result, "Computer won the overall match!");
    } 
    
    else if (you_score > computer_score) 
    {
        strcpy(result, "You won the overall match!");
    } 
    
    else 
    {
        strcpy(result, "The match is tied!");
    }
}

// Driver Code
int main() 
{
    srand(time(0));

    printf("Let's play Rock, Paper, Scissors!\n");
    printf("How many rounds do you want to play? ");
  
    int rounds;
    scanf("%d", &rounds);

    int n = 0;
    while (n < rounds) 
    {
        printf("\nRound: %d\n", n + 1);

        while (1) 
        {
            char input[20];
            char user_choice[20];
            char computer_choice[20];
            char result[50];

            printf("Enter your choice (rock, paper, or scissors): ");
            scanf("%s", input);

            if (!get_user_choice(input, user_choice)) 
            {
                printf("Invalid choice! Please enter 'rock', 'paper', or 'scissors'.\n");
            }
            
            else 
            {
                get_computer_choice(computer_choice);
                printf("You chose: %s\n", user_choice);
                printf("Computer chose: %s\n", computer_choice);

                determine_winner(user_choice, computer_choice, result);
                printf("%s\n", result);

                n++;
                break;
            }
        }
    }

    char final_result[50];
    compare_scores(final_result);
    printf("\n%s\n", final_result);

    return 0;
}
