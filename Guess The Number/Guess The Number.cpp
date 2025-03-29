#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomNumber() 
{
    return rand() % 100 + 1;
}

string giveHint(int number, int guess) 
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
    string hint;

    while (true) 
    {
        cout << "Enter a number between 1 and 100: ";
        cin >> user_guess;
        hint = giveHint(secretNumber, user_guess);
        
        if (hint == "Right") 
        {
            cout << "You guessed it Right!" << endl;
            break;
        } 
        
        else 
        {
            cout << hint << endl;
        }
    }
}

int main() 
{
    srand(time(0));  // Initialize random seed
    runGuess();
    return 0;
}
