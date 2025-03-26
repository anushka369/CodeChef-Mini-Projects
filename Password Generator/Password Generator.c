#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Global strings to be used to randomly generate password components
const char* string_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* string_num = "0123456789";
const char* string_special = "~!@#$%^&*()";

// Function to convert string to lowercase
void toLower(char* input) 
{
    for (int i = 0; input[i]; i++) 
    {
        input[i] = tolower(input[i]); // Convert each character to lowercase
    }
}

// Function to get user input
void userInput(int* length, int* use_special_chars, int* use_numbers) 
{
    printf("Enter the length of the password: ");
    scanf("%d", length);

    char special_char_input[4];
    printf("Include special characters? (yes/no): ");
    scanf("%s", special_char_input);
    toLower(special_char_input);
    *use_special_chars = (strcmp(special_char_input, "yes") == 0);

    char numbers_input[4];
    printf("Include numbers? (yes/no): ");
    scanf("%s", numbers_input);
    toLower(numbers_input);
    *use_numbers = (strcmp(numbers_input, "yes") == 0);
}

// Function to generate the password
char* generate_password(int length, int use_special_chars, int use_numbers) 
{
    if (length < 3) 
    {
        printf("Error: Password length must be at least 3.\n");
        return NULL;
    }

    char* password = (char*)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    srand((unsigned int)time(NULL)); // Seed random number generator

    // Step 1: First character must be an alphabet
    password[0] = string_char[rand() % strlen(string_char)];

    // Step 2: Generate the remaining characters (length - 2)
    for (int i = 1; i < length - 2; ++i) 
    {
        password[i] = string_char[rand() % strlen(string_char)];
    }

    // Step 3: Add a number or alphabet based on 'use_numbers'
    if (use_numbers) 
    {
        password[length - 2] = string_num[rand() % strlen(string_num)];
    } 
    
    else 
    {
        password[length - 2] = string_char[rand() % strlen(string_char)];
    }

    // Step 4: Add a special character or alphabet based on 'use_special_chars'
    if (use_special_chars) 
    {
        password[length - 1] = string_special[rand() % strlen(string_special)];
    } 
    
    else 
    {
        password[length - 1] = string_char[rand() % strlen(string_char)];
    }

    password[length] = '\0'; // Null-terminate the string
    return password;
}

int main() 
{
    int length;
    int use_special_chars;
    int use_numbers;

    // Get user input
    userInput(&length, &use_special_chars, &use_numbers);

    // Generate password
    char* generated_password = generate_password(length, use_special_chars, use_numbers);
  
    if (generated_password != NULL) 
    {
        // Output the generated password
        printf("\nGenerated Password: %s\n", generated_password);
      
        // Free the allocated memory for the password
        free(generated_password);
    }

    return 0;
}
