#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to convert a string to lowercase
void toLower(char* input) 
{
    for (int i = 0; input[i]; i++) 
    {
        input[i] = tolower(input[i]);
    }
}

// Function to extract the local part (before '@') from the email
void extractLocalPart(const char* email, char* localPart) 
{
    int i = 0;
    while (email[i] != '@' && email[i] != '\0') 
    {
        localPart[i] = email[i];
        i++;
    }
  
    localPart[i] = '\0'; // Null-terminate the string
}

// Function to generate random numbers
int getRandomNumber(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

// Function to generate and recommend usernames
void generateUsernames(const char* email) 
{
    char localPart[50];
    extractLocalPart(email, localPart);
    toLower(localPart);
    
    printf("\nRecommended Usernames:\n");
    printf("1. %s\n", localPart);
    printf("2. %s%d\n", localPart, getRandomNumber(100, 999));
    printf("3. %s_%c%c\n", localPart, 'a' + getRandomNumber(0, 25), 'a' + getRandomNumber(0, 25));
    printf("4. %s_%d\n", localPart, getRandomNumber(10, 99));
    printf("5. %c%s%d\n", localPart[0], &localPart[1], getRandomNumber(1000, 9999));
}

int main() 
{
    srand(time(NULL)); // Seed random number generator
    char email[100];
    
    printf("Enter your email ID: ");
    scanf("%s", email);
    
    generateUsernames(email);
    
    return 0;
}
