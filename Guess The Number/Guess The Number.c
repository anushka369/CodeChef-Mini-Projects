#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  // for strcmp() method

int getRandomNumber() 
{
    return rand() % 100 + 1;
}

const char* giveHint(int number, int guess) 
{
    if (guess > (number + 10) || guess < (number - 10)) 
    {
        return "Cold";
    } 
    
    else if (number == guess) 
    {
        return "Right";
    } 
    
    else 
    {
        return "Hot";
    }
}

void runGuess() 
{
    int secretNumber = getRandomNumber();
    int user_guess;
    const char* hint;

    while (1) 
    {
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &user_guess);
        hint = giveHint(secretNumber, user_guess);

        if (strcmp(hint, "Right") == 0) 
        {
            printf("You guessed it Right!\n");
            break;
        } 
        
        else 
        {
            printf("%s\n", hint);
        }
    }
}

int main() 
{
    srand(time(0));  // Initialize random seed
    runGuess();
    return 0;
}
