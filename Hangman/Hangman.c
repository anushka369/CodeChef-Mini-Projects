#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to choose a random word from the list
char* choose_word() 
{
    static char* words[] = {"codechef", "programming", "learning", "practice", "contests", "rating"};
    srand(time(0));  // Seed the random number generator
    int random_index = rand() % 6;  // Get a random index (size of words array)
    return words[random_index];
}

// Function to display the word with guessed characters
char* wordDisplay(const char* word, const char* guesses) 
{
    static char display[100];  // Static to retain the value between function calls
    int word_len = strlen(word);
    int index = 0;

    for (int i = 0; i < word_len; i++) 
    {
        if (strchr(guesses, word[i]) != NULL) 
        {
            display[index++] = word[i];
        } 
        
        else 
        {
            display[index++] = '_';
        }
      
        display[index++] = ' ';  // Add a space after each character
    }
  
    display[index - 1] = '\0';  // Null-terminate the string
    return display;
}

int main() 
{
    char* word = choose_word();
    int turns = strlen(word);  // Set turns based on the length of the word
    char guesses[100] = "";  // To store guessed characters
    char name[100];

    // Ask for player's name
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Remove trailing newline character

    printf("Hello, %s, time to play hangman!\n\n", name);
    printf("Start guessing...\n\n");

    while (turns > 0) 
    {
        char* display = wordDisplay(word, guesses);
        printf("You have %d guesses remaining.\n", turns);
        printf("%s\n", display);

        // Check if the player has won
        if (strchr(display, '_') == NULL) 
        {
            printf("\nYou won!\n");
            break;
        }

        printf("\nGuess a character: ");
        char guess;
        scanf(" %c", &guess);  // Space before %c to consume any leftover whitespace

        // Check if the character has already been guessed
        if (strchr(guesses, guess) != NULL) 
        {
            printf("\nYou have already tried this letter.\n");
            continue;
        }

        // Add the guess to the guesses string
        int len = strlen(guesses);
        guesses[len] = guess;
        guesses[len + 1] = '\0';

        // If the guess is incorrect, reduce turns
        if (strchr(word, guess) == NULL) 
        {
            printf("\nWrong guess, try again!\n");
            turns--;
        }
    }

    if (strchr(wordDisplay(word, guesses), '_') != NULL) 
    {
        printf("\nYou Lose\n");
        printf("The word was '%s'.\n", word);
    }
    
    return 0;
}
