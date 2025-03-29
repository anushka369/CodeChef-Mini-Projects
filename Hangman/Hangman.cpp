#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to select a random word from a predefined list
string choose_word() 
{
    vector<string> words = {"codechef", "programming", "learning", "practice", "contests", "rating"};
    int random_index = rand() % words.size();
    return words[random_index];
}

// Function to display the current state of the word with guesses
string wordDisplay(const string& word, const string& guesses) 
{
    string display_word;
  
    for (char ch : word) 
    {
        if (guesses.find(ch) != string::npos) 
        {
            display_word += ch;
            display_word += " ";
        }
        
        else 
        {
            display_word += "_ ";
        }
    }
  
    return display_word;
}

// Function to check if the player has lost
bool hasPlayerLost(int turns, const string& word, const string& guesses) 
{
    string display_word = wordDisplay(word, guesses);
    return (turns == 0 && display_word.find('_') != string::npos);
}

// Driver code
int main() 
{
    srand(time(0)); // Seed the random number generator

    cout << "What is your name? ";
    string name;
    getline(cin, name);
    cout << "Hello, " << name << ", time to play hangman!\n\n";

    string word = choose_word();
    int turns = word.length(); // Number of turns equals the length of the word
    string guesses;
    cout << "Start guessing...\n\n";

    while (turns > 0) 
    {
        cout << "You have " << turns << " guesses remaining.\n";
        string display_word = wordDisplay(word, guesses);
        cout << display_word << "\n";

        // Check if the player has won
        if (display_word.find('_') == string::npos) 
        {
            cout << "\nYou won!" << endl;
            break;
        }

        cout << "\nGuess a character: ";
        char guess;
        cin >> guess;

        // Convert guess to lowercase
        guess = tolower(guess);

        // Check if the character has already been guessed
        if (guesses.find(guess) != string::npos) 
        {
            cout << "\nYou have already tried this letter.\n";
            continue;
        }

        guesses += guess;

        // If the guess is incorrect, reduce turns
        if (word.find(guess) == string::npos) 
        {
            cout << "\nWrong guess, try again!\n";
            turns--;
        }

        // Check if the player has lost
        if (hasPlayerLost(turns, word, guesses)) 
        {
            cout << "\nYou Lose\n";
            cout << "The word was '" << word << "'.\n";
            break;
        }
    }

    return 0;
}
