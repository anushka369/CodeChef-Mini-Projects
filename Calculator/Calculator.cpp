#include <iostream>
#include <string>
using namespace std;

// Function to display the calculator menu
string calculatorDisplay() 
{
    return "Welcome to Calculator\n\n"
           "Choose one operation:\n"
           "1. Add\n"
           "2. Subtract\n"
           "3. Multiply\n"
           "4. Divide\n"
           "5. Exit\n";
}

// Function to get user input
void userInput(int &a, int &b) 
{
    cout << "Give two numbers on two lines" << endl;
    cout << "Number 1 is: ";
    cin >> a;
    cout << "Number 2 is: ";
    cin >> b;
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
string division(int a, int b) 
{
    if (b == 0) 
    {
        return "Error: Division by zero is not allowed!";
    }
  
    int quotient = a / b;
    int remainder = a % b;
    return ("The quotient is: " + to_string(quotient) + " and the remainder is: " + to_string(remainder));
}

// Function to handle the calculator operations
string calculatorFunction(int userChoice) 
{
    int a, b;
  
    switch (userChoice) 
    {
        case 1:
            cout << "Let's perform addition" << endl;
            userInput(a, b);
            return "The sum is: " + to_string(addition(a, b));
      
        case 2:
            cout << "Let's perform subtraction" << endl;
            userInput(a, b);
            return "The difference is: " + to_string(subtraction(a, b));
      
        case 3:
            cout << "Let's perform multiplication" << endl;
            userInput(a, b);
            return "The product is: " + to_string(multiplication(a, b));
      
        case 4:
            cout << "Let's perform division" << endl;
            userInput(a, b);
            return division(a, b);
      
        case 5:
            return "Exiting the calculator, bye bye!";
      
        default:
            return "Error: Operation does not exist - please provide the correct input";
    }
}

int main() 
{
    while (true)
    {
        cout << calculatorDisplay();
        cout << "Select the operation: ";
        int userChoice;
      
        if (!(cin >> userChoice)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input! Please enter a valid number.\n";
            continue;
        }

        string value = calculatorFunction(userChoice);
        cout << value << endl;

        if (value == "Exiting the calculator, bye bye!") 
        {
            break;
        }
    }
  
    return 0;
}
