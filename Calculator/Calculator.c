#include <stdio.h>
#include <stdlib.h>

// Function to display the calculator menu
void calculatorDisplay() 
{
    printf("\nWelcome to Calculator\n\n");
    printf("Choose one operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
}

// Function to get user input
void userInput(int *a, int *b) 
{
    printf("Give two numbers on two lines\n");
    printf("Number 1 is: ");
  
    if (scanf("%d", a) != 1) 
    {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }
  
    printf("Number 2 is: ");
    if (scanf("%d", b) != 1) 
    {
        printf("Invalid input. Please enter a valid number.\n");
        exit(1);
    }
}

// Function to perform addition
int addition(int a, int b) 
{
    return a + b;
}

// Function to perform subtraction
int subtraction(int a, int b) 
{
    return a - b;
}

// Function to perform multiplication
int multiplication(int a, int b) 
{
    return a * b;
}

// Function to perform division
void division(int a, int b) 
{
    if (b == 0) 
    {
        printf("Error: Division by zero is not allowed.\n");
    } 
    
    else 
    {
        printf("Quotient: %d\n", a / b);
        printf("Remainder: %d\n", a % b);
    }
}

// Function to handle the calculator operations
void calculatorFunction(int userChoice) 
{
    int a, b;
    
    switch (userChoice) 
    {
        case 1:
            printf("Let's perform addition\n");
            userInput(&a, &b);
            printf("The sum is: %d\n", addition(a, b));
            break;
        
        case 2:
            printf("Let's perform subtraction\n");
            userInput(&a, &b);
            printf("The difference is: %d\n", subtraction(a, b));
            break;
        
        case 3:
            printf("Let's perform multiplication\n");
            userInput(&a, &b);
            printf("The product is: %d\n", multiplication(a, b));
            break;
        
        case 4:
            printf("Let's perform division\n");
            userInput(&a, &b);
            division(a, b);
            break;
        
        case 5:
            printf("Exiting the calculator, bye bye!\n");
            exit(0);
            
        default:
            printf("Error: Operation does not exist - please provide the correct input.\n");
            break;
    }
}

int main() 
{
    while (1) 
    {
        calculatorDisplay();
        printf("Select the operation: ");
        
        int userChoice;
        if (scanf("%d", &userChoice) != 1) 
        {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            exit(1);
        }
        
        calculatorFunction(userChoice);
    }
  
    return 0;
}
